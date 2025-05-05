#include <iostream>

using namespace std;

class Libro {
    private:
        string titolo;
    public:
        static int counter;
        Libro(string titolo) {
            this->titolo = titolo;
            counter++;
        }
        string getTitolo() {
            return titolo;
        }
        static int getCounter() {
            return counter;
        }
};

int Libro::counter = 0;

int main() {
    Libro libri[] = {
        Libro("Harry Potter"),
        Libro("Java 6")
    };

    cout << "Libri registrati (" << Libro::getCounter() << ")"  << endl << endl;
    for (Libro libro : libri) {
        cout << libro.getTitolo() << endl;
    }
}
