/******************************************************************************
Autor: Anwar D. Caravantes
Actividad 3. Aplicación para Cálculo de RFC
Fecha: 12 de abril de 2025
*******************************************************************************/

#include <iostream>
#include <string>
#include <cctype> // lo agregamos para poder usar toupper para hacer mayúsculas
#include <unordered_map> // y este para poder utilizar las sustituciones de las palabras inconvenientes

// Función para obtener la primera vocal interna de una cadena (convierte a mayúsculas para la comparación)
char obtenerPrimeraVocalInterna(const std::string& str, size_t start_index = 1) {
    for (size_t i = start_index; i < str.length(); ++i) {
        char c = std::toupper(str[i]);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return std::toupper(str[i]);
    }
    return 'X'; // Si no se encuentra ninguna vocal interna, se usa una X
}

// Función para calcular el RFC y aplicar las sustituciones de palabras inconvenientes
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento, const std::unordered_map<std::string, std::string>& sustituciones) {
    std::string rfc;

    // Se obtienen la letra inicial y la primera vocal interna del apellido paterno
    char letraInicial = std::toupper(apellidoPaterno[0]);
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);

    // Se obtiene la inicial del apellido materno o se usa una 'X' si no hay
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? std::toupper(apellidoMaterno[0]) : 'X';

    // Se obtiene la inicial del primer nombre o se usa una 'X' si no hay
    char inicialNombre = std::toupper(nombre[0]);

    std::string primerosCuatro = "";
    primerosCuatro += letraInicial;
    primerosCuatro += primeraVocalInterna;
    primerosCuatro += inicialApellidoMaterno;
    primerosCuatro += inicialNombre;

    // Verificar si los primeros cuatro caracteres forman una palabra inconveniente y aplicar la sustitución
    if (sustituciones.count(primerosCuatro)) {
        primerosCuatro = sustituciones.at(primerosCuatro);
    }

    // Se obtienen los dos últimos dígitos del año de nacimiento
    std::string anio = fechaNacimiento.substr(2, 2);
    
    // Se obtienen el mes y el día de nacimiento
    std::string mes = fechaNacimiento.substr(5, 2);
    std::string dia = fechaNacimiento.substr(8, 2);

    // Se construye el RFC
    rfc = primerosCuatro;
    rfc += anio;
    rfc += mes;
    rfc += dia;

    return rfc;
}

int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    
    std::unordered_map<std::string, std::string> sustitucionesRFC = {
        {"BACA", "BXCA"}, {"BAKA", "BXKA"}, {"BUEI", "BXEI"}, {"BUEY", "BXEY"},
        {"BUME", "BXME"}, {"BUMI", "BXMI"}, {"BUMO", "BXMO"}, {"BUMU", "BXMU"},
        {"CACA", "CXCA"}, {"CACO", "CXCO"}, {"CAGA", "CXGA"}, {"CAGO", "CXGO"},
        {"CAKA", "CXKA"}, {"CAKO", "CXKO"}, {"COGE", "CXGE"}, {"COGI", "CXGI"},
        {"COJA", "CXJA"}, {"COJE", "CXJE"}, {"COJI", "CXJI"}, {"COJO", "CXJO"},
        {"COLA", "CXLA"}, {"COLO", "CXLO"}, {"CULO", "CXLO"}, {"FALO", "FXLO"},
        {"FETO", "FXTO"}, {"GETA", "GXTA"}, {"GUEI", "GXEI"}, {"GUEY", "GXEY"},
        {"JETA", "JXTA"}, {"JOTO", "JXTO"}, {"KACA", "KXCA"}, {"KACO", "KXCO"},
        {"KAGA", "KXGA"}, {"KAGO", "KXGO"}, {"KAKA", "KXKA"}, {"KAKO", "KXKO"},
        {"KOGE", "KXGE"}, {"KOGI", "KXGI"}, {"KOJA", "KXJA"}, {"KOJE", "KXJE"},
        {"KOJI", "KXJI"}, {"KOJO", "KXJO"}, {"KOLA", "KXLA"}, {"KOLO", "KXLO"},
        {"KULO", "KXLO"}, {"LILO", "LXLO"}, {"LOCA", "LXCA"}, {"LOCO", "LXCO"},
        {"LOKA", "LXKA"}, {"LOKO", "LXKO"}, {"MAME", "MXME"}, {"MAMO", "MXMO"},
        {"MEAR", "MXAS"}, {"MEAS", "MXAS"}, {"MION", "MXON"}, {"MOCO", "MXCO"},
        {"MOKO", "MXKO"}, {"MULA", "MXLA"}, {"MULO", "MXLO"}, {"NACA", "NXCA"},
        {"NACO", "NXCO"}, {"PEDA", "PXDA"}, {"PEDO", "PXDO"}, {"PENE", "PXNE"},
        {"PIPI", "PXPI"}, {"PITO", "PXTO"}, {"POPO", "PXPO"}, {"PUTA", "PXTA"},
        {"PUTO", "PXTO"}, {"QULO", "QXLO"}, {"RATA", "RXTA"}, {"ROBA", "RXBA"},
        {"ROBE", "RXBE"}, {"ROBO", "RXBO"}, {"RUIN", "RXIN"}, {"SENO", "SXNO"},
        {"TETA", "TXTA"}, {"VACA", "VXCA"}, {"VAGO", "VXGO"}, {"VAGA", "VXGA"},
        {"VAKA", "VXKA"}, {"VUEI", "VXEI"}, {"VUEY", "VXEY"}, {"WUEI", "WXEI"},
        {"WUEY", "WXEY"}, {"VERG", "XVGA"} 
    };

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::cout << "Ingrese el apellido materno (si no tiene, presione Enter): ";
    std::getline(std::cin, apellidoMaterno);
    std::cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);

    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, sustitucionesRFC);
    std::cout << "RFC: " << rfc << std::endl;

    return 0;
}