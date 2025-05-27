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

    Node* burbuja(Node* fin){
    
        Node* actual = head->next;
        Node* prev = head;
        if (actual == fin) return nullptr;
        while (actual->next != fin){
            if (actual->value > actual->next->value){
                Node* sig = actual->next;
                actual->next = sig->next;
                sig->next = actual;
                prev->next = sig;

                prev = sig;
            }
            else {
                prev = actual;
                actual = actual->next;
            }
        }
        return actual;

    }

    int burb(){
        Node* a = burbuja(nullptr);
        return a->value;
    }
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