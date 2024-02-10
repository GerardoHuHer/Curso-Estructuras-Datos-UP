#include "Tarea2Registros.h"
#include <string>

Arreglo::Arreglo(){
  ocupados = 0;
}

int Arreglo::borrar(string nombre){
  int pos {-1};
  // Obtenemos posición
  for(int i = 0; i < ocupados; i++){
    if(arr[i].nombre == nombre){
      pos = i;
      break;
    }
  }
  // En caso de no encontrar el valor, salimos del método
  if(pos == -1){
    return -1;
  }
  // Eliminamos la posición actual y desplazamos el resto de elementos
  for(int i = pos; i < ocupados; i++){
    arr[i] = arr[i + 1];
  }
  // Marcamos el último elemento que antes estaba ocupado como 0
  arr[ocupados].estatura = 0;
  arr[ocupados].nombre = "";
  arr[ocupados].sueldo = 0;
  // Restamos un valor a ocupados ya que eliminamos un elemento
  ocupados--;
  return 0;
}

int Arreglo::insertar(Empleado emp){
  int pos = ocupados;
  // Verificar la capacidad del arreglo
  if(ocupados >= TAM){
    return -2;
  }
  // Localizamos la posición a insertar
  for(int i = 0; i < ocupados; i++){
    if(arr[i].nombre > emp.nombre){
      pos = i;
      break;
    }
  }
  // Dezplazamos los elementos a la derecha para poder añadir el nuevo
  for(int i = ocupados - 1; i >= pos; i-- ){
    arr[i + 1] = arr[i];
  }
  // Colocamos en la posición que obtuvimos antes el empleado deseado
  arr[pos] = emp;
  // Aumentamos una posición en ocupados
  ocupados++;
  return 0;
}

void Arreglo::bubble_sort(){
  bool ordenado = false;
  Empleado aux;
  int iter{0};
  while(!ordenado){
    ordenado = true;
    for(int i = 0; i < ocupados - iter - 1; i++){
      if(arr[i].nombre > arr[i + 1].nombre){
        aux = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = aux;
        ordenado = false;
       }
    }
    iter++;
  }
}
int Arreglo::llenado(){
  string nombre;
  do{
    if(ocupados >= TAM){
      return -2;
    }
    cout << "Ingrese el nombre del empleado para salir escriba \"salir\": \n? ";
    cin >> nombre;
    if(nombre == "salir"){
      break;
    }
    arr[ocupados].nombre = nombre;
    cout << "\nIngrese la estatura en centímetros del empleado: \n? ";
    cin >> arr[ocupados].estatura;
    cout << "Ingrese el sueldo semanal: \n? ";
    cin >> arr[ocupados].sueldo;
    ocupados++;
    
  }while(nombre != "salir");
  return 0;
}

Empleado crearEmp(){
  Empleado obj1;
  cout << "Ingrese el nombre del empleado: \n? ";
  cin >> obj1.nombre;
  cout << "Ingrese la estatura del empleado: \n? ";
  cin >> obj1.estatura;
  cout << "Ingrese el sueldo del empleado: \n? ";
  cin >> obj1.sueldo;
  return obj1;
}

void Arreglo::mostrar(){
  for(int i = 0; i < ocupados; i++){
    cout << "---------------------------------" << endl;
    cout << "\nNombre: " << arr[i].nombre <<
       "\nEstatura: " << arr[i].estatura <<
       "\nSueldo semanal: " << arr[i].sueldo << endl;
    
  }
  cout << endl;
  cout << "---------------------------------" << endl;
}

void menu(){
  int opc {-1};
  Empleado retorno;
  int ret;
  Arreglo obj;
  string nombre1;
  do{    
    cout << "1) Ingresar nuevo empleado \n2) Llenar empleados \n3) Borrar empleado \n4) Mostrar lista \n5) Ordenar \n6) Salir ";
    cout << "Ingrese la opción deseada: \n? ";
    cin >> opc;
    switch (opc) {
      case 1:
        retorno = crearEmp();
        ret = obj.insertar(retorno);
        if(ret == -2)
          cout << "El arreglo ya está lleno\n";
        if(ret == 0)
          cout << "Se ha ingresado el empleado correctamente\n";
        break;
      case 2:
        ret = obj.llenado();
        if(ret == -2)
          cout << "El arreglo ya está lleno\n";
        if(ret == 0)
          cout << "Se han ingresado los empleados correctamente\n";
        break;
      case 3:
        cout << "Ingrese el nombre del empleado que desea eliminar: \n? ";
        cin >> nombre1;
        ret = obj.borrar(nombre1);
        if(ret == -1)
          cout << "No se ha encontrado el empleado\n";
        if(ret == 0)
          cout << "Se ha borrado correctamente\n";
        break;
      case 4:
        obj.mostrar();
        break;
      case 5:
        obj.bubble_sort();
        break;
      case 6:
        cout << "Hasta luego";
        break;
      default:
        cout << "No se ingresó una opción válida\n";
        break;
    }
  }while(opc != 6);
}
