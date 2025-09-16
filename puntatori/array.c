#include <stdio.h>

/**
 * I puntatori sono strumenti per dichiarare una variabile cambiando 
 * la maniera nella quale memorizza il suo valore
 */

/**
 * Array pesa [3]: 1 MB
 * Array uguale: [123141421, 123141421, 123141421]
 * Peso array dipende da lunghezza
 */

void test(float v[][3]) {
    printf("Funziona!");
}

int main() {
    float v[3][3];
    test(v);
    return 0;
}