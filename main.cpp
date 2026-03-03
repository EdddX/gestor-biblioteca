#include <iostream>
#include <string>
#include <vector>

class Libro {
private:
    std::string titulo, autor, isbn;
public:
    Libro(std::string t, std::string a, std::string i) : titulo(t), autor(a), isbn(i) {}
    void mostrar() const {
        std::cout << "Libro: " << titulo << " | Autor: " << autor << " | ISBN: " << isbn << std::endl;
    }
};

class Biblioteca {
private:
    std::vector<Libro> listaLibros;
public:
    // Método para agregar un libro (Usa push_back como pide la rúbrica)
    void agregarLibro(const Libro& l) {
        listaLibros.push_back(l);
    }

    // Método para listar (Usa iteración segura)
    void mostrarCatalogo() const {
        std::cout << "\n--- CATALOGO DE LA BIBLIOTECA ---" << std::endl;
        for (const auto& libro : listaLibros) {
            libro.mostrar();
        }
    }
};

int main() {
    Biblioteca miBiblioteca;
    
    // Agregamos libros
    miBiblioteca.agregarLibro(Libro("El Quijote", "Cervantes", "123"));
    miBiblioteca.agregarLibro(Libro("C++ Primer", "Lippman", "456"));
    
    miBiblioteca.mostrarCatalogo();

    std::cout << "\nPresiona Enter para salir...";
    std::cin.get();
    return 0;
}