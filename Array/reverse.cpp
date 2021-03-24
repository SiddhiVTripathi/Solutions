#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n/2;i++)
    {
        swap(&arr[i], &arr[n-i-1]);
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

}