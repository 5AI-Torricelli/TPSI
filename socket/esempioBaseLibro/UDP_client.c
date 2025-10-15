#include <stdio.h>
#include <string.h>
#include <time.h>

#include "UDP.h"

#define PORT_NUMBER 	12345
#define REQUEST		"DATETIME"
#define TIMEOUT		1000 // 1000ms = 1s

int main(int argc , char*argv[]){
  uint8_t request[] = REQUEST;
  uint32_t ip_address;
  uint16_t port_number;
  uint32_t timestamp;
  int n;

  if (argc < 2)
    {
      printf("Uso %s indirizzo-IP-server!\r\n", argv[0]);
      return 0;
    }
    
  if (UDP_init(0) < 0)
    {
      printf("Errore inizializzazione socket!\r\n");
      return 0;
    }
    
  ip_address = IP_to_bin(argv[1]);
  port_number = PORT_NUMBER;
  
  UDP_send(ip_address, port_number, request, strlen((char*)request));
    
  if (UDP_wait(TIMEOUT) > 0){
    if ((n = UDP_receive(&ip_address, &port_number, (uint8_t*)&timestamp, sizeof(uint32_t))) == sizeof(uint32_t)){
      printf("Timestamp: %u\r\n", timestamp);
      UDP_close();
      return 1;
    }
  }
  printf("Nessuna risposta ricevuta!\r\n");
  UDP_close();
  return 0;
}

