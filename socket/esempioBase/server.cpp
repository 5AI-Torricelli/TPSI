#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
  // Crea un socket TCP (AF_INET = IPv4, SOCK_STREAM = TCP).
  // Restituisce un file descriptor che rappresenta il socket.
  // file descriptor = un numero intero che linux usa per riferirsi a una risorsa aperta.
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in addr{};
  addr.sin_family = AF_INET;         // Indichiamo che useremo IPv4.
  addr.sin_addr.s_addr = INADDR_ANY; // Accetta connessioni da qualsiasi indirizzo locale.
  addr.sin_port = htons(8080);       // Porta 8080, convertita in network byte order (big endian).

  // "Collega" il socket a indirizzo e porta scelti.
  // Da questo momento il socket è legato alla porta 8080.
  bind(server_fd, (sockaddr *)&addr, sizeof(addr));

  // Mette il socket in ascolto, pronto ad accettare connessioni.
  // "1" significa coda massima di connessioni in attesa.
  listen(server_fd, 1);

  // Accetta la prima connessione in arrivo.
  // Restituisce un nuovo socket (client_fd) dedicato a quel client.
  int client_fd = accept(server_fd, nullptr, nullptr);

  // Riceve dati inviati dal client attraverso il socket.
  // Scrive il messaggio nel buffer.
  char buffer[1024] = {0};
  recv(client_fd, buffer, sizeof(buffer), 0);
  cout << "Messaggio ricevuto: " << buffer << endl;

  const char *reply = "Hello World dal server!";
  send(client_fd, reply, strlen(reply), 0);

  close(client_fd);
  close(server_fd);
}