#ifndef PATENTE_H
#define PATENTE_H
#include "Fecha.h"
#include "Empresa.h"

using namespace std;

class Patente: public Empresa{
    private:
    Fecha m_fechaPatente;
    string m_tipo;
    int m_valor;
    bool m_procesado;

    protected:

    public:
    Patente();
    Patente(Rut rut, Fecha fechaPatente);

    void set_fecha(Fecha fechaPatente);
    void set_tipo(string tipo);
    void set_valor(int valor);
    void set_procesado(bool procesado);
    void calcularValor();
    void set_rut(const Rut& r);

    Fecha get_fecha()const;
    string get_tipo()const;
    int get_valor()const;
    bool get_procesado();
    string get_rol() const;
    Rut get_rut() const; 
    string get_nombre() const;

    void visualizar();

    ~Patente();
};

#endif // Patente_H
