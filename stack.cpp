#include <iostream>
using namespace std;

template <class T>

class Node
{
public:
    Node<T> *next;
    T data;

    Node<T>(){
        next = nullptr;
        data = T();
    }

    Node<T>(T d){
        next = nullptr;
        data = d;
    }
};

template <class T>

class Stack{
public:
    Node<T> *pHead;
    int size;

    Stack(){
        pHead = nullptr;
        size = 0;
    }

    Stack(T d){
        Node<T> *newNode = new Node<T>(d);
        pHead = newNode;
        size++;
    }

 ~Stack(){
    while (pHead != nullptr)
    {
        Node<T> *ptr = pHead;
        pHead = pHead->next;
        delete ptr;
    }
    }


    Stack(const Stack<T> &myStack){
        this->pHead = nullptr;
        size = 0;
        Node<T> *curr = current.pHead;
        while (curr != nullptr)
        {
            push(curr->data);
            curr = curr->next;
        }
    }

    void push(T d)
    {
        Node<T> *newNode = new Node<T>(d);

        if (pHead == nullptr)
        {
            pHead = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = pHead;
            pHead = newNode;
        }

        size++;
    }

    T pop()
    {
        if (pHead == nullptr)
        {
            cout << "Empty Stack" << endl;
            return T();
        }
        else
        {
            Node<T> *pdel = pHead;
            pHead = pHead->next;
            T poppedData = pdel->data;
            delete pdel;
            size--;
            return poppedData;
        }
    }

    void display()
    {
        if (pHead == nullptr)
        {
            cout << "Nothing to display" << endl;
        }
        Node<T> *ptr = pHead;
        while (ptr != nullptr)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
        cout << endl;
    }

    
};

int main(){





return 0;
}