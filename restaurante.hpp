#include <iostream>
#include <string>

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
        
        virtual std::string imprimirAlimento() = 0;
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
        std::string imprimirAlimento(){
            return "Alimento: " + getNombre() + "\n Precio: " + getPrecio() + "\n Salsa: " + getSalsa() + "\n";
        }
};

class PapasFrancesa : public Alimentos {
    public:
        PapasFrancesa(){}
        PapasFrancesa(double precioX, std::string nombreX) : Alimentos(precioX, nombreX){}
        std::string imprimirAlimento(){
            return "Alimento: " + getNombre() + "\n Precio: " + getPrecio() + "\n Salsa: " + "\n";
        }
};

class Banderillas : public Alimentos {
    public: 
        Banderillas(){}
        Banderillas(double precioX, std::string nombreX) : Alimentos(precioX, nombreX){}
        std::string imprimirAlimento(){
            return "Alimento: " + getNombre() + "\n Precio: " + getPrecio() + "\n Salsa: " + "\n";
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


Cliente::Cliente(std::string nombreCompletoP, int idClienteP)
{
    nombreCompleto = nombreCompletoP;
    idCliente = idClienteP;
    maxSizeLista = 5;               
    contProductosComprados = 0;    
    listaNombresProductosComprados = new std::string[maxSizeLista]; 
}

void Cliente::agregarProductoComprado(string nombreProducto)
{
    listaNombresProductosComprados[contProductosComprados] = nombreProducto;
    contProductosComprados++;
}

void Cliente::incrementarTotalGastado(double cantidadGastada)
{
    totalGastado +=cantidadGastada;
}

std::string Cliente::getNombreCompleto()
{
    return nombreCompleto;
}

double Cliente::getTotalGastado()
{
    return totalGastado;
}

int Cliente::getIdCliente()
{
    return idCliente;
}


class Restaurante {
    private: 
        int minStock;
        int contadorAlitasEnStock;
        int contadorPapasFrancesaEnStock;
        int contadorBanderillasEnStock;
    
        Alitas** listaAlitas;
        PapasFrancesa** listaPapas;
        Banderillas** listaBanderillas;
        Cliente** listaClientes;
    
    public:
        Restaurante(int minStockP){
            minStock = minStockP;
            contadorAlitasEnStock = 0;
            contadorPapasFrancesaEnStock = 0;
            contadorBanderillasEnStock = 0;
            
            listaAlitas = new Alitas*[minStock];
            listaPapas = new PapasFrancesa*[minStock];
            listaBanderillas = new Banderillas*[minStock];
            
            maxSizeListaClientes = 5;       
            contClientesAgregados = 0;      
            listaClientes = new Cliente*[maxSizeListaClientes]; 
        }
    
        void imprimirMenu(){
            listaAlitas[0] -> imprimirAlimento();
            std::cout "Alitas - cantidad de ordenes disponibles: " << contadorAlitasEnStock << std::endl;
            listaPapas[0] -> imprimirAlimento();
            std::cout "Papas a la francesa - cantidad de ordenes disponibles: " << contadorPapasFrancesaEnStock << std::endl;
            listaBanderillas[0] -> imprimirAlimento();
            std::cout "Bnaderillas - cantidad de ordenes disponibles: " << contadorBanderillasEnStock << std::endl;
        }
    
        void agregarPapas(PapasFrancesa* d){
            listaPapas[contadorPapasFrancesaEnStock] = d;
            contadorPapasFrancesaEnStock++;
        }
        void agregarAlitas(Alitas* d){
            listaAlitas[contadorAlitasEnStock] = d;
            contadorAlitasEnStock++;
        }
        void agregarBanderillas(Banderillas *d){
            listaBanderillas[contadorBanderillasEnStock] = d;
            contadorBanderillasEnStock++;
        }
        
        int getMinStock(){
            return minStock;
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
        
        // regresa 1 si se puede llevar a ese código postal, 0 si no
        int sePuedeLlevar(Cliente* cliente) {
            if (cliente -> getIdCliente() == 02420 || cliente -> getIdCliente() == 02419){
                listaClientes[contClientesAgregados]=cliente;
                contClientesAgregados++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        

};
