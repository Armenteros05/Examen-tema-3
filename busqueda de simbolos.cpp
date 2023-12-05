#include <iostream>
#include <map>
#include <string>

// Función para buscar el valor asociado a un símbolo en la tabla de símbolos
int lookupSymbol(const std::map<std::string, int>& symbolTable, const std::string& symbol) {
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end()) {
        return it->second; // Devuelve el valor asociado al símbolo
    } else {
        // Manejo de caso en el que el símbolo no está en la tabla
        std::cerr << "Error: El simbolo '" << symbol << "' no esta definido." << std::endl;
        return 0; // Puedes ajustar el valor de retorno según tus necesidades
    }
}

int main() {
    std::map<std::string, int> symbolTable;

    // Insertar algunos símbolos para probar la función lookup
    symbolTable["x"] = 10;
    symbolTable["y"] = 20;

    // Pedir al usuario que ingrese un símbolo para buscar su valor
    std::string userSymbol;
    std::cout << "Ingrese el nombre del simbolo que desea buscar (x o y): ";
    std::cin >> userSymbol;

    // Buscar y mostrar el valor del símbolo
    int symbolValue = lookupSymbol(symbolTable, userSymbol);
    std::cout << "Valor de " << userSymbol << ": " << symbolValue << std::endl;

    return 0;
}
