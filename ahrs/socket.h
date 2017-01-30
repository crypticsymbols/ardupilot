#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

class Socket
{
public:
    Socket();
    void send();
    void setup();
    bool has_client();
private:
    std::string socket_path;
    std::string socket_path;
    struct sockaddr_un addr;
    int sockfd,client_socket,client_return;
};