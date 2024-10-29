#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>

#include "Patente.h"

using namespace std;

void leerArchivo(vector<Patente>& patentes) 
{
  // Leer los datos de las patentes desde un archivo de texto
  ifstream file("patentesComerciales.txt");
  string line;

  // Saltar la primera línea (encabezado del archivo)
  getline(file, line);

  while (getline(file, line)) {
    stringstream ss(line);
    string rol, rutStr, nombre, direccion, giro, fechaOtorgamiento, tipoPatente;
    double valorPatente = 0.0;  // Inicialmente el valor de la patente es 0

    getline(ss, rol, ';');
    getline(ss, rutStr, ';');
    getline(ss, nombre, ';');
    getline(ss, direccion, ';');
    getline(ss, giro, ';');
    getline(ss, fechaOtorgamiento, ';');
    getline(ss, tipoPatente, ';');

    // Crear un objeto Rut y un objeto Fecha inicializados adecuadamente
    Rut rut(1,rutStr); 
    int dia, mes, anio;
    // Parsing de la cadena fechaOtorgamiento para obtener los valores dia, mes y año
    sscanf(fechaOtorgamiento.c_str(), "%d/%d/%d", &dia, &mes, &anio);
    Fecha fechaPatente(dia, mes, anio);
    // Crear un objeto Patente y añadirlo a la lista
    Patente patente(rut, fechaPatente);
    patentes.push_back(patente);
  }

  file.close();
}

//Opcion 1
void Patente::calcularValor() 
{
  if (m_tipo == "Microempresa") 
  {
    m_valor = rand() % 5 + 1;  // Genera un número aleatorio entre 1 y 5
  } 
  else if (m_tipo == "Profesional") 
  {
    m_valor = rand() % 5 + 2;  // Genera un número aleatorio entre 2 y 6
  } 
  else if (m_tipo == "Industriales") 
  {
    m_valor = rand() % 5 + 3;  // Genera un número aleatorio entre 3 y 7
  } 
  else if (m_tipo == "Comerciales") 
  {
    m_valor = rand() % 5 + 4;  // Genera un número aleatorio entre 4 y 8
  } 
  else if (m_tipo == "Alcoholes") 
  {
    m_valor = rand() % 6 + 5;  // Genera un número aleatorio entre 5 y 10
  } 
  else 
  {
    m_valor = 0;
  }

  cout<<"Calculando valores..."<<endl;
  cout<<"Calculado."<<endl;
}

//opcion 2
bool Rut::verificarDV() 
{
   cout<<"Verificando..."<<endl;
  
  int suma = 0;
  int multiplicador = 2;
  int num = this->num;
  string dvCalculado;

  // Calcular la suma para el algoritmo de módulo 11
  while (num != 0) {
    int digito = num % 10;
    suma += digito * multiplicador;
    num /= 10;
    multiplicador = multiplicador % 7 + 1;  
  }

  // Calcular el dígito verificador
  int dv = 11 - (suma % 11);
  if (dv == 10) 
  {
    dvCalculado = "K";
  } 
  else if (dv == 11) 
  {
    dvCalculado = "0";
  } 
  else 
  {
    dvCalculado = to_string(dv);
  }

  // Comparar el dígito verificador calculado con el dígito verificador del RUT
  return dvCalculado == this->dv;
}

