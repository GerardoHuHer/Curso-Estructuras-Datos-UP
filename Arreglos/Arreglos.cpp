#include "Arreglos.h"

void Arreglo::MostrarEnteros(){
  // Función para imprimir arreglo de enteros
  for(int i = 0; i < TAM; i++){
    cout << "\t" << *(enteros + i);    
  }
  cout << endl;
}

void Arreglo::MostrarPalabras(){
  for(int i = 0; i < TAM; i++){
    cout << "\t" << *(palabras + i);
  }
  cout << endl;
}

void Arreglo::OrdenarEnteros_burbuja(){
  int aux, itera = 0; 
  bool ordenado = false;
  while(!ordenado){
    ordenado = true;
    for(int j = 0; j< ocupadosEnteros - itera - 1; j++){
      if(*(enteros + j) > *(enteros + j + 1)){
        aux = *(enteros + j);
        *(enteros + j) = *(enteros + j + 1);
        *(enteros + j + 1) = aux;
        ordenado = false;
      }
    }
    itera++;
  }
}

void Arreglo::OrdenarPalabras_burbuja(){
  int itera = 0; 
  std::string aux;
  bool ordenado = false;
  while(!ordenado){
    ordenado = true;
    for(int j = 0; j< ocupadosPalabras - itera - 1; j++){
      if(*(palabras + j) > *(palabras+ j + 1)){
        aux = *(palabras+ j);
        *(palabras+ j) = *(palabras+ j + 1);
        *(palabras+ j + 1) = aux;
        ordenado = false;
      }
    }
    itera++;
  }
}
