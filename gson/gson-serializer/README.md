<h1 align="center">Serializzazione e Deserializzazione JSON con Gson</h1>

Questo progetto dimostra come serializzare e deserializzare oggetti Java in formato JSON utilizzando la libreria Gson di Google. Nello specifico, il programma gestisce oggetti di tipo `Libro`, permettendo di trasformarli in stringhe JSON e viceversa.

## Componenti Principali

- `Libro.java`: Definisce la classe modello per un libro, con attributi come titolo, autore, ecc.
- `InstanziaLibro.java`: Contiene la logica per creare istanze di oggetti `Libro`.
- `GsonSerialize.java`: Mostra come serializzare un oggetto `Libro` in una stringa JSON.
- `GsonDeserialize.java`: Mostra come deserializzare una stringa JSON in un oggetto `Libro`.

## Dipendenze

Questo progetto utilizza la libreria `Gson` per la serializzazione e deserializzazione JSON. Se stai utilizzando Maven, puoi aggiungere la seguente dipendenza al tuo file `pom.xml`:

```xml
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.10.1</version>
</dependency>
```

Dopo aver aggiunto la dipendenza, Maven scaricherà automaticamente le librerie necessarie.

## Compilazione

Per compilare il progetto, assicurati di avere Maven installato su Visual Studio Code. Quindi, con Control+Shift+P apri il menù e cerca l'opzione:

```bash
Java: Reload Projects
```

Questo comando scaricherà le dipendenze trovate su `pom.xml`.

Da ora sarà possibile importare tutte le classi necessarie per lavorare con Gson in Java, ad esempio:

```java
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.*;
```

