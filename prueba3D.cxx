#include "ArbolKD.h"
#include "Vertice.h"
#include <iostream>
#include <vector>

void pruebaIns(std::vector<Vertice>& puntos, ArbolKD& arbol);

void pruebaDifHiperPlano(ArbolKD& arbol);

int main() {
    ArbolKD arbol;

// Suponiendo que la clase Vertice ya está definida
    std::vector<Vertice> puntos;

    puntos.push_back(Vertice(0, 32, 25, 15));
    puntos.push_back(Vertice(0, 30, 35, 40));
    puntos.push_back(Vertice(0, 35, 30, 30));
    puntos.push_back(Vertice(0, 37, 12, 25));
    puntos.push_back(Vertice(0, 25, 45, 50));
    puntos.push_back(Vertice(0, 45, 32, 22));
    puntos.push_back(Vertice(0, 5, 15, 10));
    puntos.push_back(Vertice(0, 50, 50, 50));  // Punto adicional
    puntos.push_back(Vertice(0, 0, 0, 0));     // Punto cerca del origen
    puntos.push_back(Vertice(0, 100, 100, 100)); // Punto muy alejado

    pruebaIns(puntos, arbol);

    std::vector<Vertice> puntosDuplicados;

    puntosDuplicados.push_back(Vertice(0, 32, 25, 15));
    puntosDuplicados.push_back(Vertice(0, 100, 100, 100));
    puntosDuplicados.push_back(Vertice(0, 0, 0, 0));

    pruebaIns(puntosDuplicados, arbol);

    // Imprimir el árbol en inorden
    std::cout << "Recorrido Inorden del árbol KD:" << std::endl;
    arbol.inOrden();
    std::cout << std::endl;

    // Imprimir el árbol en preorden
    std::cout << "Recorrido Preorden del árbol KD:" << std::endl;
    arbol.preOrden();
    std::cout << std::endl;

    // Imprimir el árbol en posorden
    std::cout << "Recorrido Posorden del árbol KD:" << std::endl;
    arbol.posOrden();
    std::cout << std::endl;

    //Nivel Orden
    std::cout << "Recorrido Por niveles del árbol KD:" << std::endl;
    arbol.nivelOrden();
    std::cout << std::endl;

    // Probar la búsqueda del vecino más cercano
    Vertice verticeBusqueda(0, 33, 26, 16);  // Punto de prueba para buscar el vecino más cercano
    NodoKD* vecino = arbol.vecinoCercano(arbol.obtenerRaiz(), verticeBusqueda);

    if (vecino != nullptr) {
        std::cout << "Vecino más cercano al punto (" 
                  << verticeBusqueda.obtenerX() << ", "
                  << verticeBusqueda.obtenerY() << ", "
                  << verticeBusqueda.obtenerZ() << ") es: ("
                  << vecino->obtenerDato().obtenerX() << ", "
                  << vecino->obtenerDato().obtenerY() << ", "
                  << vecino->obtenerDato().obtenerZ() << ")" << std::endl;
    } else {
        std::cout << "No se encontró un vecino cercano." << std::endl;
    }

    pruebaDifHiperPlano(arbol);

    return 0;
}

void pruebaIns(std::vector<Vertice>& puntos, ArbolKD& arbol) {
    bool insrtExitosa = false;
    std::vector<Vertice>::iterator it = puntos.begin();
    for (;it != puntos.end(); it++) {
        insrtExitosa = arbol.insertar(*it);
        if (!insrtExitosa) std::cout<<"El Vertice "<< *it <<" esta repetido"<<std::endl;
    }

    if (insrtExitosa) {
        std::cout<<"Se han ingresado los "<<puntos.size()<<" vertices de manera exitosa"<<std::endl;
    }
}

void pruebaDifHiperPlano(ArbolKD& arbol) {

    // Insertar puntos en el árbol
    arbol.insertar(Vertice(0, 10, 5, 5));
    arbol.insertar(Vertice(0, 15, 10, 10));
    arbol.insertar(Vertice(0, 20, 5, 5)); // Punto en el otro lado del hiperplano
    arbol.insertar(Vertice(0, 30, 10, 10)); // Nodo que se busca primero en la búsqueda normal
    
    // Buscar vecino más cercano al punto (25, 5, 5)
    Vertice puntoBusqueda(0, 25, 5, 5);
    NodoKD* vecino = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoBusqueda);
    
    // Imprimir el resultado
    if (vecino) {
        std::cout << "Vecino más cercano al punto (" << puntoBusqueda.obtenerX() << ", " 
                  << puntoBusqueda.obtenerY() << ", " << puntoBusqueda.obtenerZ() << ") es: ("
                  << vecino->obtenerDato().obtenerX() << ", " 
                  << vecino->obtenerDato().obtenerY() << ", " 
                  << vecino->obtenerDato().obtenerZ() << ")" << std::endl;
    } else {
        std::cout << "No se encontró un vecino cercano." << std::endl;
    }
}
