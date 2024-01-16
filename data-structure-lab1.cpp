#include <iostream>
using namespace std ;

void swapInt (int &x , int &y);
void sortSelection (int arr[], int size) ;
void sortBubbleStruct (int arr[], int size);
void printIntArray (int arr[],int size);
void printStringArray (string arr[],int size);


struct employee {
    int id ;
    string name ;
    string address ;
};

void sortBubbleStruct (employee arr[], int size);
void printEmployeeID (employee arr[],int size);

int main() {

//int intArray[] = {123,15,14,23,10};

//sortSelection(intArray,5);
//sortBubbleStruct(intArray,5);
//printIntArray(intArray,5);


employee Employees[5] {
    {923,"ahmed","ainshams"},
    {567,"abanoub","hamada"},
    {6854,"ubeaf","orufsf"},
    {999,"esfks","fsr"},
    {84,"aekfjb","afek"}
};

sortBubbleStruct (Employees,5);
printEmployeeID (Employees, 5);





    return 0;
}





void swapInt (int &x , int &y) {
    int temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

void swapIntSring (string &x , string &y) {
    string temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

void swapStruct (employee &x , employee &y) {
    employee temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

void printStringArray (string arr[],int size)
{
    for (int i=0 ; i<size ; i++)
        {
            cout<<i+1<<"."<<arr[i]<<endl;
        };
}

void printIntArray (int arr[],int size)
{
    for (int i=0 ; i<size ; i++)
        {
            cout<<i+1<<"."<<arr[i]<<endl;
        };
}


void sortSelection (int arr[], int size) 
{
        for (int j = 0; j < size-1 ; j++)
        {
            int minIndex=j ;

            for (int i = j+1 ; i < size; i++){
                if ( arr[i] < arr[minIndex] )
                {
                    minIndex = i ;
                }
            }
        swap(arr[j],arr[minIndex]);
        }
}


void sortBubbleStruct (employee arr[], int size){
    for (int i=0 ; i<size-1 ; i++){
        for (int j = 0 ; j< size-1-i ; j++ ){
            if ((arr[j].id)>(arr[j+1].id)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printEmployeeID (employee arr[],int size)
{
    for (int i=0 ; i<size ; i++)
        {
            cout<<i+1<<"."<<arr[i].id<<endl;
        };
}






