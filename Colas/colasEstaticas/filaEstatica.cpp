#include "filaEstatica.h"

Colas::Colas() {
  minimo = 0;
  maximo = TAM - 1;
  for (int i = 0; i < TAM; i++)
    cola[i] = 0;

  principio = final = -1;
}

void Colas::mostrar() {
  if ((principio == -1) || (final == -1)) {
    std::cout << "Cola vacía" << std::endl;
    return;
  };
  for (int i = 0; i < TAM; i++) {
    std::cout << "\t" << cola[i];
    if (i == principio)
      std::cout << " <= Principio";
    if (i == final)
      std::cout << " <= Final";
    if (i == maximo)
      std::cout << " <= Máximo";
    if (i == minimo)
      std::cout << " <= Mínimo";
    std::cout << std::endl;
  }
}

int Colas::insertar(int num){
  if(maximo == final){
    return -1;
  }
  final++;
  if(principio == -1){
    principio++;
  }
  cola[final] = num;
   return 0;
}

int Colas::extrar(){
  int extraido;
  if(final < minimo && principio < minimo ){
    return -1;
  }
  if(principio > final) return -2;
  extraido = cola[principio];
  cola[principio] = 0;
  principio++;
  return 0;
}

void menu() {
  Colas enteros;
  int opc;
  int ret;
  do {
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir \n" << std::endl;
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese el número que desea insertar a la cola: \n? ";
      std::cin >> ret;
      ret = enteros.insertar(ret);
      if(ret == -1) std::cout << "La cola está llena" << std::endl;
      if(ret == 0) std::cout << "Se añadío el valor con éxito" << std::endl;
      break;
    case 2:
      ret = enteros.extrar();
      if(ret == -1) std::cout << "La cola está vacía" << std::endl;
      if(ret == -2) std::cout << "La cola está vacía" << std::endl;
      if(ret == 0) std::cout << "Se extrajo el valor con éxito" << std::endl;
      break;
    case 3:
      enteros.mostrar();
      break;
    case 4:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ha ingresado valor válido" << std::endl;
      break;
    }
  }while (opc != 4);
}
