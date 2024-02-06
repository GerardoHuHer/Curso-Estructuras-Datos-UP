#pragma once
#include <iostream>
#include <string>

class Arreglo{
public:
  void show_int();
  void show_string();
  void bubble_sortI();
  void bubble_sortS();
private:
  int int_array[5] = {3,1,7,6,9};
  std::string str_array[5] = {"computadora", "frutas", "verduras", "países", "árbol"};
  
};
