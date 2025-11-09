import java.io.*;
import javax.json.*;

public class JSONwriter {
    public static final String JSON_FILE = "libri.json";

    public static void main(String[] args) throws IOException {
        Libro[] libri = new Libro[2];

        libri[0] = new Libro();
        libri[0].setGenere("fantasy");
        libri[0].setTitolo("Lo Hobbit");
        libri[0].setAutore("J. R. R. Tolkien");
        libri[0].setPrezzo(9.99f);
        libri[1] = new Libro();
        libri[1].setGenere("fantasy");
        libri[1].setTitolo("Il signore degli anelli");
        libri[1].setAutore("J. R. R. Tolkien");
        libri[1].setPrezzo(30.00f);

        JsonObjectBuilder rootObject = Json.createObjectBuilder();
        JsonObjectBuilder booksObject = Json.createObjectBuilder();
        JsonArrayBuilder bookArray = Json.createArrayBuilder();

        for (Libro libro : libri) {
            JsonObjectBuilder bookObject = Json.createObjectBuilder();
            bookObject.add("genere", libro.getGenere());
            bookObject.add("titolo", libro.getTitolo());
            bookObject.add("autore", libro.getAutore());
            bookObject.add("prezzo", libro.getPrezzo());
            bookArray.add(bookObject.build());
        }

        booksObject.add("libro", bookArray.build());
        rootObject.add("libri", booksObject.build());

        OutputStream output = new FileOutputStream(JSON_FILE);
        JsonWriter jsonWriter = Json.createWriter(output);
        jsonWriter.writeObject(rootObject.build());

        jsonWriter.close();
        output.close();
    }
}
