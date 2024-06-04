#include "Examen.h"


bool Producto::operator==(Producto &pro2) {
  return this->codigo == pro2.codigo;
}
bool Producto::operator!=(Producto &pro2) {
  return this->codigo != pro2.codigo;
}
bool Producto::operator>=(Producto &pro2) {
  return this->codigo >= pro2.codigo;
}
bool Producto::operator<=(Producto &pro2) {
  return this->codigo <= pro2.codigo;
}
bool Producto::operator>(Producto &pro2) { return this->codigo > pro2.codigo; }
bool Producto::operator<(Producto &pro2) { return this->codigo < pro2.codigo; }

Arbol::Arbol() : root(NULL), nodo(NULL) {}

Nodo *Arbol::get_root() const { return root; }

void Arbol::crear_nodo(const Producto &val) {
  nodo = new Nodo;
  nodo->pro = val;
  nodo->izq = NULL;
  nodo->der = NULL;
}

void Arbol::insertar(Nodo* pos, int contador){
  if(root == NULL){
    nodo->nivel = contador;
    root = nodo;
    return;
  }
  if(nodo->pro < pos->pro){
    if(pos->izq == NULL){
      nodo->nivel = contador + 1;
      pos->izq = nodo;
      return;
    } else{
      insertar(pos->izq, contador +1);
      return;
    }
  }
  if(nodo->pro > pos->pro){
    if(pos->der == NULL){
      nodo->nivel = contador + 1;
      pos->der = nodo;
      return;
    } else{
      insertar(pos->der, contador +1);
      return;
    }
  }
  delete nodo;
}

Nodo* Arbol::buscar(Producto codigo, Nodo* pos){
  if(pos->pro == codigo){
    return pos;
  }
  if(pos->pro < codigo){
    if(pos->izq != NULL){
      return buscar(codigo, pos->izq);
    }
  }
  if(pos->pro > codigo){
    if(pos->der != NULL){
      return buscar(codigo, pos->der);
    }
  }
  return NULL;
}

void Arbol::pre_order(Nodo* pos){
  if(pos == NULL){
    return;
  }
  std::cout << "\t" << pos->pro.codigo << " " << pos->pro.nombre << " " << "Nivel: " << pos->nivel; 
  pre_order(pos->izq);
  pre_order(pos->der);
}

void menu(){
  int opc;
  Nodo* root;
  Arbol tree = Arbol();
  Producto paux, bus;
  Nodo* auxN;
  do {
    int aux = 0;
    std::cout << "\n1. Insertar \n2. Buscar \n3. Pre-Order \n4. Salir" << std::endl;
    std::cout << "Ingrese la opción deseada: \n> ";
    std::cin >> opc;
    root = tree.get_root();
    switch (opc) {
      case 1: 
        std::cout << "Ingrese el código de su producto: \n> ";
        std::cin >> paux.codigo;
        std::cout << "Ingrese el nombre de su producto: \n> ";
        std::cin >> paux.nombre;
        tree.crear_nodo(paux);
        tree.insertar(root, aux );
        break;

      case 2:
        if(root == NULL){
          std::cout << "El árbol está vacío" << std::endl;
          break;
        }
        std::cout << "Ingrese el código del producto que desea buscar: \n> ";
        std::cin >> bus.codigo;
        std::cout << "Ingrese el nombre del producto que desea buscar: \n> ";
        std::cin >> bus.nombre;

        auxN = tree.buscar(bus,root );
        if(auxN == NULL){
          std::cout << "El producto buscado no se encontró " << std::endl;
        } else{
          std::cout << "=======================" << std::endl; 
          std::cout << "Producto:" << std::endl;
          std::cout << "Código: " << auxN->pro.codigo << std::endl;
          std::cout << "Nombre: " << auxN->pro.nombre << std::endl;
          std::cout << "Nivel: " << auxN->nivel << std::endl;
        }        
        break;
      case 3:
        tree.pre_order(root);
        break;
      case 4:
        std::cout << "Hasta luego" << std::endl;
        break;
      default:
        std::cout << "No se ingresó un valor válido" << std::endl;
        break;
    }

  }while (opc != 4);

}
