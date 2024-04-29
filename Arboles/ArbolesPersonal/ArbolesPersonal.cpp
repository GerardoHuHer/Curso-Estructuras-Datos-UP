#include "ArbolesPersonal.h"

void menu(){
  Tree<int> tree = Tree<int>();  
  tree.insert(5);
  tree.insert(3);
  tree.insert(2);
  tree.insert(6);
  tree.insert(9);
  tree.in_order_traversal();
  Tree<std::string> tree2 = Tree<std::string>();  
  tree2.insert("Alejandra");
  tree2.insert("Gerardo");
  tree2.insert("Efren");
  tree2.insert("Montse");
  tree2.in_order_traversal();

  Tree<Coche> tree3 = Tree<Coche>();
  for (int i = 0; i < 5 ; i++ ) {
    Coche coche = Coche();
    std::cin >> coche;
    tree3.insert(coche);
  }
  tree3.in_order_traversal();
}

std::ostream& operator<<(std::ostream& os, Coche& car){
  os << "Placa: " << car.placa;
  return os;
}

std::istream& operator>>(std::istream& is, Coche& car){
  std::cout << "Ingrese la placa de su coche: \n> ";
  std::cin >> car.placa; 
  std::cout << "Ingrese el número de ruedas de su coche: \n> ";
  std::cin >> car.ruedas; 
  std::cout << "Ingrese el color de su coche: \n> ";
  std::cin >> car.color; 
  std::cout << "Ingrese la marca de su coche: \n> ";
  std::cin >> car.marca; 
  return is;
}

bool operator<(Coche& car1, Coche& car2){
  return car1.placa < car2.placa;
}
