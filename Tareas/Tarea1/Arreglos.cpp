#include "Arreglos.h"

void Arreglo::show_int(){
  for(int i = 0; i < sizeof(int_array)/ sizeof(int); i++){
    std::cout << "\t" << *(int_array + i);
  }
  std::cout << std::endl;
}

void Arreglo::show_string(){
  for(int i = 0; i < sizeof(str_array)/ sizeof(std::string); i++){
    std::cout << "\t" << *(str_array + i);
  }
  std::cout << std::endl;
}

void Arreglo::bubble_sortI(){
  int aux;
  int iterable {0};  
  bool ordenado {false};
  while(!ordenado){
    ordenado = true;
    for(int elem = 0; elem < sizeof(int_array)/sizeof(int) - iterable - 1; elem++ ){
      if(int_array[elem] > int_array[elem + 1 ]){
        aux = int_array[elem + 1];
        int_array[elem + 1] = int_array[elem];
        int_array[elem] = aux;
        ordenado = false;
      }
    }
    iterable++;
  }
}

void Arreglo::bubble_sortS(){
  std::string aux;
  int iterable {0};  
  bool ordenado {false};
  while(!ordenado){
    ordenado = true;
    for(int elem = 0; elem < sizeof(str_array)/sizeof(std::string) - iterable - 1; elem++ ){
      if(*(str_array + elem)> *(str_array + elem + 1)){
        aux = str_array[elem + 1];
        str_array[elem + 1] = str_array[elem];
        str_array[elem] = aux;
        ordenado = false;
      }
    }
    iterable++;
  }
}
