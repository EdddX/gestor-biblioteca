#include <iostream>
#include <string>
#include <vector>

class Libro {
private:
    std::string titulo, autor, isbn;
public:
    Libro() : titulo(""), autor(""), isbn("") {}
    Libro(std::string t, std::string a, std::string i) : titulo(t), autor(a), isbn(i) {}
    
    void mostrarInfo() const {
        std::cout << "Libro: " << titulo << " | Autor: " << autor << " | ISBN: " << isbn << std::endl;
    }
};

class Biblioteca {
private:
    std::vector<Libro> listaLibros;
public:
    void agregarLibro(const Libro& nuevoLibro) {
        listaLibros.push_back(nuevoLibro);
    }

    void mostrarCatalogo() const {
        if (listaLibros.empty()) {
            std::cout << "La biblioteca esta vacia." << std::endl;
            return;
        }
        std::cout << "\n--- CATALOGO DE LA BIBLIOTECA ---" << std::endl;
        for (const auto& libro : listaLibros) {
            libro.mostrarInfo();
        }
    }
};

int main() {
    Biblioteca miBiblioteca;
    miBiblioteca.agregarLibro(Libro("El Quijote", "Cervantes", "123"));
    miBiblioteca.agregarLibro(Libro("C++ Primer", "Lippman", "456"));

    miBiblioteca.mostrarCatalogo();

    std::cout << "\nPresiona Enter para salir...";
    std::cin.get();
    return 0;
}