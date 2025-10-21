#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    int dato;
    Nodo *enlace;
};

typedef Nodo NPila;

void pilaAgregar(NPila* &pila, int dato) {
    NPila* nuevo = new NPila;      // Crear nuevo nodo
    nuevo->dato = dato;            // Asignar dato
    nuevo->enlace = pila;          // Apuntar al tope anterior
    pila = nuevo;                  // Actualizar tope
}

void mostrarPila(NPila* pila) {
    while (pila != nullptr) {
        cout << pila->dato << " " << endl;
        cout << pila->enlace << endl;
        pila = pila->enlace;
    }
    cout << endl;
}

int main() {
    NPila* pila = nullptr;
    
    pilaAgregar(pila, 10);
    pilaAgregar(pila, 20);
    pilaAgregar(pila, 30);
    
    cout << "Pila: ";
    mostrarPila(pila);  // Salida: 30 20 10
    
    return 0;
}
