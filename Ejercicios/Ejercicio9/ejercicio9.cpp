#include "ejercicio9.h"

ColaCirular::ColaCirular(){
  minimo = 0;
  maximo = TAM - 1;
  inicio = final = -1;
  palabras = new std::string[TAM];
  for (int i = 0; i < TAM ; i++ ) {
    palabras[i] = "- -";
  } 
}

int ColaCirular::insertar(std::string nuevo){
  // Paso 1: Revisar capacidad
  // Código -1 significa está lleno
  if (inicio == minimo && final == maximo) { 
    return -1;
  }
  if ((final + 1) == inicio) {
    return -1;
  }
  // Paso 2: Incrementar final
  final++;
  if (inicio == -1) {
    inicio++;
  }
  // Paso 2.5: Si final ya pasó el máximo, significa que llego a su tope por lo que hay que regresarlo al inicio para que sea circular
  if(final > maximo){
    final = minimo;
  }
  // Paso 3: Colocar el nuevo valor en la posición final
  palabras[final] = nuevo;
  // Código 0: significa se insertó con éxito
  return 0;
}

std::string ColaCirular::extraer(){
  std::string aux;
  // Paso 1: Revisar si hay información
  if(final == -1 && inicio == -1){
    return "";
  }
  // Paso 2: Extraer información
  aux = palabras[inicio];
  palabras[inicio] = "- -";
  // Paso 3: Incrementar inicio
  if (inicio == final) {
    inicio = final = -1;
    return aux;
  }
  inicio++;
  return aux;
}

void ColaCirular::mostrar(){
  std::cout << "\nPalabras" << std::endl;
  for(int i = 0; i < TAM; i++){
    std::cout << "\t" << palabras[i];
    if(i == minimo) std::cout << "\t <= Mínimo";
    if(i == maximo) std::cout << "\t <= Máximo";
    if(i == inicio) std::cout << "\t <= Inicio";
    if(i == final) std::cout << "\t <= Final";
    std::cout << std::endl;
  }
}
