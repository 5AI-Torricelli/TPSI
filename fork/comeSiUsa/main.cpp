#include <iostream>
#include <string>

// Fondamentali
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
    int array[6] = {1, 2, 3, 4, 5, 6};  
    string array1[6] = {"a", "b", "c", "d", "e", "f"}; 
    int stato;
    // Funzione che ritorna il PID (Process ID) del processo corrente
    int p = getpid();
    // Funzione per creare il nuovo processo figlio
    // Esso è completamente indipendente da quello padre
    int r = fork();

    if(r < 0){
        cerr << "Errore nella creazione del processo\n";
        return 1;
    } else if (r > 0){
        cout << "Pid padre: " << p << "\n";
        
        for (int i = 0; i < 6; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        // Aspetta perché il processo figlio termini esecuzione
        wait(&stato);
        cout << stato << "\n";
    } else {
        
        p = getpid();
        cout << "Pid figlio: " << p << "\n";
        for (int i = 0; i < 6; i++) {
            cout << array1[i] << " ";
        }
        cout << endl;

        return 0;
    }
    // Il processo figlio termina la sua esecuzione solo il processo padre invoca la funzione wait(), altrimenti rimarrà un processo zombie.
    return 0;
}   
