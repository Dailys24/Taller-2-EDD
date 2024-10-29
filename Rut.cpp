#include "Rut.h"
using namespace std;

Rut::Rut()
{
  this->dv='0';
  this->num=00000000;
}

Rut::Rut(int n, string dig)
{
  this->num=n;
  this->dv=dig;
}

Rut::Rut(const Rut& aux)
{
  num = aux.num;
  dv = aux.dv;
}

//Setters
void Rut::setdv( string val )
{
  this->dv = val;
}

void Rut::setnum( int val)
{
  this->num = val;
}

//Getters
string Rut::getdv() const  // Modificado aquí
{
  return this->dv;
}

int Rut::getnum() const  // Modificado aquí
{
  return this->num;
}

void Rut::mostrar()
{
  cout << num << "-" << dv;
}

// Implementación de la sobrecarga del operador <<
ostream& operator<<(ostream& os, const Rut& rut) {
  os << rut.getnum() << "-" << rut.getdv();
  return os;
}
