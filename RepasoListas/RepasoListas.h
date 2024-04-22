#ifndef REPASOLISTAS_H
#define REPASOLISTAS_H
#include <iostream>

enum Lista_option {
  Empty,
  Not_found,
  Found,
};

template <typename T> class ListaCircular {
public:
  struct Nodo {
    T dato;
    Nodo *sig;
  };
  ListaCircular() {
    final = head = NULL;
    node = NULL;
  }

  void insertar_inicio(const T &nuevo) {
    node = new Nodo;
    node->dato = nuevo;
    node->sig = head;
    if (head == NULL) {
      final = node;
    }
    final->sig = node;
    head = node;
    check = head;
  }

  void insertar_intermedio(const T &nuevo, const T &pos) {
    if (!head) {
      insertar_inicio(nuevo);
      return;
    }
    bool Found = false;
    Nodo *nodo_anterior = head;
    display_inicio();
    do {
      if (nodo_anterior->dato == pos) {
        Found = true;
        break;
      }
      nodo_anterior = nodo_anterior->sig;
    } while (nodo_anterior != head);
    if (Found) {
      node = new Nodo;
      node->dato = nuevo;
      node->sig = nodo_anterior->sig;
      nodo_anterior->sig = node;
    }
    if (!Found) {
      insertar_final(nuevo);
    }
  }

  void insertar_final(const T &nuevo) {
    if (!head) {
      insertar_inicio(nuevo);
      return;
    }
    node = new Nodo;
    node->dato = nuevo;
    node->sig = head;
    final->sig = node;
    final = node;
  }

  bool extraer_inicio() {
    if (head == NULL) {
      return false;
    }
    node = head;
    if (head == final) {
      final = NULL;
    }
    head = node->sig;
    final->sig = head;
    delete node;
    return true;
  }

  bool extraer_intermedio(const T &pos) {
    if (head == NULL) {
      return false;
    }
    if (head == final) {
      return extraer_inicio();
    }
    if (head->dato == pos) {
      return extraer_inicio();
    }

    bool Found = false;
    Nodo *node_anterior = head;

    if (check != head) {
      node_anterior = check;
    }

    do {
      if (node_anterior->sig->dato == pos) {
        Found = true;
        break;
      }
      node_anterior = node_anterior->sig;
    } while (node_anterior != check);

    if (Found) {
      Nodo *node = node_anterior->sig;
      if (node == final) {
        return extraer_final();
      }
      node_anterior->sig = node->sig;
      delete node;
      return true;
    }

    return false;
  }

  bool extraer_final() {
    if (head == NULL) {
      return false;
    }
    if (head == final) {
      return extraer_inicio();
    }
    Nodo *nodo_anterior = head;
    node = head;
    while (node != final) {
      nodo_anterior = node;
      node = node->sig;
    }
    nodo_anterior->sig = head;
    final = nodo_anterior;
    return true;
  }

  bool busqueda(const T &search) {
    if (head == NULL) {
      return false;
    }
    node = check;
    do {
      if (node->dato == search) {
        check = node;
        return true;
      }
      node = node->sig;
    } while (node != check);
    return false;
  }

  void display_inicio() {
    if (head == NULL) {
      std::cout << "-- LISTA VACÍA --" << std::endl;
      return;
    }
    node = head;
    std::cout << "-- LISTA --" << std::endl;
    do {
      std::cout << "\t" << node->dato;
      if (node == final)
        std::cout << " <= Final";
      if (node == head)
        std::cout << " <= Inicio";
      std::cout << std::endl;
      node = node->sig;
    } while (node != head);
  }

  void display_check() {
    if (head == NULL) {
      std::cout << "-- LISTA VACÍA --" << std::endl;
      return;
    }
    node = check;
    std::cout << "-- LISTA --" << std::endl;
    do {
      std::cout << "\t" << node->dato;
      if (node == final)
        std::cout << " <= Final";
      if (node == head)
        std::cout << " <= Inicio";
      if (node == check)
        std::cout << " <= Revisado";
      std::cout << std::endl;
      node = node->sig;
    } while (node != check);
  }

private:
  Nodo *head, *final;
  Nodo *check;
  Nodo *node;
};

