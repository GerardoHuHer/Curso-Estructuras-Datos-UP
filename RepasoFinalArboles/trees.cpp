#include "trees.h"

Arbol::Arbol() : nodo(NULL), raiz(NULL) {}

Arbol::Nodo *Arbol::get_root() { return raiz; }

void Arbol::crear_nodo(const int &val) {
  nodo = new Nodo;
  nodo->dato = val;
  nodo->der = NULL;
  nodo->izq = NULL;
}

void Arbol::insertar(Nodo *pos) {
  if (raiz == NULL) {
    raiz = nodo;
    return;
  }
  if (nodo->dato < pos->dato) {
    if (pos->izq == NULL) {
      pos->izq = nodo;
      return;
    } else {
      insertar(pos->izq);
    }
  }
  if (nodo->dato > pos->dato) {
    if (pos->der == NULL) {
      pos->der = nodo;
      return;
    } else {
      insertar(pos->der);
    }
  }
  delete nodo;
}

Arbol::Nodo *Arbol::busqueda_in_order(const int &val, Nodo *pos) {
  if (raiz == NULL) {
    return NULL;
  }
  if (val < pos->dato) {
    if (pos->izq == NULL) {
      return NULL;
    }
    return busqueda_in_order(val, pos->izq);
  }
  if(val > pos->dato){
    if(pos->der == NULL){
      return NULL;
    }
    return busqueda_in_order(val, pos->der);
  }
  return pos;
}

void Arbol::in_order(Nodo* pos){
  if(pos->izq != NULL){
    in_order(pos->izq);
  }
  std::cout << "\t" << pos->dato;
  if(pos->der != NULL){
    in_order(pos->der);
  }
}
void Arbol::pre_order(Nodo* pos){
  std::cout << "\t" << pos->dato;
  if(pos->izq != NULL){
    pre_order(pos->izq);
  }
  if(pos->der != NULL){
    pre_order(pos->der);
  }
}
void Arbol::post_order(Nodo* pos){
  if(pos->izq != NULL){
    post_order(pos->izq);
  }
  if(pos->der != NULL){
    post_order(pos->der);
  }
  std::cout << "\t" << pos->dato;
}

void menu(){
  Arbol tree = Arbol();
  int opc, aux;
  Arbol::Nodo* root, *naux;
  do {
    std::cout << "\n1. Insertar\n2. Buscar\n3. In-Order\n4. Post-Order\n5. Pre-Order\n6. Salir" << std::endl;
    std::cout << "Ingrese la opción deseada: \n> ";
    std::cin >> opc;
    root = tree.get_root();
    switch (opc) {
      case 1:
        std::cout << "Ingrese el número que desea ingresar: \n> ";
        std::cin >> aux;
        tree.crear_nodo(aux);
        tree.insertar(root);
        break;
      case 2:
        if(root == NULL){
          std::cout << "El árbol está vacío" << std::endl;
        } else{
          std::cout << "Ingrese el valor que desea buscar: \n> ";
          std::cin >> aux;
          naux = tree.busqueda_in_order(aux, root); 
          if(naux != NULL){
            tree.in_order(naux);
          } else {
            std::cout << "No se encontró el valor que ingresó" << std::endl;
          }
        }
        break;
      case 3:
        tree.in_order(root);
        break;
      case 4:
        tree.post_order(root);
        break;
      case 5:
        tree.pre_order(root);
        break;
      case 6:
        std::cout << "Hasta luego" << std::endl;
        break;
      default:
        std::cout << "No se ingresó un valor válido" << std::endl;
        break;
    }  
  }while (opc != 6);
}
