#include <string>
#include <unordered_map>

using namespace std;

class Orden {
    // Clase con la info de la orden
    private:

    string direccion;
    string codigoPostal;
    unordered_map<string, int> infoOrden;  // se mapea un producto a su cantidad

    public:

    Orden(string direccion_, string codigoPostal_, unordered_map<string, int> infoOrden_) {
        direccion = direccion_;
        codigoPostal = codigoPostal_;
        infoOrden = infoOrden_;
    }
        
        
    void imprimirOrden() {}
};