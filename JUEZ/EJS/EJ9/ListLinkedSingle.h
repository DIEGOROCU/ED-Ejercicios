#include <iostream>

using namespace std;

class ListLinkedSingle
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head = nullptr;

public:
    void duplicate();
    void push_back(int value);
    void print();
    void reverse();
    void reverse_segment(int index, int length);
    void intersect(ListLinkedSingle &other);
};

void ListLinkedSingle::duplicate()
{
    Node *current = head;
    while (current != nullptr) {
        Node *newNode = new Node;
        newNode->value = current->value;
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
}

void ListLinkedSingle::push_back(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void ListLinkedSingle::print()
{
    cout << "[";
    Node *current = head;
    while (current != nullptr) {
        cout << current->value;
        current = current->next;
        if (current != nullptr) {
            cout << ", ";
        }
    }
    if (current != nullptr) {
        cout << current->value;
    }
    cout << "]" << endl;
}

void ListLinkedSingle::reverse()
{
    // Variables auxiliares
    Node *anterior = nullptr;
    Node *current = head;
    Node *siguiente = nullptr;
    while (current != nullptr) {
        // Cambiamos el puntero next del nodo actual
        siguiente = current->next;
        current->next = anterior;
        // Avanzamos los punteros
        anterior = current;
        current = siguiente;
    }
    head = anterior;
}

void ListLinkedSingle::reverse_segment(int index, int length)
{
    // Variables auxiliares
    Node *anterior = nullptr;
    Node *current = head;
    Node *siguiente = nullptr;
    int i = 0;
    while (current != nullptr && i < index) {
        anterior = current;
        current = current->next;
        siguiente = current->next;
        i++;
    }
    bool hayAnterior = anterior != nullptr;
    Node *antesInvertir = anterior;
    Node *principio = current;
    // Invertimos el segmento
    while (current != nullptr && i < index + length) {
        // Cambiamos el puntero next del nodo actual
        siguiente = current->next;
        current->next = anterior;
        // Avanzamos los punteros
        anterior = current;
        current = siguiente;
        i++;
    }
    // Ajustamos los extremos del segmento invertido
    if (hayAnterior){
        antesInvertir -> next = anterior;
    }
    else {
        head = anterior;
    }
    principio -> next = current;
}

void ListLinkedSingle::intersect(ListLinkedSingle &other)
{
    if (head == nullptr || other.head == nullptr){
        head = nullptr;
        return;
    }

    // Variables auxiliares
    Node *current = head;
    Node *currentOther = other.head;
    Node *anterior = nullptr;
    // Recorremos ambas listas
    while (current != nullptr && currentOther != nullptr) {
        // Si la lista actual tiene un valor mayor, avanzamos la otra lista para que coincidan o se adelante, lo que significa que hay que eliminar el nodo
        if (current->value > currentOther-> value){
            currentOther = currentOther->next;
        }
        // Si la lista actual tiene un valor menor, eliminamos el nodo actual, ya que se ha pasado de largo
        else if (current->value < currentOther->value){
            // Distintos casos para eliminar el nodo actual dependiendo de si es el primero o no
            Node *temp = current;
            current = current -> next;
            if (anterior == nullptr){
                head = current;
            }
            else {
                anterior -> next = current;
            }
            delete temp;
        }
        // Si los valores son iguales, avanzamos en ambas listas
        else {
            anterior = current;
            current = current -> next;
            currentOther = currentOther -> next;
        }
    }
    // Eliminamos el resto de nodos de la lista actual si es que quedan
    while (current != nullptr){
        Node *temp = current;
        current = current -> next;
        if (anterior == nullptr){
            head = current;
        }
        else {
            anterior -> next = current;
        }
        delete temp;
    }
}