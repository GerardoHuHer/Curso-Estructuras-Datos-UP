#include "Tarea8.h"

Lista::Lista() {
  cabecera = final = NULL;
  numNodos = 0;
}


void Lista::insertar_inicio(const string& valor) {
  Nodo *nuevoNodo = new Nodo;
  if (!cabecera) {
    cabecera = final = nuevoNodo;
    nuevoNodo->sig = nuevoNodo;

  } else {
    nuevoNodo->sig = cabecera;
    cabecera = nuevoNodo;
    final->sig = cabecera;
  }
  numNodos += 1;
}

void Lista::insertar_final(const string& valor) {
  Nodo *nuevoNodo = new Nodo{valor};
  if (!cabecera) {
    cabecera = final = nuevoNodo;
    nuevoNodo->sig = nuevoNodo;

  } else {
    nuevoNodo->sig = cabecera;
    final->sig = nuevoNodo;
    final = nuevoNodo;
  }
  numNodos += 1;
}

string Lista::extraer_pos(const int& numeroDesdeCabecera) {
  string datoADevolver;
  if (cabecera == NULL || numNodos - 1 < numeroDesdeCabecera) {
    return "-1";
  }
  if (numNodos == 1) {
    datoADevolver = cabecera->dato;
    delete cabecera;
    cabecera = final = NULL;
    numNodos -= 1;
    return datoADevolver;
  }

  Nodo *nodo, *nodoPrevio;
  nodo = cabecera;
  nodoPrevio = final;
  int indice = 0;       
  datoADevolver = "-1"; 
  bool seEncontroDato = false;
  do {
    if (indice == numeroDesdeCabecera) {
      datoADevolver = nodo->dato;
      seEncontroDato = true;

      nodoPrevio->sig = nodo->sig;
      delete nodo;
      numNodos -= 1;
      if (numNodos == 0)
        nodo = nodoPrevio = NULL;
      else
        nodo = nodoPrevio->sig;
    } else {

      nodoPrevio = nodoPrevio->sig;
      nodo = nodo->sig;
      indice = +1;
    }
  } while (nodo != cabecera && !seEncontroDato);

  return datoADevolver;
}

bool Lista::extraer_impares() {
  if (cabecera == NULL) {
    return false;
  }

  if (numNodos == 1) {
    extraer_pos(0);
    return true;
  }
  Nodo *nodoPrevio;
  nodo = cabecera;
  nodoPrevio = final;
  bool impar = true;
  bool cambiar_cabecera = false;
  bool cambiar_final = false;
  do {
    if (impar) {
      cambiar_cabecera = cambiar_final = false;
      if (cabecera == nodo)
        cambiar_cabecera = true;
      if (final == nodo)
        cambiar_final = true;

      nodoPrevio->sig = nodo->sig;
      delete nodo;
      numNodos -= 1;
      if (numNodos == 0)
        nodo = nodoPrevio = NULL;
      else
        nodo = nodoPrevio->sig;

      if (cambiar_cabecera)
        cabecera = nodo;
      if (cambiar_final)
        final = nodoPrevio;

      if (numNodos == 1)
        break;

    } else {
      nodoPrevio = nodoPrevio->sig;
      nodo = nodo->sig;
    }
    impar = !impar;
  } while (nodo != cabecera || cambiar_cabecera);
  return true;
}

void Lista::display() {
  cout << "\tLista tamaño " << numNodos << ":" << endl;
  if (cabecera == NULL) {
    cout << "\t*LISTA VACÍA*" << endl << endl;
    return;
  }

  nodo = cabecera;
  int indice = 0;
  do {
    mostrar_valor(nodo->dato, indice);
    if (nodo == cabecera)
      cout << "\t <= Inicio";
    if (nodo == final)
      cout << "\t <= Final";
    cout << "\n";
    nodo = nodo->sig;
    indice += 1;
  } while (nodo != cabecera);
}

int Lista::getSize() { 
  return numNodos;
}

void mostrar_valor(const string& valor, const int& indice) {
  cout << "\nPalabra[" << indice + 1 << "]: " << valor;
}

void menu() {
  Lista lista = Lista();
  int opc, nodos;
  string ret;
  bool fin;

  do {
    cout << "1. Insertar nombre\n"
         << "2. Mostrar número de nodos de lista\n"
         << "3. Extraer 1 vez nodos impares\n"
         << "4. Extraer nodos impares hasta vaciar lista\n"
         << "5. Mostrar lista\n"
         << "6. Salir\n ? ";
    cin >> opc;
    cout << endl;

    switch (opc) {

    case 1:
      cout << "\nEscribe el nombre a insertar:\n> ";
      cin >> ret;
      cout << endl;
      lista.insertar_inicio(ret);
      break;

    case 2: 
      nodos = lista.getSize();
      cout << "\nLa lista tiene " << nodos << " nodos.\n\n";
      break;

    case 3: 
      fin = lista.extraer_impares();
      if (fin == true) 
      {
        cout << "\tSe extrajeron los impares exitosamente" << endl;
        lista.display();
      } else
        cout << "\tNo se extrajeron, lista vacía" << endl;
      break;

    case 4:
      cout << "\tLista inicial:" << endl;
      lista.display();
      do {
        fin = lista.extraer_impares();
        if (fin == true) {
          cout << "\tSe extrajeron los impares exitosamente" << endl;
          lista.display();
        }
      } while (fin == true);
      cout << "\tSe terminaron de extraer impares, lista vacía" << endl;
      break;
    case 5: 
      lista.display();
      break;
    default:
      cout << "No se ingresó una opción válida" << endl;
      break;
    }
  } while (opc != 6);
}