//opcion 4
// Función para calcular la media, mediana y desviación estándar del valor de patente por TIPO PATENTE
void calcularEstadisticasPorTipo(const vector<Patente>& patentes) 
{
  cout << "Estadísticas por TIPO PATENTE:\n";
  map<string, vector<double>> valoresPorTipo;
  for (const Patente& patente : patentes) 
  {
    valoresPorTipo[patente.get_tipo()].push_back(patente.get_valor());
  }
  for (const auto& entry : valoresPorTipo) 
  {
    const string tipo = entry.first;
    const vector<double>& valores = entry.second;
    double suma = 0.0;
    for (double valor : valores) 
    {
      suma += valor;
    }
    double media = suma / valores.size();
    vector<double> copiaValores = valores;
    sort(copiaValores.begin(), copiaValores.end());
    double mediana;
    if (valores.size() % 2 == 0) 
    {
      mediana = (copiaValores[valores.size() / 2 - 1] + copiaValores[valores.size() / 2]) / 2.0;
    }
    else 
    {
      mediana = copiaValores[valores.size() / 2];
    }
    double sumaCuadradosDiferencia = 0.0;
    for (double valor : valores) 
    {
      sumaCuadradosDiferencia += pow(valor - media, 2);
    }
    double desviacionEstandar = sqrt(sumaCuadradosDiferencia / valores.size());
    cout << "Tipo: " << tipo << "\n";
    cout << "Media: " << media << "\n";
    cout << "Mediana: " << mediana << "\n";
    cout << "Desviación Estándar: " << desviacionEstandar << "\n";
    cout << "\n";
  }
}
double calcularCoeficienteVariacion(const vector<double>& valores) 
{
  double media = 0.0;
  for (double valor : valores) 
  {
    media += valor;
  }
  media /= valores.size();
  double sumaCuadradosDiferencia = 0.0;
  for (double valor : valores) 
  {
    sumaCuadradosDiferencia += pow(valor - media, 2);
  }
  double desviacionEstandar = sqrt(sumaCuadradosDiferencia / valores.size());
  return (desviacionEstandar / media) * 100.0;
}
void encontrarGiroConMayorVariabilidad(const vector<Patente>& patentes) 
{
  cout << "Giro con mayor variabilidad en el pago de valor de patente:\n";
  vector<string> girosDeInteres = { "BOTILLERIA", "MINIMERCADOS", "REST.DIURNO" };
  map<string, vector<double>> valoresPorGiro;
  for (const Patente& patente : patentes) 
  {
    if (find(girosDeInteres.begin(), girosDeInteres.end(), patente.getGiro()) != girosDeInteres.end()) 
    {
      valoresPorGiro[patente.getGiro()].push_back(patente.get_valor());
    }
  }
  double maxCV = -1.0;
  string giroConMayorVariabilidad;
  for (const auto& entry : valoresPorGiro) 
  {
    const string giro = entry.first;
    const vector<double>& valores = entry.second;
    double cv = calcularCoeficienteVariacion(valores);
    if (cv > maxCV) 
    {
      maxCV = cv;
      giroConMayorVariabilidad = giro;
    }
  }
  cout << "Giro con mayor variabilidad: " << giroConMayorVariabilidad << "\n";
  cout << "Coeficiente de Variación (CV): " << maxCV << "%\n";
}
void calcularPercentil75(const vector<Patente>& patentes) 
{
  cout << "Valor patente en el percentil 75:\n";
  vector<double> valoresPatentes;
  for (const Patente& patente : patentes) 
  {
    valoresPatentes.push_back(patente.get_valor());
  }
  sort(valoresPatentes.begin(), valoresPatentes.end());
  int n = valoresPatentes.size();
  int indicePercentil75 = n * 0.75;
  double percentil75 = valoresPatentes[indicePercentil75];
  cout << "El valor patente en el percentil 75 es: " << percentil75 << "\n";
}

//opcion 5
void consultarPatentesPorAñoYTipo(const vector<Patente>& patentes, int año, const string& tipoPatente) 
{
  cout << "Patentes otorgadas en el año " << año << " y de tipo " << tipoPatente << ":\n";

  for (const Patente& patente : patentes) 
  {
    if (patente.get_fecha().getAa() == año && patente.get_tipo() == tipoPatente) 
    {
      cout << "ROL: " << patente.get_rol() << "\n";
      cout << "RUT: " << patente.get_rut() << "\n";
      cout << "NOMBRE: " << patente.get_nombre() << "\n";
      cout << "\n";
    }
  }
}
