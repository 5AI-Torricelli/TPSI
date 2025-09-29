#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <string.h>
#define BUFFER_SIZE 1024
int receiveFrom(int socketId){
	char buffer[BUFFER_SIZE];
	struct sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	while (1) {
        ssize_t bytesReceived = recvfrom(
            socketId,
            buffer,
            BUFFER_SIZE - 1,
            0,
            (struct sockaddr*)&clientAddr,
            &clientAddrLen
        );

        if (bytesReceived < 0) {
            perror("recvfrom");
            continue;
        }

        buffer[bytesReceived] = '\0'; 

        printf(
            "Ricevuto %zd bytes da %s:%d: %s\n",
            bytesReceived,
            inet_ntoa(clientAddr.sin_addr),
            ntohs(clientAddr.sin_port),
            buffer
        );
    }
}
int main(int argc, char *argv[]) {
    int socketId = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET; // DEVE COMBACIARE CON PARAMETRO DOMAIN NEL SOCKET
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8081); // CONVERTE IN BIG ENDIAN (standard network)
    int bindResult = bind(socketId, (struct sockaddr*) &addr, sizeof(addr));
    if(bindResult < 0){
		perror("bind failed");
        close(socketId);
        return -1;
    }
    printf("Server in ascolto sulla porta %i...\n", 8081);
    receiveFrom(socketId);
    return -1;
}
