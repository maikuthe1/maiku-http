#include "headers/util.hpp"
#include "headers/maiku-http-server.hpp"

using namespace MaikuHTTPLib;

Server::Server(int port) : port(port) {

}

void Server::Start()
{
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);

    serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
        std::cerr << "Error establishing the server socket" << std::endl;
        exit(0);
    }
    int bindStatus = bind(serverSd, (struct sockaddr*) &servAddr,
        sizeof(servAddr));
    if(bindStatus < 0)
    {
        std::cerr << "Error binding socket to local address" << std::endl;
        exit(0);
    }

    this->Listen();
}

void Server::Stop()
{
    close(serverSd);
}

void handleConnection(Server* server, int newSd, sockaddr_in newSockAddr)
{
    char msg[1500];
    while(1)
    {
        memset(&msg, 0, sizeof(msg));
        int bytesIn = recv(newSd, (char*)&msg, sizeof(msg), 0);
        if(bytesIn == 0)
        {
            break;
        }
        try
        {
            Request *request = new Request(std::string(msg));
            std::cout << "Method: " << MaikuHTTPLib::to_string(request->method) << std::endl;
            std::cout << "Resource: " << request->resource << std::endl;
            std::cout << "Version: " << MaikuHTTPLib::to_string(request->version) << std::endl;
            for(Header header : request->headers)
            {
                std::cout << "Key: " << header.Key() << std::endl << "Value: " << header.Value() << std::endl << std::endl;
            }
            std::cout << "Body: " << request->body << std::endl << std::endl;

            if(request->method == Method::GET)
            {

                std::ifstream notFound("404.html");

                std::stringstream buffer;
                buffer << notFound.rdbuf();

                std::string fourohfour = buffer.str();

                notFound.close();

                Response response(MaikuHTTPLib::Version::HTTP_1_1, 404, "NotFound");
                response.headers.push_back(MaikuHTTPLib::Header("Content-Type", "text/html"));
                response.headers.push_back(MaikuHTTPLib::Header("Connection", "close"));
                response.body = fourohfour;

                std::string fullResponse = response.Serialize();

                send(newSd, fullResponse.c_str(), strlen(fullResponse.c_str()), 0);

                break;
            }
        }
        catch (std::exception)
        {
            break;
        }

    }

    close(newSd);
}

void Server::Listen()
{
    char msg[1500];
    listen(serverSd, 5);
    while(1)
    {
        sockaddr_in newSockAddr;
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
        if(newSd < 0)
        {
            std::cerr << "Error accepting request from client!" << std::endl;
            close(newSd);
            continue;
        }

        // Create a new thread and pass newSd, newSockAddr and this as arguments
        std::thread t(handleConnection, this, newSd, newSockAddr);
        t.detach();  // Detach the thread so it runs in the background
    }
    this->Stop();
}


Server::~Server()
{
    Stop();
}
