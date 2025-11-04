# UDP Echo Server in Java

## Cos'è questo progetto?

Questo è un **server UDP Echo** scritto in Java che riceve messaggi dai client e li rimanda indietro (come un'eco).

### Cosa fa?

Il server:
1. Si mette in ascolto su una porta specifica
2. Riceve messaggi dai client
3. Rimanda indietro lo stesso messaggio al mittente
4. Continua ad ascoltare finché non viene interrotto

### Concetti chiave

- **UDP (User Datagram Protocol)**: protocollo di comunicazione veloce ma non garantito
- **Echo Server**: server che rimanda indietro ciò che riceve (utile per test di rete)
- **Thread**: il server gira in un thread separato per non bloccare il programma principale
- **DatagramSocket**: classe Java per creare socket UDP
- **DatagramPacket**: rappresenta un pacchetto di dati ricevuto/inviato

## Come funziona

1. Il server si avvia su una porta (es. 9876)
2. Rimane in attesa di pacchetti UDP
3. Quando riceve un pacchetto:
   - Legge il contenuto
   - Prende l'indirizzo e la porta del mittente
   - Rimanda indietro lo stesso messaggio
4. Il ciclo continua finché il thread non viene interrotto

## Struttura del progetto

- `src/UDPecho.java`: classe del server echo che estende Thread
- `src/App.java`: programma principale che avvia il server
- `bin/`: cartella dove vengono compilati i file .class
