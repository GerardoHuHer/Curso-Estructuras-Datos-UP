#include "filaEstatica.h"

Colas::Colas(){
  minimo = 0;
  maximo = TAM - 1;
  for(int i = 0; i < TAM; i++) cola[i] = 0;
  
  principio = final = -1;
}

void Colas::mostrar(){
  if((principio == -1) || (final == -1)){
    std::cout << "Cola vacía" << std::endl;
    return;
  }  ;
  for(int i = 0; i < TAM; i++ ){
    std::cout << "\t" << cola[i];
    if(i == principio) std::cout << " <= Principio";
    if(i == final) std::cout << " <= Final";
    if(i == maximo) std::cout << " <= Máximo";
    if(i == minimo) std::cout << " <= Mínimo";
    std::cout << std::endl;
  }
}

// int Colas::insertar(int num){
//   if(maximo == final){
//     return -1;
//   }
//   final++;
//   cola[final] = num;
//    return 0; 
// }

// int Colas::extrar(){
//   if(final == -1 || principio == -1)
// }

void menu(){
  Colas enteros;
  int opc;
  do {
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir \n"; 

  
  }while (opc != 4);
}
