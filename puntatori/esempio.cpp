#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int *p = &x;
    x = 10;
    cout << *p << endl;
    return 0;
}