#include "headers/util.hpp"
#include "headers/maiku-http-lib.hpp"


MaikuHTTPServer::MaikuHTTPServer(int port) : port(port) {
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

MaikuHTTPServer::~MaikuHTTPServer() {

}

void MaikuHTTPServer::Listen() {
    while(true)
    {
        char msg[1500];
        listen(serverSd, 5);
        sockaddr_in newSockAddr;
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
        if(newSd < 0)
        {
            std::cerr << "Error accepting request from client!" << std::endl;
        }
        int bytesRead, bytesWritten = 0;
        while(1)
        {
            memset(&msg, 0, sizeof(msg));
            int bytesIn = recv(newSd, (char*)&msg, sizeof(msg), 0);
            if(bytesIn == 0)
            {
                break;
            }

            this->ProcessRequest(std::string(msg));

            std::string responseHeader = std::string("HTTP/1.1 200 OK\r\nServer: Maiku-HTTP/0.1 (Unix)\r\nContent-Type: text/html\r\nConnection: keep-alive\r\n\r\n");
            std::string response = std::string("<html><body><h1>Hello, World!</h1></body></html>");

            bytesWritten += send(newSd, responseHeader.c_str(), strlen(responseHeader.c_str()), 0);
            bytesWritten += send(newSd, response.c_str(), strlen(response.c_str()), 0);
            close(newSd);
            break;
        }
    }
    close(serverSd);
}


void MaikuHTTPServer::ProcessRequest(const std::string message)
{
    std::cout << message << std::endl;
    // Map to store header key/vals
    std::map<std::string, std::string> request_data;
    // Split the header by \r\n
    std::vector<std::string> lines = split(message, "\r\n");
    // For each line, split into key/val and add to request_data
    for(const std::string &line : lines)
    {
        if(line.size() == 0)
            continue;
        std::vector<std::string> segments = split(line, " ");
        if(segments.size() == 0)
            continue;
        const std::string key = segments[0].substr(0, segments[0].size() - 1);
        segments.erase(segments.begin());
        const std::string value = concat(segments, " ");

        request_data[str_tolower(key)] = value;
    }

    std::cout << "User agent: " << request_data["user-agent"] << std::endl;
}
