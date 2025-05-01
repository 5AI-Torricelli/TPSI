/**
 * Gestore azienda: questo programma si occupa di generare dei processi che saranno i nostri "dipendenti" 
 * e di assegnargli un compito differente per ognuno di loro
 *
 * Questo esercizio lavora con fork() e execlp()
 */

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
  cout << "######################## Gestore Azienda ########################" << endl;
  int pid;

  // Compiti da assegnare ai lavoratori
  const char* tasks[] = {
      "./stampaMessaggio",   // Compito 1: Stampa un messaggio
      "date",   // Compito 2: Mostra la data attuale
      "whoami" // Compito 3: Mostra l'utente corrente
  };

  const int numTasks = 3;

  for (int i = 0; i < numTasks; i++) {
    pid = fork();

    if (pid < 0) {
      cout << "Errore in fork()!" << endl;
      return -1;
    } 
    if (pid == 0) {
      cout << "Dipendente " << getpid() << ": Comincio il compito " << i + 1 << endl;
      
      execlp(tasks[i], tasks[i], NULL); // Rimpiazza il processo attuale con il processo del programma che stiamo per avviare
      // se execlp() va a buon fine, allora il codice si fermerà qui, altrimenti se generato un errore continuerà eseguendo la parte sotto
      cout << "Errore nell'eseguire il compito!" << endl;
      return -2;
    }
    // Mentre il processo figlio si è fermato (perché la sua esecuzione è stata rimpiazzata con execlp), 
    // Il padre continuerà a eseguire altri processi figlio fino alla fine del ciclo for
  }

  // Il padre ha bisogno di terminare ogni singolo processo figlio, 
  // quindi aspettiamo per ognuno di loro la chiusura dei processi figlio
  for (int i = 0; i < numTasks; i++) {
      wait(NULL); // Se inserito NULL la funzione wait() funzione comunque
  }

  cout << "Tutti i dipendenti hanno eseguito il loro ruolo." << endl;
  return 0;
}

