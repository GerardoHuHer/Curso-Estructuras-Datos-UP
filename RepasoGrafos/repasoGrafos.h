#ifndef REPASOGRAFOS_H
#define REPASOGRAFOS_H
#include <iostream>

class Persona{
public:
  std::string curp;
  std::string name;
  int edad;  
  friend std::ostream& operator<<(std::ostream&, Persona&);
  friend std::istream& operator>>(std::istream&, Persona&);
  bool operator==(Persona&);
  bool operator!=(Persona&);
  bool operator<=(Persona&);
  bool operator>=(Persona&);
  bool operator<(Persona&);
  bool operator>(Persona&);
};

struct Nodo;

struct Ady{
};

#endif
