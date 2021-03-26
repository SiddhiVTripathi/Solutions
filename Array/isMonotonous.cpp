/*
Check if a given array is monotonous 
*/
#include <iostream>
using namespace std;
void isMonotonous(int arr[], int n)
{
    int val =0;
    bool flag = true;
    for (int i = 0; i < n-1; i++)
    {
        if(val==0)
            val = arr[i]>arr[i+1]?-1:arr[i]<arr[i+1]?1:0;
        else if(val==-1 && arr[i]<arr[i+1])
        {
                    flag = false;
                    break;

        }
        else if(val==1 && arr[i]>arr[i+1])
        {
            flag = false;
            break;
        }
            
    }
    cout<<val<<endl;
    if(!flag)
        cout<<"Not monotonic array\n";
    else    
        cout<<"Monotonic\n";
        
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    isMonotonous(arr,n);
}