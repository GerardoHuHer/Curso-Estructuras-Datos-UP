#include "tarea5.h"

Cola::Cola(){
  mini = 0;
  maxi = TAM - 1;
  principio = final = -1;
  boletos = new Boleto[TAM];
  for(int i = 0; i < TAM; i++){
    boletos[i].no_boleto = i + 1;
    boletos[i].descuento = (i + 1)%5==0 ? true: false; 
    boletos[i].nombre = "- -";
  }
}

