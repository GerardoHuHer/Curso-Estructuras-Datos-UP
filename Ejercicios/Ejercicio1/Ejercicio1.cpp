#include "Ejercicio1.h"

void Ejercicio::ejercicio_a(){
  int num;
  int cont{0};
  int suma{0};
  do{
    std::cout << "Ingrese el número que desea sumar: \n?";
    std::cin >> num;
    cont++;
    suma += num;
  }while(num != 0);
  std::cout << "La suma total es de: " << suma << std::endl;
  std::cout << "La cantidad de números sumados es de: " << cont - 1 << std::endl;
}

void Ejercicio::ejercicio_b(){
  int sumaPar{0}, sumaImpar{0};
  int contP{0}, contI{0};
  int num;
  for(int i = 0; i < 9; i++){
    std::cout << "Ingrese su número: \n?";
    std::cin >> num;
    if(num % 2 == 0){
      sumaPar += num;
      contP++;
    }
    else{
      sumaImpar += num;
      contI++;
    }
  }
  std::cout << "La suma total de los números pares es de : " << sumaPar << " y la cantidad de números pares es de " << contP << std::endl;
  std::cout << "La suma total de los números impares es de : " << sumaImpar << " y la cantidad de números impares es de " << contI << std::endl;
}
