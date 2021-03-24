/*
Given an array of integers and an integer k, move all occurences of k to the end of the array. Try to see if the order of the moved elements can be maintained
*/
#include <iostream>
using namespace std;

void collect(int arr[],int n, int k)
{
    int count = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]!=k)
            arr[count++] = arr[i];
    }

    while(count<n)
    {
        arr[count++]=k;
    }
}
int main()
{
    int n,k;
    cout<<"Enter n"<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter k"<<endl;
    cin>>k;

    collect(arr,n,k);
    for(int i=0;i<n;i++)
        cout<<arr[i];
}