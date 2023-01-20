#ifndef LIB_MAIKU_HTTP
#define LIB_MAIKU_HTTP
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

class MaikuHTTPServer {
public:
    MaikuHTTPServer(int port);
    ~MaikuHTTPServer();

private:
    void Listen();
    void ProcessRequest(const std::string message);
    int port;
    sockaddr_in servAddr;
    int serverSd;
};


#endif /* LIB_MAIKU_HTTP */
