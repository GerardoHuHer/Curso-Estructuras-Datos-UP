#include "Ejercicio2.h"
int main() {
    int num;
    Arreglo obj = Arreglo();
    obj.mostrar();
    std::cout << "Ingrese el número que desea agregar al arreglo \n?";
    std::cin >> num;
    obj.insertar(num);
    obj.mostrar();
    return 0;
}
