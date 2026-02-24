#include <iostream>
#include <string>
#include <vector>

class Libro {
private:
    // Atributos privados (Encapsulación)
    std::string titulo;
    std::string autor;
    std::string isbn;

public:
    // 1. Constructor por defecto (campos vacíos)
    Libro() : titulo("Sin titulo"), autor("Sin autor"), isbn("000-000") {}

    // 2. Constructor con parámetros
    Libro(std::string t, std::string a, std::string i) 
        : titulo(t), autor(a), isbn(i) {}

    // --- Métodos Públicos (Getters) ---
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    std::string getIsbn() const { return isbn; }

    // --- Métodos Públicos (Setters) ---
    void setTitulo(const std::string& t) { titulo = t; }
    void setAutor(const std::string& a) { autor = a; }
    void setIsbn(const std::string& i) { isbn = i; }

    // Método para mostrar información con formato claro
    void mostrarInfo() const {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "TITULO: " << titulo << std::endl;
        std::cout << "AUTOR:  " << autor << std::endl;
        std::cout << "ISBN:   " << isbn << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
};

int main() {
    // Crear al menos tres objetos usando ambos constructores
    
    // Objeto 1: Usando constructor con parámetros
    Libro libro1("El Quijote", "Miguel de Cervantes", "978-8424922498");

    // Objeto 2: Usando constructor con parámetros
    Libro libro2("C++ Primer", "Stanley Lippman", "978-0321714114");

    // Objeto 3: Usando constructor por defecto y luego setters
    Libro libro3; 
    libro3.setTitulo("Programacion ATS");
    libro3.setAutor("Alejandro Taboada");
    libro3.setIsbn("111-222-333");

    // Mostrar la información de cada objeto
    std::cout << "LISTADO DE LIBROS EN BIBLIOTECA:" << std::endl;
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    libro3.mostrarInfo();

    std::cout << "\nPresiona Enter para salir..." << std::endl;
    std::cin.get();

    return 0;
}