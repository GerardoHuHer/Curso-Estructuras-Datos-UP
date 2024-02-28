#include "Tarea4.h"

Pilas::Pilas(){
  min = 0;
  tope = min - 1;
  max = TAM - 1;
  original = new int[TAM];
  for(int i = 0; i < TAM; i++){
    *(original + i) = 0;
  }
}

int Pilas::push(int num){
  // In case it returns -1, means that the stack is full
  if(tope >= max){
    return -1;
  } 
  tope++;
  *(original + tope) = num;
  // In case it returns 0, means that we have pushed the number
  return 0;
}

int Pilas::pop(){
  // If it returns -1, means that the stack is empty
  if(tope < min){
    return -1;
  }
  int ret = original[tope];
  original[tope] = 0;
  tope--;
  return ret;
}

int depurar(Pilas original, Pilas dep, int num){
  // If topeo is less than mino, means that the original stack is empty
  if(original < ){
    return -1;
  }
  for(int i = 0; i < tope; i++){
  
  }
}
