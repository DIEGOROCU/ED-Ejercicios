#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>
#include <string>

class ListLinkedDouble
{
private:
    struct Node
    {
        int value;
        Node *next;
        Node *prev;
    };

public:
    ListLinkedDouble() : num_elems(0)
    {
        head = new Node;
        head->next = head;
        head->prev = head;
    }

    ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble()
    {
        copy_nodes_from(other);
        num_elems = other.num_elems;
    }

    ~ListLinkedDouble() { }

    void push_front(const int &elem)
    {
        Node *new_node = new Node{elem, head->next, head};
        head->next->prev = new_node;
        head->next = new_node;
        num_elems++;
    }

    void push_back(const int &elem)
    {
        Node *new_node = new Node{elem, head, head->prev};
        head->prev->next = new_node;
        head->prev = new_node;
        num_elems++;
    }

    void pop_front()
    {
        assert(num_elems > 0);
        Node *target = head->next;
        head->next = target->next;
        target->next->prev = head;
        delete target;
        num_elems--;
    }

    void pop_back()
    {
        assert(num_elems > 0);
        Node *target = head->prev;
        target->prev->next = head;
        head->prev = target->prev;
        delete target;
        num_elems--;
    }

    int size() const { return num_elems; }

    bool empty() const { return num_elems == 0; };

    const int &front() const
    {
        assert(num_elems > 0);
        return head->next->value;
    }

    int &front()
    {
        assert(num_elems > 0);
        return head->next->value;
    }

    const int &back() const
    {
        assert(num_elems > 0);
        return head->prev->value;
    }

    int &back()
    {
        assert(num_elems > 0);
        return head->prev->value;
    }

    const int &operator[](int index) const
    {
        assert(0 <= index && index < num_elems);
        Node *result_node = nth_node(index);
        return result_node->value;
    }

    int &operator[](int index)
    {
        assert(0 <= index && index < num_elems);
        Node *result_node = nth_node(index);
        return result_node->value;
    }

    ListLinkedDouble &operator=(const ListLinkedDouble &other)
    {
        if (this != &other)
        {
            delete_nodes();
            head = new Node;
            head->next = head->prev = head;
            copy_nodes_from(other);
            num_elems = other.num_elems;
        }
        return *this;
    }

    void display(std::ostream &out) const;
    void display() const { display(std::cout); }
    void display_reverse(std::ostream &out) const;
    void display_reverse() const { display_reverse(std::cout); }

    void swap2by2();
    void zip(ListLinkedDouble &other);

    void detach(Node *node);
    void attach(Node *node, Node *position);
    void partition(int pivot);

private:
    Node *head;
    int num_elems;

    Node *nth_node(int n) const;
    void delete_nodes();
    void copy_nodes_from(const ListLinkedDouble &other);
};

ListLinkedDouble::Node *ListLinkedDouble::nth_node(int n) const
{
    int current_index = 0;
    Node *current = head->next;

    while (current_index < n && current != head)
    {
        current_index++;
        current = current->next;
    }

    return current;
}

void ListLinkedDouble::delete_nodes()
{
    Node *current = head->next;
    while (current != head)
    {
        Node *target = current;
        current = current->next;
        delete target;
    }

    delete head;
}

void ListLinkedDouble::copy_nodes_from(const ListLinkedDouble &other)
{
    Node *current_other = other.head->next;
    Node *last = head;

    while (current_other != other.head)
    {
        Node *new_node = new Node{current_other->value, head, last};
        last->next = new_node;
        last = new_node;
        current_other = current_other->next;
    }
    head->prev = last;
}

void ListLinkedDouble::display(std::ostream &out) const
{
    out << "[";
    if (head->next != head)
    {
        out << head->next->value;
        Node *current = head->next->next;
        while (current != head)
        {
            out << ", " << current->value;
            current = current->next;
        }
    }
    out << "]";
}

void ListLinkedDouble::display_reverse(std::ostream &out) const
{
    out << "[";
    if (head->prev != head)
    {
        out << head->prev->value;
        Node *current = head->prev->prev;
        while (current != head)
        {
            out << ", " << current->value;
            current = current->prev;
        }
    }
    out << "]";
}

std::ostream &operator<<(std::ostream &out, const ListLinkedDouble &l)
{
    l.display(out);
    return out;
}

void ListLinkedDouble::swap2by2()
{
    Node *current = head->next;
    while (current != head && current->next != head)
    {
        // Guardamos el otro nodo
        Node *siguiente = current->next;

        // Actualizamos los nodos exteriores al par
        current -> prev -> next = siguiente;
        siguiente -> next -> prev = current; 

        current -> next = siguiente -> next; // Next del actual
        siguiente -> prev = current->prev;   // Prev del siguiente
        current -> prev = siguiente;         // Prev del actual
        siguiente -> next = current;         // Next del siguiente
        
        // Pasar al siguiente par
        current = current->next;
    }
}

void ListLinkedDouble::zip(ListLinkedDouble &other)
{
    Node *current = head->next;
    Node *current_other = other.head->next;
    while (current != head && current_other != other.head)
    {
        // Guardamos los siguientes nodos
        Node *siguiente = current->next;
        Node *siguiente_other = current_other->next;

        // Actualizamos los nodos exteriores al par
        siguiente -> prev = current_other;

        // Insertamos el nodo de la otra lista
        current_other -> prev = current;
        current_other -> next = siguiente;

        // Actualizamos el nodo actual
        current -> next = current_other;

        // Pasamos al siguiente par
        current = siguiente;
        current_other = siguiente_other;
    }
    // Añadimos los nodos restantes de la otra lista
    if (current_other != other.head)
    {
        Node *last = head->prev;
        Node *first = current_other;
        Node *last_other = other.head->prev;

        last -> next = first;
        first -> prev = last;
        head -> prev = last_other;
        last_other -> next = head;
    }
       
}

void ListLinkedDouble::detach(Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    num_elems--;
}

void ListLinkedDouble::attach(Node *node, Node *position)
{
    node->next = position;
    node->prev = position->prev;
    position->prev->next = node;
    position->prev = node;
    num_elems++;
}

void ListLinkedDouble::partition(int pivot)
{
    Node *current = head->next;
    Node *first_greater = head;
    while (current != head)
    {
        if (current->value <= pivot)
        {
            if (first_greater != head)
            {
                Node *next = current->next;
                detach(current);
                attach(current, first_greater);
                current = next;
            }
            else
            {
                current = current->next;
            }
        }
        else
        {
            if (first_greater != head)
            {
                current = current->next;
            }
            else
            {
                first_greater = current;
                current = current->next;
            }
        }
    }
}

#endif