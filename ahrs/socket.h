#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <string>
#include <errno.h>
#include <sys/signal.h.h>

class Socket
{
public:
    Socket();
    void send();
    void setup();
    bool has_client();
private:
    const char * socket_path = "/tmp/socket";
    const char * phrase = "Stuff this in your pipe and smoke it\n";
    struct sockaddr_un addr;
    int sockfd,client_socket,client_return;
};