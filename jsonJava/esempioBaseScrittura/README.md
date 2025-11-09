<h1 align="center">Scrittura in un file JSON</h1>

Questo programma registra dei libri in un array per poi creare la struttura del file json e inserire i libri registrati in esso.

Per poi salvare tutto in un file `libri.json`.

## Compilazione

Scaricare online questi due file jar, che contengono le librerie per utilizzare [javax.json](https://mvnrepository.com/artifact/org.glassfish/javax.json/1.1.4):

- [JavaX.json](https://repo1.maven.org/maven2/org/glassfish/javax.json/1.1.4/javax.json-1.1.4.jar)
- [JavaX.json Module](https://repo1.maven.org/maven2/org/glassfish/javax.json/1.1.4/javax.json-1.1.4-module.jar)

Una volta scaricati, si devono spostare nella cartella lib:

```
lib/javax.json-1.1.4.jar
lib/javax.json-1.1.4-module.jar
```

Da ora sarà possibile importare tutte le classi/interfacce necessarie per lavorare con JSON in Java:

```java
import javax.json.*;
```
