# UDP Client in Java

## Cos'è questo progetto?

Questo è un **client UDP** scritto in Java che permette di inviare messaggi a un server e ricevere risposte.

### Cosa fa?

Il client:
1. Crea un socket UDP per comunicare in rete
2. Invia un messaggio al server specificando host e porta
3. Aspetta la risposta dal server (con timeout di 1 secondo)
4. Restituisce il messaggio ricevuto

### Concetti chiave

- **UDP (User Datagram Protocol)**: protocollo di comunicazione veloce ma non garantito (i pacchetti potrebbero perdersi)
- **DatagramSocket**: classe Java per creare socket UDP
- **DatagramPacket**: rappresenta un pacchetto di dati da inviare/ricevere
- **Timeout**: tempo massimo di attesa per una risposta (qui impostato a 1000ms)

## Come usarlo

1. Avvia prima il server UDP
2. Esegui il client specificando:
   - Il messaggio da inviare
   - L'host del server (es. "localhost")
   - La porta del server (es. 9876)

## Struttura del progetto

- `src/UDPClient.java`: classe che gestisce la comunicazione UDP
- `src/App.java`: programma principale che usa il client
- `bin/`: cartella dove vengono compilati i file .class
