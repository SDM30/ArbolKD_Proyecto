#ifndef __VERTICE__H__
#define __VERTICE__H__
#include <iostream> 

class Vertice {
private:
  unsigned int ind_ver;
  double x, y, z;

public:
  Vertice(unsigned int ind_ver, double x, double y, double z);
  Vertice();
  // getters
  unsigned int getInd_ver();
  double obtenerX();
  double obtenerY();
  double obtenerZ();
  void fijarX(double x);
  void fijarY(double y);
  void fijarZ(double z);
  double distanciaEuclidiana(Vertice val2);

  // Sobrecargar el operador << para imprimir los vértices
  friend std::ostream& operator<<(std::ostream& os, const Vertice& v);
};

#endif