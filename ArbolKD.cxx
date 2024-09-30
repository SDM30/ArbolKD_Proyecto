#include "ArbolKD.h"

ArbolKD::ArbolKD() {
    this->raiz = NULL;
}

ArbolKD::ArbolKD(Vertice val) {
    NodoKD nodoRaiz(val);
    this->raiz = &nodoRaiz;
}

ArbolKD::~ArbolKD() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

Vertice ArbolKD::datoRaiz() {
    return (this->raiz)->obtenerDato();
}

NodoKD* ArbolKD::obtenerRaiz() {
    return this->raiz;
}

void ArbolKD::fijarRaiz(NodoKD *n_raiz) {
    this->raiz = n_raiz;
}

bool ArbolKD::esVacio() {
    return this->raiz == NULL;
}

bool ArbolKD::insertar(Vertice val) {
    bool insertado = false;
    this->raiz = insertarRec(this->raiz, val, insertado, 'x');
    return insertado;
}

NodoKD* ArbolKD::insertarRec(NodoKD* nodo, Vertice val, bool& insertado, char dimension) {

}

NodoKD* ArbolKD::cercano(NodoKD* n1, NodoKD* n2, Vertice val) {

}

NodoKD* ArbolKD::vecinoCercano(NodoKD* raiz, Vertice val) {

}

void ArbolKD::vecinoCercanoRec(NodoKD* nodo, Vertice val, char dimension, NodoKD*& mejorNodo, int& mejorDist) {

}

//Recorridos
void ArbolKD::preOrden() {
    if(!this->esVacio()) {
        this->preOrden(this->raiz);
    }
}


void ArbolKD::preOrden(NodoKD* nodo) {
    std::cout << nodo->obtenerDato() << " ";

    if (nodo->obtenerHijoIzq() != NULL) {
        this->preOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL) {
        this->preOrden(nodo->obtenerHijoDer());
    }
}


void ArbolKD::inOrden() {
    if (!this->esVacio()) {
        this->inOrden(this->raiz);
    }
}


void ArbolKD::inOrden(NodoKD *nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout << nodo->obtenerDato() << " ";
        this->inOrden(nodo->obtenerHijoDer());
    }
}


void ArbolKD::posOrden() {
    if(!this->esVacio()) {
        this->posOrden(this->raiz);
    }
}


void ArbolKD::posOrden(NodoKD *nodo) {
    if (nodo->obtenerHijoIzq() != NULL) {
        this->posOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL) {
        this->posOrden(nodo->obtenerHijoDer());
    }

    std::cout << nodo->obtenerDato() << " ";
}


void ArbolKD::nivelOrden() {
    if (!this->esVacio()) {
        std::queue<NodoKD*> cola;
        cola.push(this->raiz);
        NodoKD* nodo;

        while(!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";

            if (nodo->obtenerHijoIzq() != NULL) {
                cola.push(nodo->obtenerHijoIzq());
            }

            if (nodo->obtenerHijoDer() != NULL) {
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}