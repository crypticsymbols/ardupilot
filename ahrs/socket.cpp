#include "socket.h"

Socket::Socket() {
  // Ignore sigpipe so client death does not kill server
  signal(SIGPIPE, SIG_IGN);
  // socket_path = 
  
}

void Socket::send() {
  if (has_client()){
    client_return = write(client_socket, phrase, strlen(phrase)+1);
    if (client_return == -1) {
      printf("Client lost\n");
      close(client_socket);
    }
    else if (client_return == 0) {
      printf("EOF\n");
      close(client_socket);
    }
  }
}

bool Socket::has_client() {
if ( (client_socket = accept(sockfd, NULL, NULL)) == -1) {
    printf("accept error");
    return false;
  } else {
    return true;
  }
}

void Socket::setup() {
  // Make socket
  if ( (sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    printf("socket error");
    exit(-1);
  }
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  if (*socket_path == '\0') {
    *addr.sun_path = '\0';
    strncpy(addr.sun_path+1, socket_path+1, sizeof(addr.sun_path)-2);
  } else {
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    unlink(socket_path);
  }
  // Bind to the new socket
  if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    printf("bind error");
    exit(-1);
  }
  // Listen for clients
  if (listen(sockfd, 5) == -1) {
    printf("listen error");
    exit(-1);
  }
}

// int main(int argc, char *argv[]) {
  
//   while (1) {

//     // while ( (  ) > 0) {
//     //   sleep(1);
//     //   printf("derp...\n");
//     // }

    
//     else {
//       printf("Unknown client error %d\n", client_return);
//       close(client_socket);
//     }
//   }
//   return 0;
// }
