#include "orden.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

struct qNode {
    Orden* value;
    struct qNode* next;
};

// clase para manejar las ordenes
class Ordenes {
    private:

    struct qNode* head;
    struct qNode* tail;

    public: 

    Ordenes() {
        head = NULL;
        tail = NULL;
    }

    void agregarOrden(Orden* orden) {
        // asignar un nodo a la orden
        struct qNode* nuevaOrden = (struct qNode*) malloc(sizeof(struct qNode));
        
        if (nuevaOrden == nullptr) {
            cout << "Error: no se pudo asignar memoria para la orden\n";
        }

        nuevaOrden->value = orden;
        nuevaOrden->next = nullptr;

        // si la cola esta vacia, la cabeza y la cola apuntan al nuevo nodo
        if (head == nullptr) {
            head = nuevaOrden;
            tail = nuevaOrden;
        } else {
            // si la cola no esta vacia, el nodo siguiente de la cola apunta al nuevo nodo
            tail->next = nuevaOrden;
            // la cola apunta al nuevo nodo
            tail = nuevaOrden;
        }
    }

    void completarOrden() { // función para eliminar la primera orden de la fila
        // checar si la cola esta vacia
        if (head == nullptr) {
            cout << "Error: no hay ordenes en la cola\n";
            return;
        } 

        // eliminar el nodo al que head apunta
        struct qNode* tmp = head;
        head = head->next;
        free(tmp);

        // si la cola esta vacia, tail apunta a null
        if (head == nullptr) {
            tail = nullptr;
        }

        cout << "Orden entregada\n";
    }

    void imprimirOrdenes() {
        cout << "\nOrdenes en el órden en el que entraron:\n\n";

        struct qNode* tmp = head;
        while (tmp != nullptr) {
            tmp->value->imprimirOrden();
            cout << "--------------------------------------------------------------------\n\n";
            tmp = tmp->next;
        }

        cout << "Fin de la lista de ordenes\n\n";
    }

    void liberarMemoria() {
        struct qNode* tmp = head;
        while (tmp != nullptr) {
            struct qNode* tmp2 = tmp;
            tmp = tmp->next;
            free(tmp2);
        }
    }
};