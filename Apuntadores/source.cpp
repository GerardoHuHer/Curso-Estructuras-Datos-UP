#include "Apuntadores.h"
int main() {
    int num = 5;
    int* direccion_num = &num;
    std::cout << "Número: " << *direccion_num << std::endl;
    std::cout << "Dirección de Memoria: " << direccion_num << std::endl;
    return 0;
}
