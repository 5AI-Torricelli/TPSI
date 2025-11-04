import java.net.*;
import java.io.*;

public class UDPecho extends Thread {
  private DatagramSocket socket;

  public UDPecho(int port) throws SocketException {
    socket = new DatagramSocket(port);
    socket.setSoTimeout(1000);
  }

  public void run() {
    DatagramPacket answer;

    byte[] buffer = new byte[1024];

    DatagramPacket request = new DatagramPacket(buffer, buffer.length);
    while (!Thread.interrupted()) {
      try {
        socket.receive(request);
        answer = new DatagramPacket(request.getData(), request.getLength(),
            request.getAddress(), request.getPort());
        // Se vogliamo stampare quanto ricevuto da un client
        // System.out.println("Ricevuto: " + new String(answer.getData(), 0,
        // answer.getLength(), "ISO-8859-1"));
        socket.send(answer);
      } catch (IOException e) {
      }
    }
    socket.close();
  }
}