template <typename T> class Lista {
public:
  struct Nodo {
    T dato;
    Nodo *sig;
  };
  Lista() : head(NULL), final(NULL), nodo(NULL) {}
  void insertar_inicio(const T &nuevo) {
    nodo = new Nodo;
    nodo->dato = nuevo;
    nodo->sig = head;
    head = nodo;
    if (final == NULL) {
      final = nodo;
    }
  }

  void insertar_intermedio(const T &nuevo, const T &pos) {
    if (head == NULL) {
      insertar_inicio(nuevo);
      return;
    }
    if(head->dato == pos){
      insertar_inicio(nuevo);
      return;
    }
    if (pos == final->dato) {
      insertar_final(nuevo);
      return;
    }
    Nodo *nodo_anterior = head;
    while (nodo_anterior != NULL) {
      if (nodo_anterior->dato == pos) {
        nodo = new Nodo;
        nodo->dato = nuevo;
        nodo->sig = nodo_anterior->sig;
        nodo_anterior->sig = nodo;
        return;
      }
      nodo_anterior = nodo_anterior->sig;
    }
    insertar_final(nuevo);
  }

  void insertar_final(const T &nuevo) {
    if (head == NULL) {
      insertar_inicio(nuevo);
    }
    nodo = new Nodo;
    nodo->dato = nuevo;
    nodo->sig = NULL;
    final->sig = nodo;
    final = nodo;
  }

  Lista_option extraer_inicio() {
    if (head == NULL) {
      return Lista_option::Empty;
    }
    nodo = head;
    head = nodo->sig;
    delete nodo;
    return Lista_option::Found;
  }

  Lista_option extraer_intermedio(const T &pos) {
    if (head == NULL) {
      return Lista_option::Empty;
    }
    if (head->dato == pos) {
      return extraer_inicio();
    }
    if (final->dato == pos) {
      return extraer_final();
    }
    Nodo *nodo_anterior = head;
    while (nodo_anterior != final) {
      if (nodo_anterior->sig->dato == pos) {
        nodo = nodo_anterior->sig;
        nodo_anterior->sig = nodo->sig;
        delete nodo;
        return Lista_option::Found;
      }
      nodo_anterior = nodo_anterior->sig;
    }
    return Lista_option::Not_found;
  }

  Lista_option extraer_final() {
    if (head == NULL) {
      return Lista_option::Empty;
    }
    if (head == final) {
      return extraer_inicio();
    }
    Nodo *nodo_anterior = head;
    bool find{false};
    while (nodo_anterior != final) {
      if (nodo_anterior->sig == final) {
        nodo = nodo_anterior->sig;
        nodo_anterior->sig = NULL;
        final = nodo_anterior;
        delete nodo;
        return Lista_option::Found;
      }
      nodo_anterior = nodo_anterior->sig;
    }
  }

  Lista_option busqueda(const T &search) {
    if (head == NULL) {
      return Lista_option::Empty;
    }
    nodo = head;
    while (nodo != NULL) {
      if (nodo->dato == search) {
        return Lista_option::Found;
      }
      nodo = nodo->sig;
    }
    return Lista_option::Not_found;
  }

  void display() {
    if (head == NULL) {
      std::cout << "-- LISTA VACÍA --" << std::endl;
      return;
    }
    nodo = head;
    std::cout << "-- LISTA --" << std::endl;
    while (nodo != NULL) {
      std::cout << "\t" << nodo->dato;
      if (nodo == final)
        std::cout << " <= Final";
      if (nodo == head)
        std::cout << " <= Inicio";
      std::cout << std::endl;
      nodo = nodo->sig;
    }
  }

private:
  Nodo *head, *final;
  Nodo *nodo;
};

enum Option {
  Insertar_inicio = 1,
  Insertar_intermedio,
  Insertar_final,
  Extraer_inicio,
  Extraer_intermedio,
  Extraer_final,
  Mostrar_inicio,
  Mostrar_check,
  Busqueda,
  Salir
};

enum Option_menu {
  Insertar_Inicio = 1,
  Insertar_Intermedio,
  Insertar_Final,
  Extraer_Inicio,
  Extraer_Intermedio,
  Extraer_Final,
  Buscar,
  Mostrar,
  Exit
};

Option_menu menu_enter_option();
Option enter_option();

void menu_listaC();
void menu_lista();

enum Menu_prin { Normales = 1, Circulares, Terminar };

Menu_prin enter_option_princ();

void run();

#endif
