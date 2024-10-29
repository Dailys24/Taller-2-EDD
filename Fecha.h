#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha 
{
  private:
    int dd;
    int mm;
    int aa;

  public:
    Fecha();
    Fecha(int dd, int mm, int aa);

    int getDd();
    int getMm();
    int getAa();

    void setDd(int dd);
    void setMm(int mm);
    void setAa(int aa);
    void visualizar();
};

#endif
