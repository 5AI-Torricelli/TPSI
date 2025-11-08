import java.net.*;
import java.io.*;

public class UDPecho extends Thread {
  private DatagramSocket socket;

  // Costruttore per creare un socket UDP per ricevere
  // pacchetti UDP sulla porta specificata
  public UDPecho(int port) throws SocketException {
    socket = new DatagramSocket(port);
    // Imposta il timeout per la ricezione di un pacchetto
    socket.setSoTimeout(1000);
  }

  public void run() {
    DatagramPacket answer;

    // Buffer per contenere i dati ricevuti
    byte[] buffer = new byte[1024];

    // Creazione di un DatagramPacket per contenere i dati ricevuti
    DatagramPacket request = new DatagramPacket(buffer, buffer.length);

    // Ciclo per ricevere i pacchetti UDP
    while (!Thread.interrupted()) {
      try {
        // Ricezione di un pacchetto UDP
        socket.receive(request);
        // Creazione di un DatagramPacket per contenere la risposta
        answer = new DatagramPacket(request.getData(), request.getLength(),
            request.getAddress(), request.getPort());
        // Invio della risposta
        socket.send(answer);
      } catch (IOException e) {
      }
    }
    // Chiusura del socket
    socket.close();
  }
}
