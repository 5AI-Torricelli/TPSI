import java.net.*;
import java.io.*;

/**
 * Classe che rappresenta un client UDP.
 * Gestisce la comunicazione tramite socket UDP.
 */
public class UDPClient {
  /**
   * Socket UDP utilizzato per la comunicazione.
   */
  private DatagramSocket socket;

  /**
   * Costruttore della classe che crea un socket UDP.
   * 
   * @throws SocketException se non riesce a creare il socket.
   */
  public UDPClient() throws SocketException {
    // Creo un socket UDP e lo imposto con un timeout di 1000 millisecond.
    socket = new DatagramSocket();
    socket.setSoTimeout(1000);
  }

  /**
   * Chiude il socket UDP.
   */
  public void close_socket() {
    // Chiudo il socket UDP.
    socket.close();
  }

  /**
   * Invia una richiesta al server e restituisce la risposta.
   * 
   * @param request la richiesta da inviare.
   * @param host    l'indirizzo IP del server.
   * @param port    la porta UDP del server.
   * @return la risposta del server.
   * @throws UnknownHostException   se l'indirizzo IP non esiste.
   * @throws IOException            se si verifica un errore di I/O.
   * @throws SocketTimeoutException se non riesce a ricevere la risposta
   *                                entro il timeout specificato.
   */
  public String sendAndReceive(String request, String host, int port)
      throws UnknownHostException, IOException, SocketTimeoutException {
    // Converto la richiesta in un array di byte.
    byte[] buffer = request.getBytes("UTF-8");

    // Creo un DatagramPacket con l'array di byte e l'indirizzo IP del server.
    DatagramPacket datagram = new DatagramPacket(buffer, buffer.length, InetAddress.getByName(host), port);

    // Invio il DatagramPacket attraverso il socket UDP.
    socket.send(datagram);

    // Creo un nuovo DatagramPacket per ricevere la risposta.
    datagram = new DatagramPacket(buffer, buffer.length);

    // Ricevo la risposta tramite il socket UDP.
    socket.receive(datagram);

    // Verifico se la risposta proviene dal server giusto.
    if (datagram.getAddress().equals(InetAddress.getByName(host)) && datagram.getPort() == port) {
      // Converto la risposta in una stringa.
      String answer = new String(datagram.getData(), 0, datagram.getLength(), "ISO-8859-1");

      // Restituisco la risposta.
      return answer;
    } else {
      // Lancio un'eccezione se la risposta non proviene dal server giusto.
      throw new SocketTimeoutException();
    }
  }
}
