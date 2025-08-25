#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    string elemento;
    int cuenta;
    Nodo *enlace;
};

typedef Nodo* NodoPtr;

void insercion_cabeza(NodoPtr& cabeza, int cuenta, string elemento){
    NodoPtr temp_ptr;
    temp_ptr = new Nodo;

    temp_ptr->cuenta = cuenta;
    temp_ptr->elemento = elemento;
    temp_ptr->enlace = cabeza;
    
    cabeza = temp_ptr;
}
