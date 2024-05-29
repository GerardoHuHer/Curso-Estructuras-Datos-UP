#include "ListaAdy.h"

ListaAdy::ListaAdy()
{
	inicio = NULL;
}
int ListaAdy::InsertarNod(char nom)
{
	int existe;
	Nod* posicNod;

	nodo = new Nod;		// Se crea el nodo nuevo
	nodo->nom = nom;
	nodo->sigNod = NULL;
	nodo->sigAdy = NULL;

	if (!inicio)
	{
		inicio = nodo;		// Grafo Vacío. Se inserta el nodo
		return 0;
	}

	existe = LocalizarNod(nom, posicNod);
	if (existe == -1)	// No existe el nodo
	{
		posicNod->sigNod = nodo;	// Se inserta al final de la lista
		return 0;
	}
	else
		delete nodo;	// YA existe el nodo. No se inserta. Se destruye.

	return -1;
}
int ListaAdy::InsertarAdy(char ori, char des, int peso)
{
	Nod* posicOri, * posicDes;
	Ady* posicAdy;
	int existeOri, existeDes, existeAdy;

	adya = new Ady;			// Se crea la adyacencia
	adya->nom = des;
	adya->peso = peso;
	adya->sigAdy = NULL;


	if (!inicio)	// Grafo vacío. No se inserta el arco
		return -1;

	existeOri = LocalizarNod(ori, posicOri);
	existeDes = LocalizarNod(des, posicDes);

	if (existeOri == -1 || existeDes == -1)	// No existe Orig o Dest. NO se inserta
		return -1;

	if (!posicOri->sigAdy)	// No existe ninguna Adyad en el nodo Orig. Se inserta
	{
		posicOri->sigAdy = adya;
		adya->dirNod = posicDes;
		return 0;
	}

	existeAdy = LocalizarAdy(posicOri, des, posicAdy);

	if (existeAdy == 0)		// YA existe la adyacencia. NO se inserta
		return -2;

	posicAdy->sigAdy = adya;	// NO existe la adyac. Se inserta al final de la lista
	adya->dirNod = posicDes;

	return 0;		// Se insertó la adyacencia
}
int ListaAdy::LocalizarNod(char nom, Nod*& posicNod)
{
	if (!inicio)
		return -1;	// Grafo Vacío. No existe el nodo

	auxNod = inicio;
	do
	{
		posicNod = auxNod;
		if (auxNod->nom == nom)		// Se encontró el nodo
			return 0;
		auxNod = auxNod->sigNod;
	} while (auxNod);

	return -1;		// No existe el nodo
}
int ListaAdy::LocalizarAdy(Nod* ori, char des, Ady*& posicAdy)
{
//	posicAdy = NULL;
	auxAdy = ori->sigAdy;
	if (auxAdy == NULL)
		return -1;
	do
	{
		posicAdy = auxAdy;
		if (auxAdy->nom == des)		// Ya existe la adyacencia
			return 0;
		auxAdy = auxAdy->sigAdy;
	} while (auxAdy);

	return -1;		// No existe la adyacencia
}
void ListaAdy::Mostrar()
{
	if (!inicio)
	{
		cout << "\n\t-- El Grafo está VACÍO --" << endl;
		return;
	}
	cout << "\nLISTA DE NODOS:" << endl;
	cout << "\t";

	auxNod = inicio;
	do
	{
		cout << auxNod->nom << " -> ";
		auxNod = auxNod->sigNod;
	} while (auxNod);
	cout << "null" << endl;

	cout << "\nLISTA DE ADYACENCIAS:" << endl;

	auxNod = inicio;
	do
	{
		cout << "\t" << auxNod->nom << " => ";
		auxAdy = auxNod->sigAdy;
		while (auxAdy)
		{
			cout << auxAdy->nom << "-" << auxAdy->peso << " -> ";
			auxAdy = auxAdy->sigAdy;
		}
		cout << "null" << endl;

		auxNod = auxNod->sigNod;
	} while (auxNod);
}
