#include "Tarea3.h"

Array::Array(){
  std::cout << "Enter the number of employees: \n? ";
  std::cin >> this->tam;
  arr = new Employee[tam];
  for(int i = 0; i < tam; i++){
    arr[i].pieces = new int[3]; 
  }
  ocupados = 0;
}

void Array::regis(){
  for(int i = 0; i < tam ; i++ ){
    std::cin.ignore();
    std::cout << "Enter the name of the employee number " << i + 1 << " \n? ";
    std::getline(std::cin, this->arr[i].name);
    std::cout << "Enter your seniority \n? ";
    std::cin >> this->arr[i].years;
    std::cout << "Enter the number of pieces that you have done: ";
    for(int j = 0; j < 3; j++){
      std::cout << "\nPieces in month " << j + 1 << ": ";
      std::cin >> this->arr[i].pieces[j];
    }
  }
}

void Array::sort(){
  bool ordenado = false;
  int cont {0};
  while(!ordenado){
    ordenado = true;
    for(int i = 0; i < tam - 1 - cont; i++){
      if(arr[i].years > arr[i + 1].years ){
        std::swap(arr[i], arr[i + 1]);
        ordenado = false;
      }
    }
    cont++;
  }
}

void Array::show(){
  for(int i = 0; i < this->tam; i++){
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "\nName: " << this->arr[i].name <<
     "\nSeniority: " << this->arr[i].years << std::endl;
    for(int j = 0; j < 3; j++){
      std::cout << "Month "<< j + 1 << ": " << this->arr[i].pieces[j] << std::endl;
      
    }  
  }
}

void menu(Array ar){
  int opc;
  while(opc != 4){
    
    std::cout << "\n1) Register \n2) Sort \n3) Show \n4) Quit\n";
    std::cout << "-----------------------------------------------" << std::endl;  
    std::cout << "Enter your choice: \n? ";
    std::cin >> opc;
    switch (opc) {
      case 1:
        ar.regis();
        break;
      case 2:
        ar.sort();
        break;
      case 3:
        ar.show();
        break;
      case 4:
        std::cout << "Goodbye" << std::endl;
        break;
      default:
        std::cout << "You haven't enter a valid choice" << std::endl;
        break;
    }
  }  
}
