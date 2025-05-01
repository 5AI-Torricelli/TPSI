# La famiglia exec

# Che cos'è una funzione "exec"

Per funzione exec si intende una funzione che sostituisce il codice in esecuzione del processo che la chiama, con l'esecuzione di un altro programma, questo risulta utile per creare dei processi con uno scopo ben preciso quando si usa con `fork()`, senza che le istruzioni siano già nel codice originale, rendendo il programma più versatile.

Sotto è presente una lista delle funzioni della famiglia Exec:

> NOTA: gli argomenti da passare devono terminare con un ultimo elemento NULL (se senza argomenti passare sempre il nome dell'eseguibile stesso come primo elemento e NULL come ultimo)

1. `execl(percorso completo del file, argomenti da passare)`: esegue un programma specificando il percorso completo del file e con una lista di parametri separati 
 
2. `execlp(nome del programma, argomenti da passare)`: simile a execl() con la differenza che il file da eseguire viene attribuito attraverso la variabile di sistema PATH, ovvero una variabile contente i percorsi tutti gli eseguibili che possiamo eseguire soltanto chiamandoli nel terminale (esempio quando usiamo il comando "ls" invece di "/bin/ls" che è il suo percorso completo), ovviamente si può anche specificare semplicemente un file nella stessa cartella del progetto

3. `execv(percorso completo del file, array di stringhe degli argomenti da passare)`: anche lui fa lo stesso identico lavoro basandoci però su un array di stringhe sempre terminante con NULL e che inizia con il nome dell'eseguibile stesso

4. `execvp(nome del programma, array di stringhe degli argomenti da passare)`: questo necessità solo del nome del programma e di un array di stringhe con all'interno il nome del programma, gli argomenti e deve terminare con NULL

5. `execve(percorso completo del file, array di stringhe degli argomenti, array di stringhe che rappresentano le variabili di ambiente per il nuovo processo)`: la funzione più generica della famiglia exec, permette di avere controllo completo sull'esecuzione di un programma impostando anche le variabili di ambiente.

## Significato nel nome della funzione

Le lettere dopo la parola exec hanno un significato ben preciso:

- l = argomenti da passare in "lista", come execl(file, arg1, arg2, arg3, NULL)

- v = argomenti da passare in un array di stringhe come execv(file, {arg1, arg2, arg3, NULL})

- p = il percorso del file è determinato tenendo in considerazione la variabile di sistema PATH

- e = si impostano delle variabile di ambiente
