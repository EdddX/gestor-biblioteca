#include <iostream>
#include <string>
class Libro {
public:
std::string titulo;
std::string autor;
std::string isbn;
};
int main() {
Libro l1;
l1.titulo = "Cien años de soledad";
l1.autor = "Gabriel García Márquez";
l1.isbn = "978-0307474728";
std::cout << "Título: " << l1.titulo << "\n";
std::cout << "Autor: " << l1.autor << "\n";
std::cout << "ISBN: " << l1.isbn << "\n";
return 0;
}