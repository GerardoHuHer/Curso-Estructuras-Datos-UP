#ifndef LISTAADY_H
#define LISTAADY_H
#include <iostream>

using namespace std;

struct Nod;

struct Ady
{
	char nom;
	int peso;
	Ady* sigAdy;
	Nod* dirNod;
};
struct Nod
{
	char nom;
	Nod* sigNod;
	Ady* sigAdy;
};
class ListaAdy
{
public:
	ListaAdy();
	int InsertarNod(char nom);
	int InsertarAdy(char ori, char des, int peso);
	int LocalizarNod(char nom, Nod*& posicNod);
	int LocalizarAdy(Nod* ori, char des, Ady*& posicAdy);
	void Mostrar();
private:
	Nod* nodo, * inicio, * auxNod;
	Ady* adya, * auxAdy;
};



#endif
