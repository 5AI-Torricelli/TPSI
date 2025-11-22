<h1 align="center">Lettura di un file JSON</h1>

Dato un file json con all'interno dei libri registrati.

Questo programma legge e stampa il contenuto del file `libri.json` fornito.

## Dipendenze

Questo progetto utilizza la libreria `jakarta.json` per la gestione dei file JSON. Se stai utilizzando Maven, puoi aggiungere la seguente dipendenza al tuo file `pom.xml`:

```xml
<dependency>
    <groupId>org.glassfish</groupId>
    <artifactId>jakarta.json</artifactId>
    <version>2.0.1</version>
</dependency>
```

Dopo aver aggiunto la dipendenza, Maven scaricherà automaticamente le librerie necessarie.

## Compilazione

Per compilare il progetto, assicurati di avere Maven installato su Visual Studio Code. Quindi, con Control+Shift+P apri il menù e cerca l'opzione:

```bash
Java: Reload Projects
```

Questo comando scaricherà le dipendenze trovate su `pom.xml`.

Da ora sarà possibile importare tutte le classi/interfacce necessarie per lavorare con JSON in Java:

```java
import jakarta.json.*;
```
