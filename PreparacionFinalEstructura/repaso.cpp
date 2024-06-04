#include "repaso.h"

// ################################# Arbol
Option get_option() {
  int opc;
  std::cout << "\n1. Insertar \n2. Buscar \n3. Imprimir In-Order \n4. Imprimir "
               "Pre-Order\n5. Imprimir Post-Order \n6. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada: \n> ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

Arbol::Arbol() : nodo(NULL), root(NULL){};

void Arbol::crear_nodo(const int &value) {
  nodo = new Nodo;
  nodo->data = value;
  nodo->der = NULL;
  nodo->izq = NULL;
}

Nodo *Arbol::get_root() const { return root; }

void Arbol::insertar(Nodo *pos) {
  if (root == NULL) {
    root = nodo;
    return;
  }
  if (nodo->data < pos->data) {
    if (pos->izq == NULL) {
      pos->izq = nodo;
      return;
    } else {
      insertar(pos->izq);
      return;
    }
  }
  if (nodo->data > pos->data) {
    if (pos->der == NULL) {
      pos->der = nodo;
      return;
    } else {
      insertar(pos->der);
      return;
    }
  }
  delete nodo;
  return;
}

Nodo *Arbol::busqueda(const int &value, Nodo *pos) {
  if (value == pos->data) {
    return pos;
  }
  if (value < pos->data) {
    if (pos->izq == NULL) {
      return NULL;
    } else {
      return busqueda(value, pos->izq);
    }
  }
  if (value > pos->data) {
    if (pos->der == NULL) {
      return NULL;
    } else {
      return busqueda(value, pos->der);
    }
  }
  return NULL;
}

void Arbol::in_order(Nodo *pos) {
  if (pos->izq != NULL) {
    in_order(pos->izq);
  }
  std::cout << "\t" << pos->data;
  if (pos->der != NULL) {
    in_order(pos->der);
  }
}

void Arbol::pre_order(Nodo *pos) {
  std::cout << "\t" << pos->data;
  if (pos->izq != NULL) {
    pre_order(pos->izq);
  }
  if (pos->der != NULL) {
    pre_order(pos->der);
  }
}

void Arbol::post_order(Nodo *pos) {
  if (pos->izq != NULL) {
    post_order(pos->izq);
  }
  if (pos->der != NULL) {
    post_order(pos->der);
  }
  std::cout << "\t" << pos->data;
}

void Arbol::display(Nodo *pos, int cont) {
  if (pos == NULL) {
    return;
  }
  display(pos->der, cont + 1);
  for (int i = 0; i < cont; i++) {
    std::cout << "\t";
  }
  std::cout << pos->data << std::endl;
  display(pos->izq, cont + 1);
}

void menu() {
  Option opc;
  int aux;
  Nodo *root, *naux;
  Arbol tree = Arbol();
  while ((opc = get_option()) != Salir) {
    root = tree.get_root();
    switch (opc) {
    case Insertar:
      std::cout << "Ingresa el valor que deseas: \n> ";
      std::cin >> aux;
      tree.crear_nodo(aux);
      tree.insertar(root);
      break;
    case Buscar:
      if (root == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        std::cout << "Ingresa el valor que deseas buscar: \n> ";
        std::cin >> aux;
        naux = tree.busqueda(aux, root);
        if (naux == NULL) {
          std::cout << "No se encontró el valor en el árbol" << std::endl;
        } else {
          std::cout << "El valor " << naux->data
                    << " se encontró y impreso in-order a partir de él es:"
                    << std::endl;
          tree.in_order(naux);
        }
      }
      break;
    case In_o:
      if (root == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.in_order(root);
      }
      break;
    case Pre_o:
      if (root == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.pre_order(root);
      }
      break;
    case Post_o:
      if (root == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.post_order(root);
      }
      break;
    case Salir:
      break;
    default:
      std::cout << "No se ingresó un valor válido " << std::endl;
      break;
    }
  }
}

// ############################ Grafo

OptionGrafo get_optionGrafo() {
  int opc;
  std::cout << "\n1. Insertar Nodo \n2. Insertar Arco \n3. Mostrar \n4. Salir "
            << std::endl;
  std::cout << "Inserte la opción deseada: \n> ";
  std::cin >> opc;
  return static_cast<OptionGrafo>(opc);
}

bool Persona::operator==(Persona &aux) { return this->nombre == aux.nombre; }
bool Persona::operator!=(Persona &aux) { return this->nombre != aux.nombre; }
bool Persona::operator<=(Persona &aux) { return this->nombre <= aux.nombre; }
bool Persona::operator>=(Persona &aux) { return this->nombre >= aux.nombre; }
bool Persona::operator<(Persona &aux) { return this->nombre < aux.nombre; }
bool Persona::operator>(Persona &aux) { return this->nombre > aux.nombre; }

std::ostream &operator<<(std::ostream &os, Persona &per) {
  std::cout << "Nombre: " << per.nombre << " ";
  std::cout << "Edad: " << per.edad;
  return os;
}

std::istream &operator>>(std::istream &is, Persona &per) {
  std::cout << "Ingrese su nombre: \n> ";
  std::cin >> per.nombre;
  std::cout << "Ingrese su edad: \n> ";
  std::cin >> per.edad;
  return is;
}

ListaAdy::ListaAdy() : inicio(NULL) {}

int ListaAdy::insertarNod(Persona nom) {
  int existe;
  Node *posicNod;

  nodo = new Node;
  nodo->persona = nom;
  nodo->sigAdy = NULL;
  nodo->sigNod = NULL;

  if (!inicio) {
    inicio = nodo;
    return 0;
  }

  existe = localizarNod(nom, posicNod);
  if (existe == -1) {
    posicNod->sigNod = nodo;
    return 0;
  } else {
    delete nodo;
  }
  return -1;
}

int ListaAdy::insertarAdy(Persona ori, Persona des, int peso) {
  Node *posicOri, *posicDes;
  Ady *posicAdy;
  int existeOri, existeDes, existeAdy;

  adya = new Ady;
  adya->persona = des;
  adya->peso = peso;
  adya->sigAdy = NULL;

  if (!inicio) {
    return -1;
  }

  existeOri = localizarNod(ori, posicOri);
  existeDes = localizarNod(des, posicDes);

  if (existeOri == -1 || existeDes == -1) {
    return -1;
  }

  if (!posicOri->sigAdy) {
    posicOri->sigAdy = adya;
    adya->dirNod = posicDes;
    return 0;
  }

  existeAdy = localizarAdy(posicOri, des, posicAdy);
  if (existeAdy == 0) {
    return -2;
  }

  posicAdy->sigAdy = adya;
  adya->dirNod = posicDes;
  return 0;
}

int ListaAdy::localizarNod(Persona nom, Node *&posicNod) {
  if (!inicio) {
    return -1;
  }
  auxNod = inicio;
  do {
    posicNod = auxNod;
    if (auxNod->persona == nom) {
      return 0;
    }
    auxNod = auxNod->sigNod;
  } while (auxNod);
  return -1;
}

int ListaAdy::localizarAdy(Node *ori, Persona des, Ady *&posicAdy) {
  auxAdy = ori->sigAdy;
  if (auxAdy == NULL) {
    return -1;
  }
  do {
    posicAdy = auxAdy;
    if (auxAdy->persona == des) {
      return 0;
    }
    auxAdy = auxAdy->sigAdy;
  } while (auxAdy);
  return -1;
}

void ListaAdy::mostrar() {
  if (!inicio) {
    std::cout << "\n\t-- El Grafo está vacío --" << std::endl;
    return;
  }
  std::cout << "\nLista de nodos: " << std::endl;
  std::cout << "\t";
  auxNod = inicio;
  do {
    std::cout << auxNod->persona << " ->";
    auxNod = auxNod->sigNod;
  } while (auxNod);
  std::cout << "null" << std::endl;
  std::cout << "\nLista de adyacencias: " << std::endl;

  auxNod = inicio;
  do {
    std::cout << "\t" << auxNod->persona << " => ";
    auxAdy = auxNod->sigAdy;
    while (auxAdy) {
      std::cout << auxAdy->persona << "-" << auxAdy->peso << " ->";
      auxAdy = auxAdy->sigAdy;
    }
    std::cout << "null" << std::endl;
    auxNod = auxNod->sigNod;
  } while (auxNod);
}

void menuGrafo() {
  OptionGrafo opc;
  int peso, codigo;
  Persona nodo, ori, des;
  ListaAdy grafo;
  do {
    opc = get_optionGrafo();
    switch (opc) {
    case InsertarN:
      std::cout << "\tInserte su persona: \n> ";
      std::cin >> nodo;
      codigo = grafo.insertarNod(nodo);
      if (codigo == 0) {
        std::cout << "\tSe insertó el nodo" << std::endl;
      }
      if (codigo == -1) {
        std::cout << "\tError el nodo ya existe" << std::endl;
      }
      break;
    case InsertarA:
      std::cout << "\tNodo Origen: \n> ";
      std::cin >> ori;
      std::cout << "\tNodo Destino: \n> ";
      std::cin >> des;
      std::cout << "\tPeso del arco: \n> ";
      std::cin >> peso;
      codigo = grafo.insertarAdy(ori, des, peso);
      if (codigo == 0) {
        std::cout << "Se insertó el arco ori-dest" << std::endl;
      }
      if (codigo == -1) {
        std::cout << "\tError, no existe el nodo destino o el nodo de origen"
                  << std::endl;
      }
      if (codigo == -2) {
        std::cout << "\tError, ya existe el arco" << std::endl;
      }
      codigo = grafo.insertarAdy(des, ori, peso);
      if (codigo == 0) {
        std::cout << "Se insertó el arco ori-dest" << std::endl;
      }
      if (codigo == -1) {
        std::cout << "\tError, no existe el nodo destino o el nodo de origen"
                  << std::endl;
      }
      if (codigo == -2) {
        std::cout << "\tError, ya existe el arco" << std::endl;
      }
      break;
    case Mostrar:
      grafo.mostrar();
      break;
    case SalirG:
      std::cout << "Hasta luego";
      break;
    default:
      std::cout << "El valor ingresado no es válido" << std::endl;
      break;
    }
  } while (opc != SalirG);
}
