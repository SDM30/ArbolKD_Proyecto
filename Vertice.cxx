#include "Vertice.h"
#include <cmath>

// Implementación del constructor
Vertice::Vertice(unsigned int ind_ver, double x, double y, double z) {
  this->ind_ver = ind_ver;
  this->x = x;
  this->y = y;
  this->z = z;
}

Vertice::Vertice() {}

// Implementación de los getters
unsigned int Vertice::getInd_ver() { return ind_ver; }

double Vertice::obtenerX() { return x; }

double Vertice::obtenerY() { return y; }

double Vertice::obtenerZ() { return z; }

void Vertice::fijarX(double x) {this->x = x;}
void Vertice::fijarY(double y) {this->y = y;}
void Vertice::fijarZ(double z) {this->z = z;}

double Vertice::distanciaEuclidiana(Vertice val2) {
  return sqrt(pow(this->x - val2.obtenerX(), 2)) + 
         sqrt(pow(this->y - val2.obtenerY(), 2)) + 
         sqrt(pow(this->z - val2.obtenerZ(), 2));
}