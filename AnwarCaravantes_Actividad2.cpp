/******************************************************************************
Autor: Anwar D. Caravantes
Actividad 2. Suma, resta, multiplicacion y division.
Fecha: 10 de abril de 2025
*******************************************************************************/

/*
1.Que pida el ingreso de dos valores (ya sean enteros o decimales).
2. Que los sume, reste, multiplique y divida.
3. Que los muestre en pantalla con su respectivo enunciado. 
*/

#include <iostream>

int main()
{
    float numero1, numero2;
    
    std::cout << "Escribe el primer numero: "; 
    std::cin >> numero1;
    
    std::cout << "Escribe el segundo numero: ";
    std::cin >> numero2; 
    
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicacion = numero1 * numero2;
    float division = numero1 / numero2;
    
    std::cout << "\nLa suma es: " << suma << std::endl;
    std::cout << "La resta es: " << resta << std::endl;
    std::cout << "La multiplicacion es: " << multiplicacion << std::endl;
    std::cout << "La division es: " << division << std::endl;    
    
    return 0;
}