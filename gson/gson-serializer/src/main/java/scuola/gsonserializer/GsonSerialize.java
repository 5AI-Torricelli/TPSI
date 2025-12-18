package scuola.gsonserializer;

import com.google.gson.*;
import java.io.IOException;
import java.nio.file.*;

public class GsonSerialize {
    private static void writeStringToFile(String filepath, String content) throws IOException {
        Files.write(Paths.get(filepath), content.getBytes());
    }

    public static void main(String args[]) throws IOException {
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        Libro libro = new Libro("Il signore degli anelli", "J. R. R. Tolkien", 30.0F);
        String json = gson.toJson(libro);
        writeStringToFile("libro.json", json);
    }
}
