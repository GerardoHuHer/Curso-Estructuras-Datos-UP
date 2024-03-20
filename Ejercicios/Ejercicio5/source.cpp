#include "Ejercicio5.h"
int main() {
    Arreglo obj = Arreglo();
    std::cout << "--------------------------------------------------" << std::endl;
    obj.insert();
    obj.show();
    std::cout << "--------------------------------------------------" << std::endl;
    obj.sort();
    obj.show();
    return 0;
}
