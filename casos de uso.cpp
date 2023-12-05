#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    using Value = std::variant<int, double, std::string>;

    Variant(const Value& val) : value(val) {}

    Value getValue() const {
        return value;
    }

    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    void setCharacterAttribute(const std::string& characterName, const std::string& attribute, const Variant::Value& value) {
        characterAttributes[characterName][attribute] = value;
    }

    Variant::Value getCharacterAttribute(const std::string& characterName, const std::string& attribute) const {
        auto characterIt = characterAttributes.find(characterName);
        if (characterIt != characterAttributes.end()) {
            const auto& attributes = characterIt->second;
            auto attributeIt = attributes.find(attribute);
            if (attributeIt != attributes.end()) {
                return attributeIt->second;
            } else {
                std::cerr << "Error: El atributo '" << attribute << "' no está definido para el personaje '" << characterName << "'." << std::endl;
            }
        } else {
            std::cerr << "Error: El personaje '" << characterName << "' no está definido." << std::endl;
        }
        return Variant::Value{};
    }

private:
    std::map<std::string, std::map<std::string, Variant::Value>> characterAttributes;
};

int main() {
    Environment gameEnvironment;

    // Personalizar atributos para el personaje "Hero"
    gameEnvironment.setCharacterAttribute("Hero", "Health", 100);
    gameEnvironment.setCharacterAttribute("Hero", "Strength", 20.5);
    gameEnvironment.setCharacterAttribute("Hero", "Name", "Heroic Warrior");

    // Obtener y mostrar los atributos del personaje "Hero"
    std::cout << "Atributos del Hero:" << std::endl;
    std::cout << "Salud: ";
    Variant(gameEnvironment.getCharacterAttribute("Hero", "Health")).printValue();
    std::cout << "Fuerza: ";
    Variant(gameEnvironment.getCharacterAttribute("Hero", "Strength")).printValue();
    std::cout << "Nombre: ";
    Variant(gameEnvironment.getCharacterAttribute("Hero", "Name")).printValue();

    return 0;
}
