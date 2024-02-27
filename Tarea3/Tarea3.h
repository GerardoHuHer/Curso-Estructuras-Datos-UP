#pragma once
#include <iostream>
#include <string>

struct Employee{
  std::string name; 
  int years;
  int* pieces;
};

class Array{
public:
  Array();
  void sort();
  void regis();
  void show();
private:
  Employee* arr;
  int tam;
  int ocupados;
};

void menu(Array);
