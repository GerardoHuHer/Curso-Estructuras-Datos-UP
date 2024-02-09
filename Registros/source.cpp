#include "Registros.h"
int main() {
    Mascota mia;
    std::cout << "Nombre: "; std::cin >> mia.nombre;
    std::cout << "Edad: "; std::cin >> mia.edad;
    std::cout << "Mi mascota se llama: " << mia.nombre << std::endl;
    std::cout << "Mi mascota tiene: " << mia.edad << " años"<< std::endl;
    return 0;
}
