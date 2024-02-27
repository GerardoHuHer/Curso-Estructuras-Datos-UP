#include "Ejercicio6.h"
#include <memory>

PilaEnteros::PilaEnteros(){
  tope = min - 1;
  max = TAM - 1;
  min = 0; 
  pila = new int[TAM];
  for(int i = 0; i < TAM; i++){
    *(pila + i) = 0;
  }
 }

int PilaEnteros::push(int num){
  // Paso 1: Verificar que la pila no esté llena
  if(tope >= max){
    return -1;
  }
  // Paso 2: Incrementar el valor de tope
  tope++;
  // Paso 3: Insertar el nuevo valor en la posición de tope
  pila[tope] = num;
  return 0;
}

int PilaEnteros::pop(){
  int extraido;
  // Paso 1: Verificar que la pila no esté vacía
  if(tope <  min){
    return -1;
  }
  // Paso 2: Almacenar el valor del tope y almacenarlo en extraído
  extraido = pila[tope];
  pila[tope] = 0;
  // Paso 3: Decrementar el valor de tope
  tope--;
  return extraido;
}

void PilaEnteros::show(){
  for(int i = max; i >= 0; i--){
    std::cout << "\t" << pila[i];
    if(i == min) std::cout << "\t <=Mínimo"; 
    if(i == max) std::cout << "\t <=Máximo"; 
    if(i == tope) std::cout << "\t <=Tope"; 
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int PilaEnteros::consultar(){
  if(tope < min) return -1;
  return pila[tope];
}

void menu(){
  PilaEnteros pil = PilaEnteros();
  int opc, num;
  int ret {0};
  while(opc != 5){
    std::cout << "\n1) Push \n2) Pop \n3) Show \n4) Consultar \n5) Quit" << std::endl;
    std::cin >> opc;
    switch (opc) {
      case 1:
      std::cout <<   "Enter a number: \n? ";
      std::cin >> num;
      ret = pil.push(num);
      if(ret == 0) std::cout << "It have been push successfully" << std::endl;
      if(ret == -1) std::cout << "The stack is full" << std::endl;
      break;
      case 2:
      ret = pil.pop();
      if(ret == -1){
        std::cout << "The stack is empty" << std::endl;  
      }
      if(ret != -1) std::cout << "The value is " << ret << std::endl; 
      break;
      case 3:
      pil.show();
      break;
      case 4:
      pil.consultar();
      break;
      case 5:
      std::cout << "Goodbye" << std::endl;
      break;
      default:
      std::cout << "Invalid Option" << std::endl;
      break;
  }
    
  }

}
