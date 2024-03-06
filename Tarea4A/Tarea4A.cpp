#include "Tarea4A.h"

Pila::Pila() { tope = NULL; }

void Pila::Insertar(int nuevo) {
  // Paso 1: Crear nodo
  nodo = new Entero;
  // Paso 2: Registrar la info
  nodo->dato = nuevo;
  // Paso 3: Enlace
  nodo->anterior = tope;
  // Paso 4: Cambiar tope
  tope = nodo;
}

int Pila::Extraer() {
  Entero *aux;
  int num;
  // Paso 1: Verificar que haya valores en la Pila
  if (tope == NULL)
    return -1;
  // Paso 2: Extraer la info del tope
  aux = tope;
  // Paso 3: Descender el tope
  tope = tope->anterior;
  // Paso 4: Entragar los datos
  num = aux->dato;
  delete aux;
  return num;
}

void Pila::Mostrar() {
  if (tope == NULL)
    return;
  Entero *nodo = tope;
  while (nodo != NULL) {
    std::cout << "\t" << nodo->dato;
    if (tope == nodo)
      std::cout << " <= tope";
    std::cout << std::endl;
    nodo = nodo->anterior;
  }
  delete nodo;
}

void depurar(Pila ori, Pila dep) {
  int num;
  int ret;
  std::cout << "Ingrese un número \n? ";
  std::cin >> num;
  while (ori.tope != NULL) {
    ret = ori.Extraer();
    if (ret > num)
      dep.Insertar(ret);
    continue;
  }
  dep.Mostrar();
}

void menu() {
  int opc;
  int ingreso;
  int ret;
  Pila ori, depurada;
  while (opc != 6) {
    std::cout
        << "\n1) Insertar Original \n2) Eliminar Original \n3) Mostrar "
           "Original \n4) Depurar Original \n5) Mostrar Depurada \n6) Salir"
        << std::endl;
    std::cout << "Ingrese la opción deseada: \n? ";
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese el número que desea insertar: \n? ";
      std::cin >> ingreso;
      ori.Insertar(ingreso);
      break;
    case 2:
      ret = ori.Extraer();
      if (ret == -1)
        std::cout << "La pila está vacia" << std::endl;
      if (ret != -1)
        std::cout << "Se ha eliminado el elemento" << ret << std::endl;
      break;
    case 3:
      ori.Mostrar();
      break;
    case 4:
      std::cout << "Ingrese un número: \n? ";
      std::cin >> ingreso;
      depurar(ori, depurada);
      break;
    case 5:
      depurada.Mostrar();
      break;
    case 6:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ha ingresado una opción válida" << std::endl;
      break;
    }
  }
}
