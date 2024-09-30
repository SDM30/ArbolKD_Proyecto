#include "ArbolKD.h"
#include "Vertice.h"
#include <iostream>

int main() {
    ArbolKD arbol;

    // Insertar algunos puntos en el árbol
    arbol.insertar(Vertice(0, 32, 25, 15));
    arbol.insertar(Vertice(0, 30, 35, 40));
    arbol.insertar(Vertice(0, 35, 30, 30));
    arbol.insertar(Vertice(0, 37, 12, 25));
    arbol.insertar(Vertice(0, 25, 45, 50));
    arbol.insertar(Vertice(0, 45, 32, 22));
    arbol.insertar(Vertice(0, 5, 15, 10));

    // Intentar insertar un vértice duplicado
    arbol.insertar(Vertice(0, 32, 25, 15));

        // Imprimir el árbol en inorden
    std::cout << "Recorrido Inorden del árbol KD:" << std::endl;
    arbol.inOrden();
    std::cout<< std::endl;

    return 0;
}