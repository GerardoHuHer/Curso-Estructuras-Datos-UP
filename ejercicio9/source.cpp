#include "ejercicio9.h"
int main() {
  ColaCirular C;
  int res;
  std::string ress;
  C.mostrar();
  res = C.insertar("AA");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  res = C.insertar("BB");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  res = C.insertar("CC");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  C.mostrar();
  ress = C.extraer();
  if (ress == "")
    std::cout << "Cola vacía (subdesbordamiento)" << std::endl;
  C.mostrar();
  res = C.insertar("DD");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  res = C.insertar("EE");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  res = C.insertar("FF");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  C.mostrar();
  res = C.insertar("GG");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  res = C.insertar("HH");
  if (res == -1)
    std::cout << "Cola llena (desbordamiento)" << std::endl;
  C.mostrar();
  ress = C.extraer();
  if (ress == "")
    std::cout << "Cola vacía (subdesbordamiento)" << std::endl;
  ress = C.extraer();
  if (ress == "")
    std::cout << "Cola vacía (subdesbordamiento)" << std::endl;
  C.mostrar();
  return 0;
}
