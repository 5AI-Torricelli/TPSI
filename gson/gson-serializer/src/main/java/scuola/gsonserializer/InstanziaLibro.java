package scuola.gsonserializer;

import com.google.gson.*;
import java.lang.reflect.Type;

public class InstanziaLibro implements InstanceCreator<Libro> {
    public Libro createInstance(Type type) {
        Libro libro = new Libro("", "", 0.0F);
        return libro;
    }
}
