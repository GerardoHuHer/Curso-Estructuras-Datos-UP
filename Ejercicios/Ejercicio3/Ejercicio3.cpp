#include "Ejercicio3.h"

int Arreglo::borrar(int num){
  int pos {-1};
  // Paso 1: Localizar el elemento a borrar
  for(int i = 0; i < ocupados; i++){
    if(num == enteros[i]){
      pos = i;
      break;
    }
  }
  // Paso 2: En caso de no encontrar el valor, te saca de la función ya que no se encontró
  if(pos == -1){
    std::cout << "No se encontró el valor";
    return -1;
  }
  // Paso 3: Desplazar a partir de la posición siguiente a la encontrada
  for(int i = pos; i < ocupados - 1; i++){
    enteros[i] = enteros[i + 1];
  }
  // Paso 4: Colocar en el último espacio el valor de 0
  enteros[ocupados - 1] = 0;
  // Paso 5: Reducir el número de elementos ocupados al último
  ocupados--;
  return 0;
}

int Arreglo::insertar(int num){
  int pos = ocupados;
  // Verifica la capacidad del arreglo
  if(ocupados >= TAM){
    return -2;
  }
  // Localiza la posición a insertar
  for(int i = 0; i < ocupados; i++){
    if(enteros[i] > num){
      pos = i;
      break;
    }
  }
  for(int j = ocupados - 1; j >= pos; j--){
    enteros[j + 1] = enteros[j];
  }
  enteros[pos] = num;
  ocupados++;
  return 0;
}

void Arreglo::mostrar(){
  std::cout << "---------------------------------------------------" << std::endl;
  for(int i = 0; i < ocupados; i++){
    std::cout << "\t" << enteros[i];
  }
  std::cout << std::endl;
  std::cout << "---------------------------------------------------" << std::endl;
}

void menu(){
  setlocale(LC_ALL, "" );
  int opc, valor;
  int retorno;
  Arreglo numero = Arreglo();
  do{
    std::cout << "\n1) Borrar \n2) Insertar \n3) Mostrar \n4) Salir";
    std::cout << "\nIngrese la opción deseada: \n?";
    std::cin >> opc;
    switch(opc){
      case 1:
        std::cout << "¿Qué valor deseas borrar?\n?";
        std::cin >> valor;
        retorno = numero.borrar(valor);
        if(retorno == 0){
          std::cout << "Se borró correctamente" << std::endl;
        }
        if(retorno == -1){
          std::cout << "No se encontró el valor que se deseaba borrar"<< std::endl;
        }
        break;
      case 2:
        std::cout << "¿Qué valor deseas insertar?\n?";
        std::cin >> valor;
        retorno = numero.insertar(valor);
        if(retorno == 0){
          std::cout << "Se insertó correctamente" << std::endl;        
        }
        if(retorno == -1){          
          std::cout << "No se insertó" << std::endl;
        }
        if(retorno == -2){          
          std::cout << "El arreglo está lleno, no se insertó" << std::endl;
        }
        break;
      case 3:
        numero.mostrar();
        break;
      case 4:
        std::cout << "Hasta luego" << std::endl;
        break;
      default:
        std::cout << "No se ingresó una opción válida" << std::endl;
        break;
    }
  }while(opc != 4);
}
