import java.io.*;
import java.net.*;

public class UDPClient {
  private DatagramSocket socket;

  public UDPClient() throws SocketException {
    socket = new DatagramSocket();
    socket.setSoTimeout(1000);
  }

  public void close_socket() {
    socket.close();
  }

  public String sendAndReceive(String request, String host, int port)
      throws UnknownHostException, IOException, SocketTimeoutException {
    byte[] buffer;
    DatagramPacket datagram;
    String answer;

    InetAddress address = InetAddress.getByName(host);

    if (socket.isClosed()) {
      throw new IOException();
    }

    buffer = request.getBytes("UTF-8");

    datagram = new DatagramPacket(buffer, buffer.length, address, port);
    socket.send(datagram);

    socket.receive(datagram);

    if (datagram.getAddress().equals(address) && datagram.getPort() == port) {
      answer = new String(datagram.getData(), 0, datagram.getLength(), "ISO-8859-1");
    } else {
      throw new SocketTimeoutException();
    }

    return answer;
  }
}
