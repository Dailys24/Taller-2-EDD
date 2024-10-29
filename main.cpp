/*
    TALLER 4 EDD 
    MIEMBROS:       Agustin Ugas Ñancucheo
                    Angelo Gonzalez Lobo
    FECHA:          10-09-2023
    SECCION:        412
    PROFESOR:       FERNANDO IVAN DONOSO SOLO DE ZALDIVAR
    LINK AL VDEO:   
 */

//Biblioteca
#include <iostream>
#include <string>

//Clases que ultilizaremos
#include "Funciones.h"
#include "Patente.h"
#include "Rut.h"
#include "Fecha.h"

using namespace std;
//Funcion main
int main() 
{

  vector<Patente> patentes;
  int op;
  char opcion;
  string rutStr;
  int indice=0;
  Patente miPatente;
  Rut miRut;
  string patente ="patentesComerciales.txt";

  leerArchivo(patentes);
  
  //Do While
  do
  {
    
    //Menu del prograna
    cout<<"****************************************************************************************"<<endl;
    cout << "\n-----Municipalidad El Colmo-----\n"<<endl;
    cout<<"\n------------- MENU -------------"<<endl<<endl;
    cout << "\n\u27a4 [1] Completar valor patente "<<endl;
    cout << "\n\u27a4 [2] Actualizar Digito Verificador "<<endl;
    cout << "\n\u27a4 [3] Año con más patentes de alcoholes "<<endl;
    cout << "\n\u27a4 [4] Estadísticas descriptivas "<<endl;
    cout << "\n\u27a4 [5] Consultas por año y Tipo de Patente "<<endl;
    cout << "\n\u27a4 [6] Generación de archivos "<<endl;
    cout << "\n\u27a4 [7] Procesar patentes "<<endl;
    cout << "\n\u27a4 [8] Terminar "<<endl;
    cout<<"\n****************************************************************************************"<<endl;
    cout << "\nIngrese una opcion: ";
    cin >> op;
        
    if(op > 8)
    cout << "\n*** Opcion invalida. Porfavor digite nuevamente ***\n"<<endl;
        
    switch(op)
    {
      
      case 1: //Completar valor patente
        
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        miPatente.calcularValor();
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=8;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
          if(opcion=='Y')
          {
            break;
          }
              
          else
            cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 2: //Actualizar digito verificador
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        miRut.verificarDV();
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=8;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y')
            {
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
          
      break;
      
      case 3: //Año con más patentes de alcoholes
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        //funcion
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=8;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
          if(opcion=='Y')
          {
            break;
          }
              
          else
            cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 4: //Estadísticas descriptivas
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        calcularEstadisticasPorTipo(patentes);
        encontrarGiroConMayorVariabilidad(patentes);
        calcularPercentil75(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        
        do
        {
          if(opcion=='N')
          {
            op=8;
            cout << "\n****Gracias por utilizar:)****"<<endl;
            break;
          }
          
          if(opcion=='Y'){
          break;
          }
              
          else
          cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 5: //Consultas por año y Tipo de Patente
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        //Funcion
        cout <<"------------------------------------------------------------------------------------ "<<endl;
      break;
      
      case 6: //Generación de archivos
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         //Funcion
        cout <<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 7: //Procesar patentes
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         //Funcion
        cout <<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 8: //Terminar el programa
        cout<<"*****Gracias por utilizar:)*****"<<endl;
      break;
    }
    
    
  }while(op!=8);
}
