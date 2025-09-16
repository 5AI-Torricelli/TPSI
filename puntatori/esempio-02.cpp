#include <iostream>

using namespace std;

/**
 * Esempio di utilizzo di puntatori per creare una copia di un
 * valore e cambiarne il valore senza cambiare l'originale.
 */
int main() {
    int *x = new int(5);
    int *p = x;
    // x = 10; // Non si può fare
    *x = 10; // Si deve istanziare un nuovo indirizzo
    printf("%i", *p);
    return 0;
}