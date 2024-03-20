#include "Empresa.h"

int main()
{
	setlocale(LC_ALL, "");

	Empresa Servicios;
	int opcion;
	Empleado persona;
	string aBorrar;

	bool respuesta;
	bool ordenado = false;

	do
	{
		cout << "\n 1 Insertar   2 Borrar   3 Ordenar   4 Mostrar   5 Salir: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			if (ordenado)
			{
				cout << "\n\tNombre: ";
				cin >> persona.nom;
				cout << "\tEstatura en cms: ";
				cin >> persona.esta;
				cout << "\tSueldo: ";
				cin >> persona.sdo;

				respuesta = Servicios.Insertar(persona);
			}
			else
			{
				cout << "\n\t%AVISO. Es necesario ordenar previamente el arreglo" << endl;
				break;
			}
			if (respuesta)
				cout << "\n\tOK. Se insert� la persona" << endl;
			else
				cout << "\n\t%ERROR, arreglo lleno. NO se insert� la persona" << endl;
			break;
		case 2:

			cout << "\n\tNombre que borrar�s: ";
			cin >> aBorrar;
			respuesta = Servicios.Borrar(aBorrar);
			if (respuesta)
				cout << "\n\tOK. Se borr� la persona" << endl;
			else
				cout << "\n\t%ERROR, no se encontr� la persona. NO se borr�" << endl;
			break;
		case 3:
			Servicios.Ordenar();
			cout << "\n\tOK. Se orden� el arreglo" << endl;
			ordenado = true;
			break;
		case 4:
			Servicios.Mostrar();
			break;
		case 5:
			cout << "\n\n\t\t\tFINAL DE LA APLICACI�N\n\n" << endl;
			break;
		default:
			cout << "\n\tERROR, opci�n Inv�lida" << endl;
			break;
		}
	} while (opcion != 5);
	return 0;
}
