#include <iostream>
#include "restaurante.hpp"
#include "ordenes.hpp"

using namespace std;

int main() {
    Ordenes ordenes;
    Restaurante restaurante;
    // AQUI VA EL CICLO

    /*
    1. Preguntar si es cliente o dueño
    
    Cliente:
    1. Ver el menú. 
        restaurante.imprimirMenu();
    2. Para recoger o domicilio?
    3. Dirección y código postal.
        3.1 Si es a domicilio, revisar el código postal. Restaurante va a tener una funcion para eso

        3.2 Si no se entrega, ofrecer que sea la orden para recoger
    4. Orden.
        Orden* nuevaOrden = new Orden()
    5. Confirmar pedido -> Dar tiempo estimado
    6. Agregar orden a ordenes
        ordenes.agregarOrden(&orden);

    Dueño:
    1. Ver estado de ordenes o completar órden:
        Ver ordenes: 
            ordenes.imprimirOrdenes();
        Completar órden:
            ordenes.completarOrden();

    */

    ordenes.liberarMemoria();
}