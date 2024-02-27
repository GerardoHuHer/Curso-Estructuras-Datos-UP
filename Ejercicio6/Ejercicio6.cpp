#include "Ejercicio6.h"

PilaEnteros::PilaEnteros(){
  tope = min - 1;
  max = TAM - 1;
  min = 0; 
  pila = new int[TAM];
  for(int i = 0; i < TAM; i++){
    *(pila + i) = 0;
  }
 }
