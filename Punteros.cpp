#include <iostream>

using namespace std;

int main () {
    // 1. Declaración de variables y punteros
    int numero = 42;
    int* punteroNumero;  // Declaración de un puntero a int
    
    // 2. Asignación de la dirección de memoria
    punteroNumero = &numero;  // & obtiene la dirección de 'numero'
    
    cout << "=== Conceptos Basicos de Punteros ===" << endl;
    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero (&numero): " << &numero << endl;
    cout << "Valor de punteroNumero: " << punteroNumero << endl;
    cout << "Valor al que apunta punteroNumero (*punteroNumero): " << *punteroNumero << endl;
    
    // 3. Modificación a través del puntero
    *punteroNumero = 100;
    cout << "\nDespues de modificar *punteroNumero = 100:" << endl;
    cout << "Valor de numero: " << numero << endl;
    
    // 4. Aritmética de punteros
    int arreglo[5] = {10, 20, 30, 40, 50};
    int* punteroArreglo = arreglo;  // Apunta al primer elemento
    
    cout << "\n=== Aritmetica de Punteros ===" << endl;
    cout << "Primer elemento (*punteroArreglo): " << *punteroArreglo << endl;
    punteroArreglo++;  // Mover el puntero al siguiente elemento
    cout << "Segundo elemento (*punteroArreglo): " << *punteroArreglo << endl;
    
    // 5. Punteros y memoria dinámica
    int* punteroDinamico = new int;  // Asignación de memoria dinámica
    *punteroDinamico = 500;
    cout << "\n=== Memoria Dinamica ===" << endl;
    cout << "Valor en memoria dinamica: " << *punteroDinamico << endl;
    
    // Importante: liberar memoria asignada
    delete punteroDinamico;
    
    // 6. Puntero nulo
    punteroDinamico = nullptr;  // Buena práctica después de delete
    
    return 0;
}