#include <iostream>
#include <stdlib.h>

using namespace std;


// DEFINICION DE TIPOS.

struct nodo_grafo
{
	int id_nodo;
	struct nodo_arco* lista_arco;
	struct nodo_grafo* link;
};
typedef struct nodo_grafo NGrafo;

struct nodo_arco
{
	int id_arco;
	struct nodo_grafo* destino;
	struct nodo_arco* link;
};
typedef struct nodo_arco NArco;

/*2) Realice un algoritmo que elimine un arco, para esto deberá solicitar el id de nodo origen y destino
procediendo en consecuencia. Tratar los casos origen inexistente y/o arco no existente.*/

void eliminar_arco(NGrafo* lista_n, int id_nodo_origen, int id_nodo_destino) {
    // Buscar el nodo origen
    NGrafo* nodo_origen = lista_n;
    while (nodo_origen != nullptr && nodo_origen->id_nodo != id_nodo_origen) {
        nodo_origen = nodo_origen->link;
    }
    
    // Si no se encontró el nodo origen
    if (nodo_origen == nullptr) {
        cout << "Error: Nodo origen " << id_nodo_origen << " no existe" << endl;
        return;
    }
    
    // Buscar el arco en la lista del nodo origen
    NArco* anterior = nullptr;
    NArco* actual = nodo_origen->lista_arco;
    
    while (actual != nullptr && actual->destino->id_nodo != id_nodo_destino) {
        anterior = actual;
        actual = actual->link;
    }
    
    // Si no se encontró el arco
    if (actual == nullptr) {
        cout << "Error: No existe arco desde " << id_nodo_origen 
             << " hasta " << id_nodo_destino << endl;
        return;
    }
    
    // Eliminar el arco de la lista
    if (anterior == nullptr) {
        // El arco es el primero de la lista
        nodo_origen->lista_arco = actual->link;
    } else {
        // El arco está en medio o al final
        anterior->link = actual->link;
    }
    
    // Liberar memoria del arco
    delete actual;
    cout << "Arco eliminado: " << id_nodo_origen << " -> " << id_nodo_destino << endl;
}

/*3) Realizar un algoritmo que muestre el contenido de un grafo como se muestra en la tabla 1.*/

void grafo_mostrar (NGrafo* lista_n)
{
	cout << "Grafo:\n\n";
	
	while (lista_n != nullptr)
	{
		cout << "Nodo " << lista_n->id_nodo << ":" << endl;
		
		NArco* aux_la = lista_n->lista_arco;
		while (aux_la != nullptr)
		{
			cout << "  Arco " << aux_la->id_arco << " -> Nodo " << aux_la->destino->id_nodo << endl;
			aux_la = aux_la->link;
		}
		
		lista_n = lista_n->link;
	}
	cout << endl;
	cout << endl;
}

void agregar_nodo (NGrafo* &lista_n, int id_nodo){

    NGrafo* aux = lista_n;

    while (aux != nullptr){
        if (aux->id_nodo == id_nodo){
            cout << "!!! Error: Ya existe un nodo con ese id_nodo." << endl;
			return;
		}
	    aux = aux->link;
    }    
    
    aux = new NGrafo;           // Crea un nuevo nodo en memoria dinámica para el grafo
    aux->id_nodo = id_nodo;     // Asigna el ID del nodo al campo id_nodo del nuevo nodo
    aux->lista_arco = nullptr;  // Inicializa la lista de arcos como vacía (nullptr)
    aux->link = lista_n;        // El nuevo nodo apunta al primer nodo de la lista actual
    lista_n = aux;              // La lista ahora comienza con el nuevo nodo (se inserta al inicio)

}

void agregar_arco(NGrafo* lista_n, int id_arco, int id_nodo_origen, int id_nodo_destino) {
    
    NGrafo* nodo_origen = lista_n;
    NGrafo* nodo_destino = lista_n;
    
    // 1. BUSCAR NODO ORIGEN
    while (nodo_origen != nullptr && nodo_origen->id_nodo != id_nodo_origen) {
        nodo_origen = nodo_origen->link;
    }
    
    // 2. BUSCAR NODO DESTINO
    while (nodo_destino != nullptr && nodo_destino->id_nodo != id_nodo_destino) {
        nodo_destino = nodo_destino->link;
    }
    
    // 3. VERIFICAR QUE AMBOS NODOS EXISTEN
    if (nodo_origen == nullptr) {
        cout << "!!! Error: Nodo origen " << id_nodo_origen << " no existe." << endl;
        return;
    }
    if (nodo_destino == nullptr) {
        cout << "!!! Error: Nodo destino " << id_nodo_destino << " no existe." << endl;
        return;
    }
    
    // 4. VERIFICAR SI EL ARCO YA EXISTE "O" SI YA EXISTE UNA CONEXION AL MISMO NODO
    NArco* actual = nodo_origen->lista_arco;
    while (actual != nullptr) {
        if (actual->id_arco == id_arco || actual->destino->id_nodo == id_nodo_destino) {
            cout << "!!! Error: Arco ya existe o ID de arco duplicado." << endl;
            return;
        }
        actual = actual->link;
    }
    
    // 5. CREAR NUEVO ARCO
    NArco* aux = new NArco;
    aux->id_arco = id_arco;
    aux->destino = nodo_destino;
    aux->link = nodo_origen->lista_arco;  // Insertar al inicio
    nodo_origen->lista_arco = aux;
    
}

int main (){

    NGrafo* lista_n = nullptr;

    agregar_nodo (lista_n, 8);
    agregar_nodo (lista_n, 4);
    agregar_nodo (lista_n, 121);
    agregar_nodo (lista_n, 32);
    agregar_nodo (lista_n, 87);

    agregar_arco (lista_n, 5, 8, 4);
    agregar_arco (lista_n, 7, 4, 121);
    agregar_arco (lista_n, 73, 121, 8);
    agregar_arco (lista_n, 27, 121, 32);
    agregar_arco (lista_n, 81, 87, 4);

    grafo_mostrar (lista_n);

    return 0;
}  