#include <iostream>
#include <map>
#include <string>

// Función para insertar un símbolo en la tabla, evitando conflictos
void insertSymbol(std::map<std::string, int>& symbolTable, const std::string& symbol, int value) {
    auto it = symbolTable.find(symbol);
    if (it == symbolTable.end()) {
        // El símbolo no existe, se puede insertar
        symbolTable[symbol] = value;
        std::cout << "Simbolo '" << symbol << "' insertado con exito." << std::endl;
    } else {
        // El símbolo ya existe, manejo de conflicto
        std::cerr << "Error: El simbolo '" << symbol << "' ya esta definido." << std::endl;
    }
}

int main() {
    std::map<std::string, int> symbolTable;

    int numSymbols;
    std::cout << "Ingrese el numero de simbolos que desea crear: ";
    std::cin >> numSymbols;

    for (int i = 0; i < numSymbols; ++i) {
        std::string symbol;
        int value;

        std::cout << "Ingrese el nombre del simbolo " << i + 1 << ": ";
        std::cin >> symbol;

        std::cout << "Ingrese el valor del simbolo " << i + 1 << ": ";
        std::cin >> value;

        // Intentar insertar el símbolo en la tabla
        insertSymbol(symbolTable, symbol, value);
    }

    // Imprimir valores de la tabla
    for (const auto& entry : symbolTable) {
        std::cout << "Valor de " << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
