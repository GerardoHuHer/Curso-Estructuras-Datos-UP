#ifndef GRAFO_H
#define GRAFO_H
#include "main.h"

struct Nod;

struct Ady{
  char nom;
  int peso;
  Ady* sigAdy;
  Nod* dirNod;
};

struct Nod{
  char nom;
  Nod* sigNod;
  Ady* sigAdy;
};

class ListaAdy{
  public:
    ListaAdy();
    int insertarNod(char nom);
    int insertaAdy(char ori, char des, int peso);
    int localizarNod(char nom, Nod*& posNod);
    int localizarAdy(Nod* ori, char des, Ady*& posAdy);
    void mostrar();
  private:
    Nod* nodo, *inicio, *auxNod;
    Ady* adya, *auxAdy;
};

#endif
