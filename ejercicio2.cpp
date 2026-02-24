#include <iostream>
#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    int anioPublicacion;

public:
    Libro(std::string t, std::string a, std::string i, int anio) 
        : titulo(t), autor(a), isbn(i), anioPublicacion(anio) {
        std::cout << "-> Objeto Libro creado: " << titulo << std::endl;
    }

    ~Libro() {
        std::cout << "-> Objeto Libro '" << titulo << "' destruido." << std::endl;
    }

    std::string getTitulo() const { return titulo; }
    void setTitulo(const std::string& t) { titulo = t; }

    std::string getAutor() const { return autor; }
    void setAutor(const std::string& a) { autor = a; }

    std::string getIsbn() const { return isbn; }
    void setIsbn(const std::string& i) { isbn = i; }

    int getAnioPublicacion() const { return anioPublicacion; }
    void setAnioPublicacion(int anio) { anioPublicacion = anio; }

    
    void mostrarInfo() const {
        std::cout << "===========================" << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Autor:  " << autor << std::endl;
        std::cout << "ISBN:   " << isbn << std::endl;
        std::cout << "Año:    " << anioPublicacion << std::endl;
        std::cout << "===========================" << std::endl;
    }
};

int main() {
    
    Libro libro1("C++ Primer", "Stanley Lippman", "978-0321714114", 2012);

    std::cout << "\n--- Datos iniciales ---" << std::endl;
    libro1.mostrarInfo();

    
    std::cout << "\nModificando el titulo y el año..." << std::endl;
    libro1.setTitulo("C++ Primer - Edición Especial");
    libro1.setAnioPublicacion(2024);

    
    std::cout << "\nConfirmando cambio con Getter:" << std::endl;
    std::cout << "Nuevo Título: " << libro1.getTitulo() << std::endl;
    std::cout << "Nuevo Año:    " << libro1.getAnioPublicacion() << std::endl;

    std::cout << "\n--- Datos actualizados ---" << std::endl;
    libro1.mostrarInfo();

    std::cout << "\nPresiona Enter para salir..." << std::endl;
    std::cin.get();

    return 0;
}