#include "Fecha.h"

// Constructor
Fecha::Fecha()
{
    this->dd = 0;
    this->mm = 0;
    this->aa = 0;
}

Fecha::Fecha(int dd, int mm, int aa) 
{
    this->dd = dd;
    this->mm = mm;
    this->aa = aa;
}

// Getters
int Fecha::getDd() 
{
  return this->dd;
}

int Fecha::getMm() 
{
  return this->mm;
}

int Fecha::getAa() 
{
  return this->aa;
}

// Setters
void Fecha::setDd(int dd) 
{
  this->dd = dd;
}

void Fecha::setMm(int mm) 
{
  this->mm = mm;
}

void Fecha::setAa(int aa) 
{
  this->aa = aa;
}

void Fecha::visualizar() {
  cout << "Fecha de nacimiento: " << dd << "/" << mm << "/" << aa << endl;
}
