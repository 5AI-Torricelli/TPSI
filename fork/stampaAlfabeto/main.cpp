/**
 * Crea un programma che invoca N processi figli, ognuno dei quali deve stampare 10 volte una lettera dell'alfabeto, un processo per lettera.
 */

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n, r, p, s;

    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                            't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);
    int alphabetRepeat = 10;
    
    cout << "Quanti processi vuoi creare? (max 26): ";
    cin >> n;

    if (n > alphabetSize || n < 0) {
        cout << "Numero di processi non valido. Massimo 26." << endl;
        main();
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        p = getpid();
        r = fork();
        if (r < 0) {
            cout << "Fork fallita" << endl;
            return 1;
        }
        else if (r > 0) { // Processo padre
            wait(NULL); // Aspetta che il processo figlio termini
            cout << "Processo padre " << p << " terminato" << endl;
            break;
        }
        else { // Processo figlio
            s = getpid();
            cout << "Processo figlio " << s << " creato da " << p << " per la lettera " << alphabet[i] << endl;
            for (int j = 0; j < alphabetRepeat; j++) {
                cout << alphabet[i] << endl;
            }
        }
    }
    
}