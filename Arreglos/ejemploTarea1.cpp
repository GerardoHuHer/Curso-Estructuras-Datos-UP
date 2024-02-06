#include "Arreglos.h"

int main(){
  setlocale(LC_ALL, "");
  Arreglo array = Arreglo();
  array.MostrarEnteros();
  array.OrdenarEnteros_burbuja();
  array.MostrarEnteros();
  array.MostrarPalabras();
  array.OrdenarPalabras_burbuja();
  array.MostrarPalabras();
  return 0;
}
