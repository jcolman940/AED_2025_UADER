#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura del nodo
struct Nodo {
    string elemento;
    int cuenta;
    Nodo *enlace;
};

// Alias para puntero a Nodo
typedef Nodo* NodoPtr;

// Función de inserción por la cabeza con comentarios paso a paso
void insercion_cabeza(NodoPtr& cabeza, int cuenta, string elemento){
    // PASO 1: Crear puntero temporal
    NodoPtr temp_ptr;
    
    // PASO 2: Reservar memoria para nuevo nodo
    temp_ptr = new Nodo;
    
    // PASO 3: Asignar el valor de cuenta al nuevo nodo
    temp_ptr->cuenta = cuenta;
    
    // PASO 4: Asignar el string elemento al nuevo nodo
    temp_ptr->elemento = elemento;
    
    // PASO 5: Enlazar el nuevo nodo con la lista existente
    // El nuevo nodo apunta a lo que actualmente es la cabeza
    temp_ptr->enlace = cabeza;
    
    // PASO 6: Actualizar la cabeza para que apunte al nuevo nodo
    // Ahora el nuevo nodo se convierte en el primer elemento de la lista
    cabeza = temp_ptr;
}

// Función auxiliar para imprimir la lista
void imprimir_lista(NodoPtr cabeza) {
    NodoPtr actual = cabeza;
    cout << "Lista: ";
    while (actual != nullptr) {
        cout << "[" << actual->elemento << ", " << actual->cuenta << "]";
        if (actual->enlace != nullptr) {
            cout << " -> ";
        }
        actual = actual->enlace;
    }
    cout << " -> nullptr" << endl;
}

// Función para liberar la memoria de la lista
void liberar_lista(NodoPtr& cabeza) {
    while (cabeza != nullptr) {
        NodoPtr temp = cabeza;
        cabeza = cabeza->enlace;
        delete temp;
    }
}

int main() {
    // Inicializar lista vacía
    NodoPtr cabeza = nullptr;
    
    cout << "=== INSERCION POR LA CABEZA ===" << endl;
    
    // Insertar primer elemento
    cout << "\n1. Insertando 'manzana' con cuenta 10..." << endl;
    insercion_cabeza(cabeza, 10, "manzana");
    imprimir_lista(cabeza);
    
    // Insertar segundo elemento (queda al principio)
    cout << "\n2. Insertando 'naranja' con cuenta 5..." << endl;
    insercion_cabeza(cabeza, 5, "naranja");
    imprimir_lista(cabeza);
    
    // Insertar tercer elemento (queda al principio otra vez)
    cout << "\n3. Insertando 'platano' con cuenta 8..." << endl;
    insercion_cabeza(cabeza, 8, "platano");
    imprimir_lista(cabeza);
    
    // Insertar cuarto elemento
    cout << "\n4. Insertando 'uva' con cuenta 15..." << endl;
    insercion_cabeza(cabeza, 15, "uva");
    imprimir_lista(cabeza);
    
    // Estado final de la lista
    cout << "\n=== ESTADO FINAL ===" << endl;
    cout << "La lista queda en orden inverso a como se inserto:" << endl;
    imprimir_lista(cabeza);
    
    // Liberar memoria
    liberar_lista(cabeza);
    cout << "\nMemoria liberada correctamente!" << endl;
    
    return 0;
}