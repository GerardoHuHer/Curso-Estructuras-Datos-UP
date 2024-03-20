#include "Ejercicio4.h"

Arreglo::Arreglo(){
  ocupados = 0;
}


void Arreglo::bubble_sort(){
  Sucursal aux;
  int iterador{0};
  bool ordenado = false;
  while(!ordenado){
    ordenado = true;
    for(int i = 0; i < ocupados; i++){
      if(obj[i].num_sucursal > obj[i + 1].num_sucursal){
        aux = obj[i];
        obj[i] = obj[i + 1];
        obj[i + 1] = aux;
        ordenado = false;
      }
    }
    iterador++;
  }  
}

void Arreglo::mostrar(){
  for(int i = 0; i < ocupados; i++){
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Número de Sucursal: "<<obj[i].num_sucursal << std::endl;
    std::cout << "Gerente: "<<obj[i].gerente << std::endl;
    for(int j = 0; j < 2; j++){
    std::cout << "Venta del mes " << j + 1 << ": " << obj[i].ventas[j] << std::endl;
    }
  }
  std::cout << "---------------------------------------" << std::endl;
}

int Arreglo::llenado(){
  int numS;
  do{
    if(ocupados >= TAM){
      return -1;
    }
    std::cout << "Ingrese el número de sucursal, para salir ingrese 0 \n? ";
    std::cin >> numS;
    if(numS == 0){
      break;
    }
    obj[ocupados].num_sucursal = numS;
    std::cin.ignore();
    std::cout << "Ingrese el nombre del gerente: \n? ";
    std::getline(std::cin, obj[ocupados].gerente);
    for(int i = 0; i < 2; i++){
      std::cout << "Ingrese la venta del mes " << i + 1 << "\n? ";std::cin >> obj[ocupados].ventas[i]; 
    }
    ocupados++;
  }while(numS != 0);
  return 0;
}

void menu(){
  Arreglo obj1;
  bool band = false;
  int opc;
  int resultado;
  do{
    std::cout << "1) Llenar \n2) Mostrar \n3) Ordenar \n4) Salir" << std::endl;
    std::cin >> opc;
    switch (opc) {
      case 1:
        resultado = obj1.llenado();
        if(resultado == -1 ){
          std::cout << "\nEl arreglo está lleno";
        }
        else{
          std::cout << "\nSe ha llenado correctamente";
        }
        band = true;
        break;
      case 2:
        if(!band){
          std::cout << "\nNo se ha ingresado ninguna sucursal";
        }
        else{
          obj1.mostrar();
        }
        break;
      case 3:
        obj1.bubble_sort();
        break;
      case 4:
        std::cout << "Hasta luego";
        break;
      default:
        std::cout << "No se ingresó una opción válida";
        break;
    
    }
  }while(opc != 4); 
}
