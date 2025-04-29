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