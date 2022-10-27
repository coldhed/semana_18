#include <iostream>
#include "restaurante.hpp"
#include "ordenes.hpp"
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int choice,choice2,choice3;

int main()
{
    system("color f8");
    Ordenes ordenes;
    Restaurante restaurante;
    // AQUI VA EL CICLO
    do{
    system("cls");
    cout << "Introduzca el numero de su seleccion:\n1. Cliente\n2. Propetario\n3. Salir" << endl;
    cin >> choice;
    
    switch (choice)
    {
    //1. Cliente
    case 1:
            do{
            cout << "\nCliente\n1. Ver el menu\n2. Recoger aqui\n3. Servicio a domicilio\n4. Ordenar\n5. Agregar a orden\n6. Confirmar Pedido\n7. Ir a Propetario\n";
            cin >> choice2;
            switch (choice2)
            {
                // 1. Ver el menu
                case 1:
                        // restaurante.imprimirMenu();
                        // los couts es para ver si sirven los case #
                        cout << "restaurante.imprimirMenu()";
                // 2. Recoger aqui
                case 2:
                        cout << "funcion pasar el dato de tipo de entrega";
                // 3. Servicio a domicilio
                case 3:
                        cout <<"funcion pasar el dato de tipo de entrega";
                // 4. Orden
                case 4:
                        cout << "Orden* nuevaOrden = new Orden()";
                // 5. Agregar orden a ordenes
                case 5:
                        cout << "ordenes.agregarOrden(&Orden)";
                // 6. Confirmar Pedido
                case 6:
                        cout << "Dar tiempo estimado";
                // 7. Ir a propetario
                case 7:
                break;
            }
            }while(choice2!=7);
    // Dueño
    case 2:
            do{
            cout << "\nPropietario\n1. Ver estado de ordenes\n2. Completar Orden\n3. Regresar a Menu Principal\n";            
            cin >> choice3;
            switch (choice3)
            {
                // Ver estado de ordenes
                case 1:
                        cout << "ordenes.imprimirOrdenes()";
                // Completar Orden
                case 2:
                        cout << "ordenes.completarOrden()";
                // Regresar Menu Principal
                case 3:
                break;
            }
            }while(choice3!=3);
    // Ordenar
    case 3:
    break;
    default:
        cout << "Ha ingresado una opción incorrecta";
    }
    }while(choice!=3);

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

    //ordenes.liberarMemoria();
}
