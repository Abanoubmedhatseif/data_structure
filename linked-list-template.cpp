#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* pNext;

    Node() {
        data = T();
        pNext = nullptr;
    }

    Node(T data) {
        this->data = data;
        pNext = nullptr;
    }
}; // end Node class

template <typename T>
class linkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    linkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->pNext = newNode;
            tail = tail->pNext;
        }
        size++;
    }

    void print() {
        if (size == 0) {
            cout << "List is Empty" << endl;
        } else {
            Node<T>* current = head;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->pNext;
            }
        }
    }

    void deleteNode(T value) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->pNext;
        }

        if (current == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->pNext;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            prev->pNext = current->pNext;
            if (current == tail) {
                tail = prev;
            }
        }
        cout << "Node with value " << value << " was deleted." << endl;
        delete current;
        size--;
    }

}; // end linked list class



int main() {
    linkedList<int>* mylist = new linkedList<int>();
    mylist->insert(50);
    mylist->insert(60);
    mylist->insert(15);
    mylist->insert(5);
    mylist->insert(98);

    
    // mylist->deleteNode(45);
    // mylist->deleteNode(60);

    mylist->print();


    return 0;
} // end main
