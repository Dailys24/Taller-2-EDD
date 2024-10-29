#include "Patente.h"
#include "Fecha.h"
#include "Empresa.h"

using namespace std;
Patente::Patente()
{
    this->m_tipo= " ";
    this->m_valor=0;
    this->m_procesado=0;
}

Patente::Patente(Rut rut, Fecha fechaPatente) : Empresa(rut), m_fechaPatente(fechaPatente) 
{

}


void Patente::set_fecha(Fecha fechaPatente)
{
  m_fechaPatente=fechaPatente;
}
void Patente::set_tipo(string tipo)
{
  m_tipo=tipo;
}
void Patente::set_valor(int valor)
{
  m_valor=valor;
}
void Patente::set_procesado(bool procesado)
{
  m_procesado=procesado;
}
void Patente::set_rut(const Rut& r) 
{
  rut = r;
}


Fecha Patente::get_fecha()
{
   return m_fechaPatente;
}
string Patente::get_tipo()const
{
   return m_tipo;
}
int Patente::get_valor()const
{
   return m_valor;
}
bool Patente::get_procesado(){

   return m_procesado;
}
Rut Patente::get_rut() const
{
  return rut;
}
string Patente::get_nombre() const 
{
  return nombre;
}

void Patente::visualizar()
{
  cout<<"tipo:      "<<m_tipo<<endl;
  cout<<"valor:     "<<m_valor<<endl;
  cout<<"procesado: "<<m_procesado<<endl;
  m_fechaPatente.visualizar();
  Empresa::visualizar();
}


Patente::~Patente()
{
  //dtor
}
