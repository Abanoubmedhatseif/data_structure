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
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Queue() {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->pNext = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node<T>* temp = front;
        front = front->pNext;
        delete temp;
        size--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void print() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
        } else {
            Node<T>* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->pNext;
            }
            cout << endl;
        }
    }

    int getSize() {
        return size;
    }

    ~Queue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->pNext;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    Queue<int> myQueue;
    myQueue.enqueue(50);
    myQueue.enqueue(60);
    myQueue.enqueue(15);
    myQueue.enqueue(5);
    myQueue.enqueue(98);

    myQueue.print();

    myQueue.dequeue();
    myQueue.print();

    cout << "Queue size: " << myQueue.getSize() << endl;

    return 0;
}
