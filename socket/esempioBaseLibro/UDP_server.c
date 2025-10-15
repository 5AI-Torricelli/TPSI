#include <stdio.h>
#include <time.h>
#include <string.h>

#include "UDP.h"

#define PORT_NUMBER 	12345
#define REQUEST		"DATETIME"
#define TIMEOUT		1000 // 1000ms = 1s

int main(void){
	uint8_t buffer[1024];
	uint32_t ip_address;
	uint16_t port_number;
	uint32_t timestamp;
	int n;

	if(UDP_init(PORT_NUMBER) < 0){
		printf("Errore inizializzazione socket!\r\n");
		return 0;
	}

	while (1){
		if ((n = UDP_receive(&ip_address, &port_number, buffer, sizeof(buffer))) > 0){
			buffer[n]='\0';
			if (strncmp((char*)buffer, REQUEST, strlen(REQUEST)) == 0){
				timestamp = time(NULL);	     
				UDP_send(ip_address, port_number, (uint8_t*)&timestamp, sizeof(uint32_t));
			}
		}	
	}
	UDP_close();
	return 1;
}

