#include <iostream>
using namespace std;

struct employee {
    int id ;
    string name ;
    int salary ;
};


template <typename T >
void swapCustom (T &x , T &y) {
    T temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

void printIntArray (int arr[],int size)
{
    for (int i=0 ; i<size ; i++)
        {
            cout<<arr[i]<<endl;
        }
}


int sortOnce (int arr[], int LB , int UB) {
    int Start,End,Pivot;
    Pivot=LB;
    Start=LB;
    End=UB;
    while (Start<End)
        {
            while((arr[Start]<=arr[Pivot])) {
                Start++;
            }
            while (arr[End]>arr[Pivot]) {
                End--;
            }
            if(Start<End) {
                 swapCustom (arr[Start],arr[End]);
            }
        }
    swapCustom (arr[Pivot],arr[End]);
    return End;
}


void quickSort(int arr[],int LB,int UB)
{
    if(LB<UB){
        int partition_location= sortOnce (arr,LB,UB);
        quickSort(arr,LB,partition_location-1);
        quickSort(arr,partition_location+1,UB);
    }
}


void mergeInside (int arr[],int start,int mid,int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int *A1 = new int[size1];
    int *A2 = new int[size2];
    int i, j;
    for (int i = 0; i < size1; i++)
    {
        A1[i] = arr[start + i];
    }
    for (int j = 0; j < size2; j++)
    {
        A2[j] = arr[mid + 1 + j];
    }
    i = j = 0;
    int k = start;
    while ((i < size1) && (j < size2))
    {
        if (A1[i] < A2[j])
        {
            arr[k] = A1[i];
            i++;
        }
        else
        {
            arr[k] = A2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        arr[k] = A1[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        arr[k] = A2[j];
        k++;
        j++;
    }
}


void MergeSort(int arr[],int start,int end)
{
if(start<end)
{
int mid=(start + end)/2;
MergeSort(arr,start,mid);
MergeSort(arr,mid+1,end);
mergeInside(arr,start,mid,end);
}
}


int searchLinear (int arr [],int searchElement , int size){
    int n = size ;
    int data = searchElement ;
    int index=-1;
        for(int i=0; i<n ;i++){
            if(arr[i]==data) {
                index =i;
             }
        }
    if (arr[index] == data) {
        cout<<"Found Element ==> index "<<index<<endl;
        return index ;
    }
    else {
        cout<<"Element Not Found"<<endl;
        return -1;
    }
}


int searchSentinalLinear (int arr [],int data , int n){
    int last =arr[n-1];
    arr[n-1]=data;
    int i=0;

    while (arr[i]!=data){
    i++;
    }
    arr[n-1]=last;
    if((i<n-1)||(data==arr[n-1])){
    cout<<"Found Element ==> index "<<i<<endl;
        return i ;
    }
    else {
        cout<<"Element Not Found"<<endl;
        return -1;
    }
}


//unexpected_behaviour when not sorted
int BinarySearch(int a[], int x , int size)
{
    int start = 0;
    int end = size - 1;
    int midIndex;
    while (start <= end)
    {
        midIndex = (start + end) / 2;
        if (a[midIndex] == x)
            return true;
        if (x < a[midIndex])
            end = midIndex - 1;
        else
            start = midIndex + 1;
    }
    return false;
}

void translate_boolean (bool answer) {
    if (answer == 1){
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
}


// trying to make linear search generic
template < typename U >
int searchLinearGeneric (employee arr [],U searchElement , int size, U (employee::*parameter)) {
    int n = size ;
    U data = searchElement ;
    int index=-1;
        for(int i=0; i<n ;i++){
            if( arr[i].*parameter == data) {
                index =i;
                break;
             }
        }
    if ((arr[index].*parameter) == data) {
        cout<<"Found Element ==> index "<<index<<endl;
        return index ;
    }
    else {
        cout<<"Element Not Found"<<endl;
        return -1;
    }
}



int main () {

employee Employees[5] {
    {923,"ahmed",2000},
    {567,"abanoub",18000},
    {6854,"sara",18000},
    {999,"seif",1200},
    {84,"youssr",7600}
};


int myArray [] = {7,8,9,6,2,10,56,45,9,654} ;
int arraySize = (sizeof(myArray)/sizeof(int));
// quickSort (myArray,0,arraySize-1);
// MergeSort(myArray,0,arraySize-1);
// printIntArray(myArray,arraySize);
// searchLinear (myArray,45,arraySize);
// searchSentinalLinear (myArray,45,arraySize);
//translate_boolean(BinarySearch(myArray ,9, arraySize));

 searchLinearGeneric(Employees,1200,5,&employee::salary);
























    return 0;} // end of main