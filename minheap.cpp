#include <iostream>
#include <limits>
using namespace std;

template <typename T>
class MinHeap
{
    T *arr;
    T size, capacity;
    public:
    MinHeap(T c);
    int left(int i) {return (2*i+1);}
    int right(int i) {return (2*i+2);}
    int parent(int i) {return (i-1)/2;}

    void insert(T x);
    void minHeapify(T i);
    T extractMin();
    void decreaseKey(T i, T s);
    void deleteKey(T i);
    void BuildHeap();
};
template <typename T>
MinHeap<T>::MinHeap(T c)
    {
        arr = new T[c];
        size=0;
        capacity = c;
    }
template <typename T>
void MinHeap<T>::insert(T x)
{
    if(size==capacity) return;
    size++; arr[size-1]=x;
    for(T i=size-1; i!=0 && arr[parent(i)]>arr[i];)
    {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
template <typename T>
void MinHeap<T>::minHeapify(T i)
{
    T lt = left(i), rt = right(i);
    T smallest=i;
    if(lt<size && arr[lt]<arr[i]) smallest=lt;
    if(rt<size && arr[rt]<arr[i]) smallest=rt;

    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        MinHeap<T>ify(smallest);
    }
}
template <typename T>
T MinHeap<T>::extractMin()
{
    if(size==0)
        return INT_MIN;
    if(size ==1)
    {
        size--;
        return arr[0];
    }
}
template <typename T>
void MinHeap<T>::decreaseKey(T i, T k)
{
    arr[i]=k;
    while(i!=0 && arr[parent(i)]>arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i = parent(i);
    }
}
template <typename T>
void MinHeap<T>::deleteKey(T i)
{
    if(i>size)
    {
        cout<<"Index out of bounds"<<endl;
        return;
    }

    decreaseKey(i, INT_MIN);
    extractMin();
}
template <typename T>
void MinHeap<T>::BuildHeap()
{
    for(T i=(size-2)/2;i>=0;i--)
        minHeapify(i);
}
