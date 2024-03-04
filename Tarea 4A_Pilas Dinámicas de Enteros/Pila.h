#pragma once
#include <iostream>
using namespace std;

struct Entero
{
	int dato;
	Entero* anterior;
};

class Pila
{
public:
	Pila();
	int Consultar();
	int Extraer();
	void Insertar(int);
	void Mostrar();
private:
	Entero* tope, * nodo;
};

