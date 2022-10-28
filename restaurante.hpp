#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Alimentos{
    protected:
        double precio;
        std::string nombre;
    public:
        Alimentos()
        {
            precio = 0;
            nombre = "";
        }
        Alimentos(double precioX, std::string nombreX)
        {
            precio = precioX;
            nombre = nombreX;
        }
        double getPrecio()
        {
            return precio;
        }
        std::string getNombre()
        {
            return nombre;
        }
        
        virtual void imprimirAlimento() = 0;
};

class Alitas : public Alimentos {
    private:
        std::string salsa;
    public:
        Alitas()
        {
            salsa = "";
        }
        Alitas(std::string salsaX, double precioX, std::string nombreX) : Alimentos(precioX, nombreX)
        {
            salsa = salsaX;
        }
        std::string getSalsa()
        {
            return salsa;
        }
        void imprimirAlimento(){
            cout << setprecision(2) << fixed << "Alimento: " << getNombre() << "\n Precio: " << getPrecio() << "\n Salsa: " << getSalsa() << "\n";
        }
};

class PapasFrancesa : public Alimentos {
    public:
        PapasFrancesa(){}
        PapasFrancesa(double precioX, std::string nombreX) : Alimentos(precioX, nombreX){}
        void imprimirAlimento(){
            cout << setprecision(2) << fixed << "Alimento: " << getNombre() << "\n Precio: " << getPrecio() << "\n";
        }
};

class Banderillas : public Alimentos {
    public: 
        Banderillas(){}
        Banderillas(double precioX, std::string nombreX) : Alimentos(precioX, nombreX){}
        void imprimirAlimento(){
            cout << setprecision(2) << fixed << "Alimento: " << getNombre() << "\n Precio: " << getPrecio() << "\n";
        }
};

class Cliente
{
    private:
        std::string nombreCompleto;
        int idCliente;
        int maxSizeLista;
        int contProductosComprados;
        std::string* listaNombresProductosComprados;
        double totalGastado;
        Cliente();
    
    public:
        Cliente(std::string nombreCompletoP, int idClienteP);
        std::string getNombreCompleto();
        int getIdCliente();
        double getTotalGastado();
        void incrementarTotalGastado(double cantidadGastada);
        void agregarProductoComprado(string nombreProducto);
};

class Restaurante {
    private: 
        int contadorAlitasEnStock;
        int contadorPapasFrancesaEnStock;
        int contadorBanderillasEnStock;


        string direccion;
    
        Alitas instanciaAlitas;
        PapasFrancesa instanciaPapas;
        Banderillas instanciaBanderillas;

        vector<string> cpEntregas;
    
    public:
        Restaurante(int stockAlimentos, string direccion_){
            contadorAlitasEnStock = stockAlimentos;
            contadorPapasFrancesaEnStock = stockAlimentos;
            contadorBanderillasEnStock = stockAlimentos;

            direccion = direccion_;
   

            instanciaAlitas = Alitas("BBQ", 75.00, "Alitas Mario");
            instanciaPapas = PapasFrancesa(47.50, "Papas Felices");
            instanciaBanderillas = Banderillas(68.00, "Banderillas Don Luigi");

            cpEntregas = vector<string>{"02420", "02419", "02421"};
        }
    
        void imprimirMenu(){
            instanciaPapas.imprimirAlimento();
            instanciaAlitas.imprimirAlimento();
            instanciaBanderillas.imprimirAlimento();
        }

        void imprimirDireccion() {
            cout << "Direccion: " << direccion << endl;
        }

        int getContadorPapasEnStock(){
            return contadorPapasFrancesaEnStock;
        }
        int getContadorAlitasEnStock(){
            return contadorAlitasEnStock;
        }
        int getContadorBanderillasEnStock(){
            return contadorBanderillasEnStock;
        }

        void setStockPapas(int stock) {
            contadorPapasFrancesaEnStock = stock;
        }

        void setStockAlitas(int stock) {
            contadorAlitasEnStock = stock;
        }

        void setStockBanderillas(int stock) {
            contadorBanderillasEnStock = stock;
        }
        
        // regresa 1 si se puede llevar a ese código postal, 0 si no
        int sePuedeLlevar(string codigoPostal) {
            return (find(cpEntregas.begin(), cpEntregas.end(), codigoPostal) != cpEntregas.end());
        }
};
