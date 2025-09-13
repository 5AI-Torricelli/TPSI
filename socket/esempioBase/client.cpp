#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
  // Crea un socket TCP (AF_INET = IPv4, SOCK_STREAM = TCP).
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in addr{};
  addr.sin_family = AF_INET;                       // Indichiamo che useremo IPv4.
  addr.sin_port = htons(8080);                     // Porta 8080, convertita in network byte order (big endian).
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); // Converte la stringa "127.0.0.1" (localhost) in un indirizzo IP binario.

  connect(sock, (sockaddr *)&addr, sizeof(addr)); // Tenta di connettersi al server specificato (127.0.0.1:8080).

  const char *msg = "Hello World dal client!";
  send(sock, msg, strlen(msg), 0); // Invia una stringa al server tramite il socket.

  char buffer[1024] = {0};
  recv(sock, buffer, sizeof(buffer), 0); // Riceve la risposta dal server.
  cout << "Risposta dal server: " << buffer << endl;

  close(sock);
}
