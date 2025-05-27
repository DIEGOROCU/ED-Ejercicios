#include <iostream>
using namespace std;

class ListLinkedSingle {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v = 0, Node* n = nullptr) : value(v), next(n) {}
    };
    Node* head; // Nodo fantasma

public:
    ListLinkedSingle() {
        head = new Node(); // Nodo fantasma, no almacena datos útiles
    }

    ~ListLinkedSingle() {
        clear();
        delete head;
    }

    void push_back(int value) {
        Node* curr = head;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = new Node(value);
    }

    void push_front(int value) {
        Node* n = new Node(value, head->next);
        head->next = n;
    }

    void pop_front() {
        if (head->next == nullptr) return;
        Node* tmp = head->next;
        head->next = tmp->next;
        delete tmp;
    }

    bool empty() const {
        return head->next == nullptr;
    }

    void clear() {
        Node* curr = head->next;
        while (curr != nullptr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
        head->next = nullptr;
    }

    void print() const {
        Node* curr = head->next;
        cout << "[";
        while (curr != nullptr) {
            cout << curr->value;
            curr = curr->next;
            if (curr != nullptr) cout << ", ";
        }
        cout << "]" << endl;
    }
};