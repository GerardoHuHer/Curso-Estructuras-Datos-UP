#include "Arreglos.h"
int main(){
  setlocale(LC_ALL, "");
  Arreglo obj1 = Arreglo();
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << "Arreglo de Enteros:" << std::endl;
  std::cout << "Arreglo Original: ";
  obj1.show_int();
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << "Arreglo Ordenado: ";
  obj1.bubble_sortI();
  obj1.show_int();
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << "Arreglo de Strings:" << std::endl;
  std::cout << "Arreglo Original: ";
  obj1.show_string();
  std::cout << "------------------------------------------------" << std::endl;
  std::cout << "Arreglo Ordenado: ";
  obj1.bubble_sortS();
  obj1.show_string();
  std::cout << "------------------------------------------------" << std::endl;
  return 0;
}
