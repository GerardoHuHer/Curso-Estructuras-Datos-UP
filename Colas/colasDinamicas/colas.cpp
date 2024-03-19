#include "colas.h"

ColaLigada::ColaLigada() { inicio = final = NULL; }

void ColaLigada::insertar(int nuevo) {
  // Paso 1: Crear nodo
  nodo = new Entero();
  // Paso 2: Colocar información
  nodo->num = nuevo;
  // Paso 3: Enlace
  nodo->sig = NULL;
  // Paso 4: Si es el primer nodo 'incio' = NULL igualar inicio y final a nodo
  if (inicio == NULL) {
    inicio = final = nodo;
  } else {
    // Paso 5: Si final != NULL final.sig = nodo
    final->sig = nodo;
    // Paso 6: final = nodo
    final = nodo;
  }
}

int ColaLigada::extraer() {
  int num;
  if ((inicio == NULL) && (final == NULL)) {
    return -1;
  }
  Entero *aux = inicio;
  nodo = inicio;
  inicio = inicio->sig;
  num = aux->num;
  delete aux;
  return num;
}

void ColaLigada::mostrar() {
  cout << "\nCOLA DE ENTEROS" << endl;
  if (inicio == NULL) {
    cout << "\n\tCola vacía" << endl;
    return;
  }
  nodo = inicio;
  cout << "\t Dirección \t Valor \t Dirección siguiente" << endl;
  while (nodo != NULL) {
    cout << "\t" << nodo << "\t" << nodo->num << "\t" << nodo->sig;
    if (nodo == inicio)
      cout << "\t <= Inicio";
    if (nodo == final)
      cout << "\t <= Final";
    cout << endl;
    nodo = nodo->sig;
  }
}

int ColaLigada::consultar(){
  if(inicio == NULL){
    return -1;
  }else{
    return inicio->num;
  }
}

void menu() {
  int opc;
  int ret;
  ColaLigada enteros = ColaLigada();
  do {
    cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Consultar \n5) Salir "
            "\nIngresa la opción deseada \n? ";
    cin >> opc;
    switch (opc) {
    case 1:
      cout << "Ingrese el número que desea insertar: \n? ";
      cin >> ret;
      enteros.insertar(ret);
      break;
    case 2:
      ret = enteros.extraer();
      if (ret == -1) {
        cout << "La cola está vacía" << endl;
      } else {
        cout << "El número extraído es: " << ret << endl;
      }
      break;
    case 3:
      enteros.mostrar();
      break;
    case 4:
      ret = enteros.consultar();
      if (ret == -1) {
        cout << "La cola está vacía" << endl;
      } else {
        cout << "El dato inicial es: " << ret << endl;
      }
      break;
    case 5:
      cout << "Hasta luego" << endl;
      break;
    default:
      cout << "Error no se ingresó una opció válida" << endl;
      break;
    }
  } while (opc != 5);
}
