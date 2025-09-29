#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <string.h>

int sendData(int socketId){
    struct sockaddr_in addr;
    char data[] = "ciao";
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8081);
    int sendtoResult = sendto(socketId, (void * ) data, sizeof(data), 0, (struct sockaddr*) &addr, sizeof(addr));
    if(sendtoResult < 0){
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int socketId = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET; // DEVE COMBACIARE CON PARAMETRO DOMAIN NEL SOCKET
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8082); // CONVERTE IN BIG ENDIAN (standard network)
    int bindResult = bind(socketId, (struct sockaddr*) &addr, sizeof(addr));
    if(bindResult < 0){
        close(socketId);
        return -1;
    }
    sendData(socketId);
    return 0;
}
