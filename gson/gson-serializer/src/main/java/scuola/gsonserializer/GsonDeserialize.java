package scuola.gsonserializer;

import com.google.gson.*;
import java.io.IOException;
import java.nio.file.*;

public class GsonDeserialize {
    private static String readStringFromFile(String filepath) throws IOException {
        byte[] content = Files.readAllBytes(Paths.get(filepath));
        return new String(content);
    }

    public static void main(String args[]) throws IOException {
        // Gson gson = new Gson();
        Gson gson = new GsonBuilder().registerTypeAdapter(Libro.class, new InstanziaLibro()).create();
        String json = readStringFromFile("libro.json");
        Libro libro = gson.fromJson(json, Libro.class);
        System.out.println(libro);
    }
}
