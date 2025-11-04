import java.io.*;

public class App {
  public static void main(String[] args) {
    int c;
    try {
      UDPecho echoserver = new UDPecho(7);
      echoserver.start();
      c = System.in.read();
      echoserver.interrupt();
      echoserver.join();
    } catch (IOException e) {
      System.err.println("Errore: " + e.getMessage());
    } catch (InterruptedException e) {
      System.err.println("Fine!");
    }
  }
}
