#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
#include <thread>
#include "maiku-http-header.hpp"
#include "maiku-http-request.hpp"
#include "maiku-http-response.hpp"

namespace MaikuHTTPLib{
    class Server {
    public:
        Server(int port);
        void Start();
        void Stop();
        ~Server();
        Request* ProcessRequest(const std::string message, int socketDescriptor);

    private:
        void Listen();
        int port;
        sockaddr_in servAddr;
        int serverSd;

    };
}
