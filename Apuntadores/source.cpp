#include "Apuntadores.h"

int main() {
    int n;
    Apuntador obj = Apuntador();
    std::cout << "Ingrese el tamano de su arreglo: \n? ";
    std::cin >> n;
    obj.AsignacionEst(n);
    return 0;
}
