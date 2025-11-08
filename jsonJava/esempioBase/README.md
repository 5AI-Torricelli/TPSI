## Compilazione

Mettere il file .zip scaricato dal [sito associato](https://javaee.github.io/jsonp).
Ed aver inserito il contenuto dello zip in una cartella chiamata `javaxjson-src`:

```
lib/javaxjson-src/main/java/javax/json/(...).java
lib/javaxjson-src/main/jdk9/module-info.java
```

Successivamente si accede a un terminale andando nella cartella del progetto ed eseguendo:

```bash
javac -d lib/javaxjson-bin $(find lib/javaxjson-src/main/java -name "*.java")
```

su Windows:

```powershell
for /R lib\javaxjson-src\main\java %f in (*.java) do javac -d lib\javaxjson-bin "%f"
```

Questo comando crea i `.class` dentro a `lib/javaxjson-bin`.

Mentre con quest'altro comando si compila il programma:

```bash
jar --create --file lib/javaxjson.jar -C lib/javaxjson-bin .
```

Ora abbiamo compilato il nostro `javaxjson.jar` nella cartella `lib` del progetto.
