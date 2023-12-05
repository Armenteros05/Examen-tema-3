#include <iostream>
#include <map>
#include <string>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    // Método para agregar un símbolo y su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    // Método para obtener el valor asociado a un símbolo en la tabla de símbolos
    int getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second; // Devuelve el valor asociado al símbolo
        } else {
            // Manejo de error si el símbolo no está en la tabla
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido." << std::endl;
            return 0; // Puedes ajustar el valor de retorno según tus necesidades
        }
    }

    // Puedes agregar más métodos según las necesidades de tu entorno
};

int main() {
    // Ejemplo de uso
    Environment myEnvironment;

    // Agregamos símbolos a la tabla
    myEnvironment.addSymbol("x", 10);
    myEnvironment.addSymbol("y", 20);

    // Obtener valores de la tabla
    std::cout << "Valor de x: " << myEnvironment.getSymbolValue("x") << std::endl;
    std::cout << "Valor de y: " << myEnvironment.getSymbolValue("y") << std::endl;

    // Intentar obtener el valor de un símbolo no definido
    std::cout << "Valor de z: " << myEnvironment.getSymbolValue("z") << std::endl;

    return 0;
}
