#include "Ejercicio5.h"

Arreglo::Arreglo(){
  namefn();
  std::cout << "Enter the number of rows: \n? "; 
  std::cin >> this->row;
  std::cout << "Enter the number of columns: \n? "; 
  std::cin >> this->col;
  arr = new int*[this->row];
  for(int i = 0; i < this->row; i++) 
  *(this->arr + i) = new int[this->col];  
}

void Arreglo::namefn(){
  std::cout << "Enter the name: \n? ";
  std::getline(std::cin, this->name);
}

void Arreglo::insert(){
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->col; j++){
      std::cout << "Enter the number "<< j + 1 << " from the row " << i << ": \n? ";
      std::cin >> *(*(arr + i) + j);
    }
  }
}

void Arreglo::sort(){
  int aux, cont{0};
  for(int i = 0; i < this->row; i++){
    bool ordenado {false};
    while(!ordenado){
      ordenado = true;
      for(int j = 0; j < this->col - 1 - cont; j++){
        if(arr[i][j] > arr[i][j + 1]){
          aux = arr[i][j];
          arr[i][j] = arr[i][j + 1];
          arr[i][j + 1] = aux;
          ordenado = false;
        }
      }
    }
  }
}

void Arreglo::show(){
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->col; j++){
      std::cout << "\t" << *(*(arr + i) + j);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

