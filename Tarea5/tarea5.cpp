#include "tarea5.h"
#include <string>

Cola::Cola() {
  mini = 0;
  maxi = TAM - 1;
  principio = final = -1;
  boletos = new Boleto[TAM];
  for (int i = 0; i < TAM; i++) {
    boletos[i].no_boleto = 0;
    boletos[i].descuento = false;
    boletos[i].nombre = "- -";
  }
}

int Cola::insertar(std::string name, int num) {
  // Paso 1: Revisar capacidad
  if (principio == mini && final == maxi) {
    return -1;
  }
  if ((final + 1) == principio) {
    return -1;
  }
  // Paso 2: Incrementar final, incrementar principio en caso de que este en -1
  // y si final llega es mayor que maximo pasarlo al minimo
  final++;
  if (principio == -1) {
    principio++;
  }
  if (final > maxi) {
    final = mini;
  }
  // Paso 3: Llenar información
  boletos[final].nombre = name;
  boletos[final].no_boleto = num;
  boletos[final].descuento = (num % 5) == 0 ? true : false;
  return 0;
}

Boleto Cola::extraer() {
  Boleto aux, vacio;
  vacio.nombre = "- -";
  vacio.no_boleto = 0;
  vacio.descuento = false;
  // Paso 1: Revisar que haya información
  if (final == -1 && principio == -1) {
    return vacio;
  }
  // Paso 2: Extraer la información a aux
  aux = boletos[principio];
  boletos[principio] = vacio;
  // Paso 3: Incrementar inicio
  if (principio == final) {
    principio = final = -1;
    return vacio;
  }
  principio++;
  return aux;
}

void Cola::mostrar() {
  std::cout << "========== BOLETOS ==========" << std::endl;
  std::cout << "No. Boleto \t Nombre" << std::endl;
  for (int i = 0; i < TAM; i++) {
    std::cout << "\t" << boletos[i].no_boleto << "\t" << boletos[i].nombre;
    if (i == maxi)
      std::cout << "\t<= Máximo ";
    if (i == mini)
      std::cout << "\t<= Mínimo ";
    if (i == principio)
      std::cout << "\t<= Principo ";
    if (i == final)
      std::cout << "\t<= Final ";
    if (boletos[i].descuento)
      std::cout << "\t<= DESCUENTO ";
    std::cout << std::endl;
  }
  std::cout << "=============================" << std::endl;
    
}
void Cola::mostrarAfortunado() {
  std::cout << "========== AFORTUNADOS ==========" << std::endl;
  std::cout << "No. Boleto \t Nombre" << std::endl;
  for (int i = 0; i < TAM; i++) {
    if (boletos[i].descuento) {
      std::cout << "\t" << boletos[i].no_boleto << "\t" << boletos[i].nombre;
      std::cout << std::endl;
    }
  }
  std::cout << "=================================" << std::endl;
}

void menu() {
  int opc;
  int pos{1};
  int ret;
  std::string name;
  Boleto aux;
  Cola cola = Cola();
  do {
    std::cout << "============ MENU ============" << std::endl;
    std::cout
        << "\n1) Ingresar \n2) Extraer \n3) Mostrar \n4) Mostrar Afortunado "
           "\n5) Salir \nIngrese la opción deseada \n? ";
    std::cin >> opc;
    std::cout << "==============================" << std::endl;
    switch (opc) {
    case 1:
      std::cin.ignore();
      std::cout << "Ingrese su nombre: \n? ";
      std::getline(std::cin, name);
      ret = cola.insertar(name, pos);
      if (ret == 0) {
        pos++;
        std::cout << "Se ha ingresado correctamente" << std::endl;
      }
      if (ret == -1)
        std::cout << "La cola está llena" << std::endl;
      break;
    case 2:
      aux = cola.extraer();
      if (aux.nombre == "- -")
        std::cout << "La cola está vacía" << std::endl;
      else {
        if (aux.descuento)
          std::cout << "Boleto extraído: " << aux.no_boleto << "\t"
                    << aux.nombre << " Boleto con descuento" << std::endl;
        else
          std::cout << "Boleto extraído: " << aux.no_boleto << "\t"
                    << aux.nombre << std::endl;
      }
      break;
    case 3:
      cola.mostrar();
      break;
    case 4:
      cola.mostrarAfortunado();
      break;
    case 5:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ingresó una opción válida" << std::endl;
      break;
    }
  } while (opc != 5);
}
