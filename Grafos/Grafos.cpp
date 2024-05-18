#include "Grafos.h"
MatrizAdy::MatrizAdy(int tam) {
  max_nodos = tam;
  ocupados = 0;
  pos_destino = pos_origen = -1;
  nodos = new char[tam];  // Arreglo de nodos
  arcos = new int *[tam]; // Renglones del arreglo de arcos
  for (int i = 0; i < tam; i++) {
    arcos[i] = new int[tam]; // Columnas de cada renglón de arcos
  }
  for (int i = 0; i < tam; i++) {
    nodos[i] = '='; // Inicialización de arreglo de nodos
  }
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      arcos[i][j] = -1; // Inicializando arreglo de arcos
    }
  }
}
int MatrizAdy::insertar_nodo(char nom) {
  if (max_nodos == ocupados) {
    return -1; // Código de error, arreglo lleno;
  }
  if (buscar_nodo(nom) != -1) {
    return -2; // The node already exists
  }
  nodos[ocupados] = nom;
  ocupados++;
  return 0;
}
int MatrizAdy::insertar_ady(char ori, char des, int peso) {
  if (ocupados == 0) {
    return -1;
  }
  pos_origen = buscar_nodo(ori);
  pos_destino = buscar_nodo(des);
  if (pos_origen == -1 || pos_destino == -1) {
    return -2;
  }
  if (arcos[pos_origen][pos_destino] != -1) {

    arcos[pos_origen][pos_destino] = peso;
    arcos[pos_destino][pos_origen] = peso;
    return -3;
  } else{
    
    arcos[pos_origen][pos_destino] = peso;
    arcos[pos_destino][pos_origen] = peso;
  }
}
void MatrizAdy::mostrar() {
  if (ocupados == 0) {

    std::cout << "\t\nGrafo vacío" << std::endl;
  }
  std::cout << "\nMatriz de Adyacencias" << std::endl;
  std::cout << "\t\n";
  std::cout << "\t";
  for (int i = 0; i < max_nodos; i++) {
    std::cout << "\t" << nodos[i];
  }
  std::cout << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < max_nodos; i++) {
    std::cout << "\t" << nodos[i];
    for (int j = 0; j < max_nodos; j++) {
      if (arcos[i][j] != -1) {
        std::cout << "\t" << arcos[i][j];
      } else {
        std::cout << "\t-";
      }
    }
    std::cout << std::endl;
  }
}

int MatrizAdy::buscar_nodo(char nom) {
  if (ocupados == 0) {
    return -1; // vacio
  }
  for (int i = 0; i < ocupados; i++) {
    if (nodos[i] == nom) {
      return i;
    }
  }
  return -1;
}
