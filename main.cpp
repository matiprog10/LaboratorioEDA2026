#include <iostream>
#include <string>
#define MAX_CANT_PALABRAS_X_LINEA 100

using namespace std;
typedef char* Cadena;

// tipos de retorno
enum _retorno{
    OK, // operacion exitosa
    ERROR, // error en la operacion
    NO_IMPLEMENTADA // funcion no implementada
};
typedef enum _retorno TipoRetorno;
typedef unsigned int Posicion;


struct NodoLinea {
    Cadena palabras[MAX_CANT_PALABRAS_X_LINEA]; // array de palabras de la linea
    int cantPalabras; // cantidad de palabras en la linea
    NodoLinea* ant; // puntero al nodo anterior de la lista
    NodoLinea* sig; // puntero al nodo siguiente de la lista
};
 
// lista doblemente enlazada de líneas.
// permite InsertarLinea en O(1) peor caso.
struct Texto {
    NodoLinea* primero; // puntero al primer nodo de la lista
    NodoLinea* ultimo; // puntero al ultimo nodo de la lista
    unsigned int cantLineas; // cantidad de lineas en el texto
};
 
// ABB ordenado ignorando mayúsculas/minúsculas.
struct NodoABB {
    Cadena palabra; // puntero a la palabra
    NodoABB* izq; // puntero al nodo hijo izquierdo
    NodoABB* der; // puntero al nodo hijo derecho
};

static NodoLinea* crearLinea() { // funcion auxiliar para crear una nueva linea
    NodoLinea* nuevaLinea = new NodoLinea();
    nuevaLinea->cantPalabras = 0;
    nuevaLinea->ant = nullptr;
    nuevaLinea->sig = nullptr;
    for (int i = 0; i < MAX_CANT_PALABRAS_X_LINEA; i++) { // inicializa el array de palabras de la linea
        nuevaLinea->palabras[i] = nullptr;
    }
    return nuevaLinea;
}

TipoRetorno InsertarLinea(Texto& texto) { // funcion para insertar una nueva linea en el texto
    NodoLinea* nuevaLinea = crearLinea();

    nuevaLinea->ant = texto.ultimo;
    nuevaLinea->sig = nullptr;

    if (texto.primero == nullptr) {
        texto.primero = nuevaLinea;
    } else {
        texto.ultimo->sig = nuevaLinea;
    }

    texto.ultimo = nuevaLinea;
    texto.cantLineas++;
    return OK;
}


int main(){
    return 0;

}

