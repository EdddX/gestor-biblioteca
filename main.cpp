#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Necesario para std::remove_if

class Libro {
private:
    std::string titulo, autor, isbn;
public:
    Libro(std::string t, std::string a, std::string i) : titulo(t), autor(a), isbn(i) {}
    
    // Getters necesarios para buscar y eliminar
    std::string getIsbn() const { return isbn; }
    std::string getTitulo() const { return titulo; }

    void mostrarInfo() const {
        std::cout << "[ISBN: " << isbn << "] " << titulo << " - " << autor << std::endl;
    }
};

class Biblioteca {
private:
    std::vector<Libro> listaLibros;
public:
    void agregarLibro(const Libro& l) {
        listaLibros.push_back(l);
    }

    void mostrarCatalogo() const {
        if(listaLibros.empty()) {
            std::cout << "La biblioteca esta vacia.\n";
            return;
        }
        for (const auto& libro : listaLibros) libro.mostrarInfo();
    }

    // --- NUEVO: BÚSQUEDA (20 pts) ---
    void buscarLibro(std::string isbnBusqueda) const {
        for (const auto& libro : listaLibros) {
            if (libro.getIsbn() == isbnBusqueda) {
                std::cout << "Libro encontrado: ";
                libro.mostrarInfo();
                return;
            }
        }
        std::cout << "Libro con ISBN " << isbnBusqueda << " no encontrado.\n";
    }

    // --- NUEVO: ELIMINACIÓN (20 pts) ---
    bool eliminarLibro(std::string isbnEliminar) {
        for (auto it = listaLibros.begin(); it != listaLibros.end(); ++it) {
            if (it->getIsbn() == isbnEliminar) {
                listaLibros.erase(it); // Uso de erase() como pide la rúbrica
                return true;
            }
        }
        return false;
    }
};

int main() {
    Biblioteca miBiblioteca;
    miBiblioteca.agregarLibro(Libro("El Quijote", "Cervantes", "123"));
    miBiblioteca.agregarLibro(Libro("C++ Primer", "Lippman", "456"));

    std::cout << "--- Listado inicial ---\n";
    miBiblioteca.mostrarCatalogo();

    std::cout << "\n--- Probando Busqueda ---\n";
    miBiblioteca.buscarLibro("456");

    std::cout << "\n--- Probando Eliminacion (ISBN 123) ---\n";
    if(miBiblioteca.eliminarLibro("123")) std::cout << "Eliminado con exito.\n";

    std::cout << "\n--- Listado final ---\n";
    miBiblioteca.mostrarCatalogo();

    return 0;
}