#include "Ejercicio5.h"

Arreglo::Arreglo(){
  std::cout << "Enter the number of rows: \n? "; 
  std::cin >> this->row;
  std::cout << "Enter the number of columns: \n? "; 
  std::cin >> this->col;
  arr = new int*[this->row];
  for(int i = 0; i < this->row; i++) 
    *(this->arr + i) = new int[this->col];  
  namefn();
}

void Arreglo::namefn(){
  std::cout << "Enter the name: \n? ";
  std::getline(std::cin, this->name);
}

void Arreglo::insert(){
  int cont{0};
  int cont2{0};
  while(*(arr + cont) != nullptr){
    while(*(*(arr + cont2) + cont) != '\0'){
      std::cout << "Enter the number "<< cont2 + 1<< " from the row " << cont + 1 << ": \n? ";
      std::cin >> *(*(arr + cont2) + cont);
      cont2++;
    }
    cont++;
  }
}

void Arreglo::show(){
  for(int i = 0;i < this->row; i++){
    for(int j = 0; j < this->col; i++){
      std::cout << "\t" << *(*(arr + j) + i);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
