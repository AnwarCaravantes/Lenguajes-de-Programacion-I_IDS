/******************************************************************************
Autor: Anwar D. Caravantes
Actividad 1. Determinar si es mayor o menor de edad

Fecha: 10 de Abril de 2025 
*******************************************************************************/
#include <iostream>

int main()
{
    int edad;
    
    // Pedir al usuario ingresar su edad
    std::cout << "Ingrese su edad: ";
    std::cin >> edad;
    
    //Determinar si es mayor o menor de edad y mostrar en pantalla el resultado
    if (edad >= 18){
        std::cout << "Usted tiene " << edad << " y es mayor de edad." << std::endl;
    } else{
        std::cout << "Usted tiene " << edad << " y es menor de edad." << std::endl;
    }

    return 0;
}

