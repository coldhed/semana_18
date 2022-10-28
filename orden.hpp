#include <string>
#include <unordered_map>

using namespace std;

class Orden {
    // Clase con la info de la orden.
    private:

    string direccion;
    string codigoPostal;
    string metodoDeEntrega;
    string nombre;
    unordered_map<string, int> infoOrden;  // se mapea un producto a su cantidad

    public:

    Orden(string direccion_, string codigoPostal_, string nombre_, unordered_map<string, int> infoOrden_, string metodoDeEntrega_) {
        direccion = direccion_;
        codigoPostal = codigoPostal_;
        nombre = nombre_;
        infoOrden = infoOrden_;
        metodoDeEntrega = metodoDeEntrega_;
    }
        
        
    void imprimirOrden() {
        cout << "Orden de " << nombre << endl;
        cout << "Metodo de entrega: " << metodoDeEntrega << endl;

        if (metodoDeEntrega == "domicilio") {
            cout << "Direccion: " << direccion << endl;
        }

        for (auto i = infoOrden.begin(); i != infoOrden.end(); ++i) {
            cout << i->first << ": " << i->second << endl;
        }
    }
};
