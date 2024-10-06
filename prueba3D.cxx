#include "ArbolKD.h"
#include "Vertice.h"
#include <iostream>
#include <vector>

void pruebaIns(std::vector<Vertice>& puntos, ArbolKD& arbol);

void pruebaVecinoCercano(ArbolKD& arbol, Vertice punto);


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

    //Caso 1: punto dentro del arbol
    Vertice verticeBusqueda(0, 100, 100, 100);  // Punto de prueba para buscar el vecino más cercano
    pruebaVecinoCercano(arbol, verticeBusqueda);
    
    //Caso 2: punto cercano a vertice en el arbol
    Vertice verticeBusqueda2(0, 36, 29, 28);
    pruebaVecinoCercano(arbol, verticeBusqueda2);

    //Caso 3: diferente hiperplano
    Vertice verticeBusqueda3(0, 24, 25, 49);
    pruebaVecinoCercano(arbol, verticeBusqueda3);


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

void pruebaVecinoCercano(ArbolKD& arbol, Vertice punto) {
    NodoKD* vecinoOtroHiperplano = arbol.vecinoCercano(arbol.obtenerRaiz(), punto);

    if (vecinoOtroHiperplano != nullptr) {
        std::cout << "Vecino más cercano al punto (" 
                << punto.obtenerX() << ", "
                << punto.obtenerY() << ", "
                << punto.obtenerZ() << ") es: ("
                << vecinoOtroHiperplano->obtenerDato().obtenerX() << ", "
                << vecinoOtroHiperplano->obtenerDato().obtenerY() << ", "
                << vecinoOtroHiperplano->obtenerDato().obtenerZ() << ")" << std::endl;
    } else {
        std::cout << "No se encontró un vecino cercano." << std::endl;
    }
}

