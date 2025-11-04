import java.io.*;
import java.net.*;

public class App {
    public static void main(String[] args) throws Exception {
        String IP_address;
        int UDP_port;
        String request, answer;
        UDPClient client;

        if (args.length != 3) {
            IP_address = "127.0.0.1";
            UDP_port = 7;
            request = "Hello world!";
        } else {
            IP_address = args[0];
            UDP_port = 7;
            request = "Hello world!";
        }

        try {
            client = new UDPClient();
            answer = client.sendAndReceive(request, IP_address, UDP_port);
            System.out.println("Ricevuto in risposta: " + answer);
            client.close_socket();
        } catch (SocketException e) {
            System.err.println("Errore creazione socket!");
        } catch (UnknownHostException e) {
            System.err.println("Indirizzo IP non trovato!");
        } catch (SocketTimeoutException e) {
            System.err.println("Nessuna risposta dal server!");
        } catch (IOException e) {
            System.err.println("Errore generico di comunicazione");
        }
    }
}
