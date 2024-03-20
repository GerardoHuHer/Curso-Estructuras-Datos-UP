#include "Empresa.h"

Empresa::Empresa()
{
	personal[0].nom = "luis";
	personal[0].esta = 167;
	personal[0].sdo = 230.50;

	personal[1].nom = "juan";
	personal[1].esta = 182;
	personal[1].sdo = 270.50;

	personal[2].nom = "Dalia";
	personal[2].esta = 173;
	personal[2].sdo = 310.00;

	ocupados = 3;
}

Empresa::~Empresa()
{}

bool Empresa::Insertar(Empleado persona)
{
	int pos = -1;

	// Arreglo lleno, NO se inserta
	if (ocupados >= tamano)
		return false;

	// Busca posición para insertar
	for (int i = 0; i < ocupados; i++)
	{
		persona.nom[0] = toupper(persona.nom[0]);
		personal[i].nom[0] = toupper(personal[i].nom[0]);
		if (persona.nom < personal[i].nom)
		{
			pos = i;
			break;
		}
	}

	// Si encontró la posición, se desplazan los elementos, para abrir el espacio
	if (pos > -1)
	{
		for (int i = ocupados; i > pos; i--)
			personal[i] = personal[i - 1];
	}

	// Inserta al final o en la posición indicada, según sea el caso
	if (pos == -1)
		personal[ocupados] = persona;
	else
		personal[pos] = persona;

	// Incrementa el número de elementos ocupados
	ocupados++;
	return true;
}

bool Empresa::Borrar(string nombreBorrar)
{
	int pos = -1;

	// Si el arreglo está vacío, no busca y NO borra
	if (ocupados == 0)
	{
		return false;
	}

	// Busca posición del empleado a borrar
	nombreBorrar[0] = toupper(nombreBorrar[0]);
	for (int i = 0; i < ocupados; i++)
	{
		if (personal[i].nom == nombreBorrar)
		{
			pos = i;
			break;
		}
	}

	// Si encontró la persona a borrar, desplaza
	if (pos != -1)
	{
		for (int i = pos; i < ocupados; i++)
		{
			personal[i] = personal[i + 1];
			ocupados--;
			return true;
		}
	}
	// Si no encontró la persona, NO desplaza, ni borra
	else
	{
		return false;
	}
}

void Empresa::Ordenar()
{
	bool ordenado = false;
	int iteracion = 0;
	Empleado aux;

	while (!ordenado)
	{
		ordenado = true;
		for (int i = 0; i < ocupados - 1 - iteracion; i++)
		{
			personal[i].nom[0] = toupper(personal[i].nom[0]);
			if (personal[i].nom > personal[i + 1].nom)
			{
				aux = personal[i];
				personal[i] = personal[i + 1];
				personal[i + 1] = aux;
				ordenado = false;
			}
		}
		iteracion++;
	}
}

void Empresa::Mostrar()
{
	cout << "\nPersonal:" << endl;
	for (int i = 0; i < ocupados; i++)
	{
		cout << "\t" << personal[i].nom << "\t" << personal[i].esta << "\t"
			<< personal[i].sdo << endl;
	}
	cout << endl;
}
