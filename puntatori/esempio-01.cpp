#include <iostream>

using namespace std;

/**
 * I puntatori sono strumenti per dichiarare una variabile cambiando 
 * la maniera nella quale essa memorizza il suo valore
 */

int main() {
    // int *x = new int(5); // è anche valido
    int x = 5;
    int *p = &x;
    x = 10;
    // printf("%i", *p);
    cout << *p << endl;
    return 0;
}