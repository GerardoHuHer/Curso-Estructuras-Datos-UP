#ifndef REPASO_H
#define REPASO_H
#include <iostream>
#include <string>

// ####################################### Arbol

enum Option { Insertar = 1, Buscar, In_o, Pre_o, Post_o, Salir };
enum OptionGrafo {InsertarN = 1, InsertarA, Mostrar, SalirG };

struct Nodo {
  int data;
  Nodo *izq, *der;
};

class Arbol {
private:
  Nodo *root, *nodo;

public:
  Arbol();
  void crear_nodo(const int &);
  Nodo *get_root() const;
  void insertar(Nodo *);
  Nodo *busqueda(const int &, Nodo *);
  void in_order(Nodo *);
  void pre_order(Nodo *);
  void post_order(Nodo *);
  void display(Nodo *, int);
};

struct Persona {
  std::string nombre;
  int edad;
  bool operator==(Persona &persona1);
  bool operator!=(Persona &persona1);
  bool operator<=(Persona &persona1);
  bool operator>=(Persona &persona1);
  bool operator>(Persona &persona1);
  bool operator<(Persona &persona1);
  friend std::ostream& operator<<(std::ostream&, Persona&);
  friend std::istream& operator>>(std::istream&, Persona&);
};

// ######################################## GRAFO

struct Node;

struct Ady {
  Persona persona;
  int peso;
  Ady *sigAdy;
  Node *dirNod;
};

struct Node {
  Persona persona;
  Node *sigNod;
  Ady *sigAdy;
};

class ListaAdy {
public:
  ListaAdy();
  int insertarNod(Persona nom);
  int insertarAdy(Persona ori, Persona des, int peso);
  int localizarNod(Persona nom, Node *&posicNod);
  int localizarAdy(Node *ori, Persona des, Ady *&posicAdy);
  void mostrar();

private:
  Node *nodo, *inicio, *auxNod;
  Ady *adya, *auxAdy;
};

Option get_option();
OptionGrafo get_optionGrafo();
void menu();
void menuGrafo();

#endif
