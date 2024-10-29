#ifndef EMPRESA_H
#define EMPRESA_H

#include "Rut.h"
#include <string>

using namespace std;

class Empresa {
  private:
    string rol;
    Rut rut;
    string nombre;
    string direccion;
    string giro;

  public:
    Empresa()
    { 
        this->rol = " ";
        this->nombre = " ";
        this->direccion = " ";
        this->giro = " ";
      }
    Empresa(Rut rut) : rut(rut) {}


    Empresa(string rol, Rut rut, string nombre, string direccion, string giro)
    : rol(rol), rut(rut), nombre(nombre), direccion(direccion), giro(giro) {}
    //Setters y Getters
    void setRol(string rol) 
      { 
        this->rol = rol; 
      }
    string getRol() 
    { 
      return rol; 
    }

    void setRut(Rut rut) 
    {
      this->rut = rut; 
    }
    Rut getRut() 
    { 
      return rut; 
    }

    void setNombre(string nombre) 
    { 
      this->nombre = nombre; 
    }
    string getNombre() 
    { 
      return nombre; 
    }    

    void setDireccion(string direccion) 
    { 
      this->direccion = direccion; 
    }
    string getDireccion() 
    { 
      return direccion; 
    }

    void setGiro(string giro) 
    { 
      this->giro = giro;
    }
    string getGiro()const
    {
      return giro; 
    }

    void visualizar() 
    {
      cout << "Rol: " << rol << endl;
      cout << "Rut: "; rut.mostrar();
      cout << "Nombre: " << nombre << endl;
      cout << "Direccion: " << direccion << endl;
      cout << "Giro: " << giro << endl;
    }
};

#endif
