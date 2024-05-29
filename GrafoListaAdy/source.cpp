#include "ListaAdy.h"

int main() {
  setlocale(LC_ALL, "");

  int opc, peso, codigo;
  char nodo, ori, des;

  ListaAdy grafo;

  do {
    cout << "\n1 Insertar Nodo   2 Insertar Arco   3 Mostrar   4 Salir: ";
    cin >> opc;
    switch (opc) {
    case 1:
      cout << "\tNombre del nodo (una letra): ";
      cin >> nodo;
      codigo = grafo.InsertarNod(nodo);
      if (codigo == 0)
        cout << "\tOK. Se insertó el nodo" << endl;
      if (codigo == -1)
        cout << "\t**ERROR, YA existe el nodo. NO se insertó" << endl;
      break;
    case 2:
      cout << "\tNodo origen (una letra): ";
      cin >> ori;
      cout << "\tNodo destino (una letra): ";
      cin >> des;
      cout << "\tPeso del Arco: ";
      cin >> peso;
      codigo = grafo.InsertarAdy(ori, des, peso);
      if (codigo == 0)
        cout << "\tOK. Se insertó el Arco Ori-Dest" << endl;
      if (codigo == -1)
        cout << "\t**ERROR, NO existe el nodo de origen o el de destino"
             << endl;
      if (codigo == -2)
        cout << "\t**ERROR, YA existe el Arco. NO se insertó" << endl;

      codigo = grafo.InsertarAdy(des, ori, peso);
      if (codigo == 0)
        cout << "\tOK. Se insertó el Arco Dest-ori" << endl;
      if (codigo == -1)
        cout << "\t**ERROR, NO existe el nodo de origen o el de destino"
             << endl;
      if (codigo == -2)
        cout << "\t**ERROR, YA existe el Arco. NO se insertó" << endl;
      break;
    case 3:
      grafo.Mostrar();
      break;
    default:
      break;
    }
  } while (opc < 4);
}
