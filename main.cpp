#include <iostream>
#include "restaurante.hpp"
#include "ordenes.hpp"
#include <string>
#include <stdio.h>

using namespace std;

char choice,choice2,choice3, continuar, menuChoice;

Ordenes ordenes;
Restaurante restaurante(5, "Banderillas Don Luigi, Azcapotzalco 21");

void metodoCliente();
void actualizarInventario();
void revisarInventario();

int main()
{
    // AQUI VA EL CICLO
    do {
        cout << "Introduzca el numero de su seleccion:\n1. Cliente\n2. Propetario\n3. Salir\n\nOpcion: ";
        cin >> choice;

        #if defined(_WIN32)
            system("cls");
        #elif __APPLE__
            system("clear");
        #endif
        
        switch (choice)
        {
        //1. Cliente
        case ('1'):
        {
            metodoCliente();
            break;
        }
        // Dueño
        case '2':
            cout << "\nPropietario\n1. Ver estado de ordenes\n2. Completar Orden\n3. Actualizar inventario\n4. Ver inventario\n5. Regresar a Menu Principal\n\nOpcion: ";            
            cin >> choice3;
            switch (choice3)
            {
                // Ver estado de ordenes
                case '1':
                    ordenes.imprimirOrdenes();
                    break;

                // Completar Orden
                case '2':
                    ordenes.completarOrden();
                    cout << "Ordenes despues de completar la primera orden:\n\n";
                    ordenes.imprimirOrdenes();
                    break;

                case '3':
                    actualizarInventario();
                    break;
                
                case '4':
                    revisarInventario();
                    break;
            }
            break;
        // Ordenar
        case '3':
            break;
        default:
            cout << "Ha ingresado una opción incorrecta\n\n";
        }
    } while(choice != '3');

    ordenes.liberarMemoria();
}

void metodoCliente() {
    // para recoger o a domicilio?
    char metEnt;
    string codigoPostal = "";
    string direccion = "";
    cout << "La orden seria para recoger (r) o a domicilio (d)? ";
    cin >> metEnt;

    // si es a domicilio, revisar si se entrega a ese C.P.
    if (metEnt == 'd') {
        cout << "¿Cual es tu codigo postal? ";
        cin >> codigoPostal;
        if (!restaurante.sePuedeLlevar(codigoPostal)) {
            cout << "No hacemos entregas a ese domicilio...\n"
                    << "¿Quieres hacer una orden para recoger?\n"
                    << "(s/n): ";
            cin >> continuar;

            if (continuar == 'n') return;
        }

        cout << "¿Cual es tu direccion? ";
        cin.ignore();
        getline(std::cin, direccion);
    }

    string nombre;
    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(std::cin, nombre);

    // hacer la orden
    unordered_map<string, int> itemsPedido = {
        {"Papas", 0},
        {"Alitas", 0},
        {"Banderillas", 0},
    };

    int cantidad, total = 0;

    cout << "Menu:\n";
    restaurante.imprimirMenu();
    cout << endl;

    int stock;

    stock = restaurante.getContadorPapasEnStock();
    do {
        cout << "¿Cuantas papas quieres? Máximo: " << stock << endl;
        cin >> cantidad;
        itemsPedido["Papas"] = cantidad;
    } while (stock < cantidad);
    total += cantidad;

    stock = restaurante.getContadorAlitasEnStock();
    do {
        cout << "¿Cuantas alitas quieres? Máximo: " << stock << endl;
        cin >> cantidad;
        itemsPedido["Alitas"] = cantidad;
    } while (stock < cantidad);
    total += cantidad;

    stock = restaurante.getContadorBanderillasEnStock();
    do {
        cout << "¿Cuantas banderillas quieres? Máximo: " << stock << endl;
        cin >> cantidad;
        itemsPedido["Banderillas"] = cantidad;
    } while (stock < cantidad);
    total += cantidad;

    if (total == 0) {
        cout << "Tu orden no puede estar vacia...\n";
        return;
    }

    cout << endl << "Confirmar orden...\n";
    cout << "Papas: " << itemsPedido["Papas"] << endl;
    cout << "Alitas: " << itemsPedido["Alitas"] << endl;
    cout << "Banderillas: " << itemsPedido["Banderillas"] << endl;

    cout << "Confirmar (s/n): ";
    cin >> continuar;

    if (continuar == 'n') {
        cout << "Orden cancelada\n";
        return;
    }

    string metodoDeEntrega = (metEnt == 'd') ? "domicilio" : "recoger";
    Orden* newOrden = new Orden(direccion, codigoPostal, nombre, itemsPedido, metodoDeEntrega);
    ordenes.agregarOrden(newOrden);

    restaurante.setStockAlitas(restaurante.getContadorAlitasEnStock() - itemsPedido["Alitas"]);
    restaurante.setStockPapas(restaurante.getContadorPapasEnStock() - itemsPedido["Papas"]);
    restaurante.setStockBanderillas(restaurante.getContadorBanderillasEnStock() - itemsPedido["Banderillas"]);

    cout << "Orden Confirmada!\n" << "Gracias por su compra\n\n\n";
}

void actualizarInventario() {
    cout << endl << endl << "Actualizar el inventario:\n";
    
    int stock;

    cout << "¿Cuantas papas hay en inventario? ";
    cin >> stock;
    restaurante.setStockPapas(stock);
    cout << endl;

    cout << "¿Cuantas alitas hay en inventario? ";
    cin >> stock;
    restaurante.setStockAlitas(stock);
    cout << endl;

    cout << "¿Cuantas banderillas hay en inventario? ";
    cin >> stock;
    restaurante.setStockBanderillas(stock);
    cout << endl;
}

void revisarInventario() {
    cout << "Papas en inventario: " << restaurante.getContadorPapasEnStock() << endl;
    cout << "Alitas en inventario: " << restaurante.getContadorAlitasEnStock() << endl;
    cout << "Banderillas en inventario: " << restaurante.getContadorBanderillasEnStock() << endl;
}