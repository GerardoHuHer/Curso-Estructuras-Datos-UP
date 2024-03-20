#pragma once
#include <iostream>
#include <string>

#define tamano 8

using namespace std;

struct Empleado
{
	string nom;
	int esta;
	float sdo;
};

class Empresa
{
public:
	Empresa();
	~Empresa();
	bool Insertar(Empleado);
	bool Borrar(string);
	void Ordenar();
	void Mostrar();
private:
	Empleado personal[tamano];
	int ocupados;
};
