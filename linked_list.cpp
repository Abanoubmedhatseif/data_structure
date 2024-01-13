#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* pNext;

    Node(){
        data=0;
        pNext=nullptr;
    }

    Node(int data){
        (*this).data=data;
        // same as this->data=data;
        pNext=nullptr;
    }
};

class linkedList {
    public:
    Node* head;
    Node* tail;
    int size;

    linkedList(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }

        void insert(int data){
            Node* newNode = new Node(data);
            if (head == nullptr){
                head = newNode;
                tail = head;
            }
            else {
                tail->pNext=newNode;
                tail = tail->pNext;
            }
                size++ ;
        }

        void print(){
            if (size == 0){
                cout<<"List is Empty"<<endl;
            }
            else {
                Node* current = head ;
                while (current != NULL){
                    cout<<current->data<<endl;
                    current = current->pNext;
                }
            }
        }


        void deleteNode(int value) {
                Node* current = head;
                Node* prev = nullptr;

                while (current != nullptr && current->data != value) {
                    prev = current;
                    current = current->pNext;
                }

                if (current == nullptr) {
                    cout << "Node with value " << value << " not found." <<endl;
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
                cout << "Node with value " << value << " was deleted." <<endl;
                delete current;
                size--;
            }
};



int main() {
    

linkedList * mylist = new linkedList();
mylist->insert(50);
mylist->insert(60);
mylist->insert(15);
mylist->insert(5);
mylist->insert(98);

//mylist->deleteNode(45);
mylist->deleteNode(60);

mylist->print();






return 0;}