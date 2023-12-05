#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    // Definir un tipo para representar valores flexibles
    using Value = std::variant<int, double, std::string>;

    // Constructor que acepta un valor inicial
    Variant(const Value& val) : value(val) {}

    // Obtener el valor almacenado en Variant
    Value getValue() const {
        return value;
    }

    // Imprimir el valor almacenado
    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    // Método para agregar un símbolo y su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }

    // Método para obtener el valor asociado a un símbolo en la tabla de símbolos
    Variant::Value getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second; // Devuelve el valor asociado al símbolo
        } else {
            std::cerr << "Error: El simbolo '" << symbol << "' no esta definido." << std::endl;
            return Variant::Value{}; // Devuelve un valor predeterminado
        }
    }

    // Método para eliminar un símbolo del entorno
    void removeSymbol(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            symbolTable.erase(it); // Elimina el símbolo de la tabla
            std::cout << "Simbolo '" << symbol << "' eliminado con exito." << std::endl;
        } else {
            std::cerr << "Error: El simbolo '" << symbol << "' no existe en el entorno." << std::endl;
        }
    }

    // Método para verificar si un símbolo existe en el entorno
    bool symbolExists(const std::string& symbol) const {
        return symbolTable.find(symbol) != symbolTable.end();
    }

    // Método para imprimir todos los símbolos y sus valores en el entorno
    void printEnvironment() const {
        std::cout << "Entorno:" << std::endl;
        for (const auto& entry : symbolTable) {
            std::cout << entry.first << ": ";
            Variant(entry.second).printValue();
        }
    }

private:
    std::map<std::string, Variant::Value> symbolTable;
};

int main() {
    Environment myEnvironment;

    // Agregar símbolos con valores de diferentes tipos
    myEnvironment.addSymbol("x", 10);
    myEnvironment.addSymbol("y", 3.14);
    myEnvironment.addSymbol("name", "John");

    // Verificar si un símbolo existe
    std::cout << "El simbolo 'x' existe? " << (myEnvironment.symbolExists("x") ? "Si" : "No") << std::endl;

    // Eliminar un símbolo
    myEnvironment.removeSymbol("y");

    // Verificar si el símbolo eliminado aún existe
    std::cout << "El simbolo 'y' existe despues de eliminarlo? " << (myEnvironment.symbolExists("y") ? "Sí" : "No") << std::endl;

    // Imprimir todos los símbolos y sus valores
    myEnvironment.printEnvironment();

    return 0;
}
