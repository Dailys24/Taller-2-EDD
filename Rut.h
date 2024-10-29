#ifndef RUT_H
#define RUT_H

#include <iostream>

using namespace std;

//Clase rut
class Rut
{
  private:
    int num;
    string dv;

  public:
    Rut();

    Rut(int,string);
    Rut(const Rut& aux);

    void setnum(int val);
    int getnum() const;  // Modificado aquí
    bool verificarDV();

    void setdv(string val);
    string getdv() const;  // Modificado aquí

    void mostrar();

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Rut& rut);
};

#endif
