/*
Given a string S consisting of uppercase and lowercase characters.
The task is to sort uppercase and lowercase letters separately such that
if the ith place in the original string had an Uppercase character then 
it should not have a lowercase character after being sorted and vice versa.
*/
#include <bits/stdc++.h> 
using namespace std;  
void swapchar(char* a, char* b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
} 

int partition (char *arr, int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        
        if (arr[j] < pivot)  
        {  
            i++; 
            swapchar(&arr[i], &arr[j]);
        }  
    }  
    swapchar(&arr[i + 1], &arr[high]);
    return (i + 1);  
}  

void quickSort(char arr[], int low, int high)  
{
    if (low < high)  
    {  
        
        int pi = partition(arr,low, high);  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);  
    } 
    
}

string caseSort(string str, int n){
    char lowerArray[n], upperArray[n];
    int lowerIndex[n], upperIndex[n];
    int iterLower=0, iterUpper=0;
    for(int i=0;i<n;i++)
    {   
        if(str[i]>=65 && str[i]<=90)
        {
            upperArray[iterUpper] = str[i];
            upperIndex[iterUpper++]= i;
            
        }
        
        else
        {
            lowerArray[iterLower] = str[i];
            lowerIndex[iterLower++]= i;
        }
    }

    quickSort(lowerArray,0,iterLower-1);
    quickSort(upperArray,0,iterUpper-1);
    
    for(int i=0; i<iterLower;i++)
        str[lowerIndex[i]]= lowerArray[i];
    for(int i=0; i<iterUpper;i++)
        str[upperIndex[i]]= upperArray[i];
    return str;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		cout<<caseSort (str, n)<<endl;
	}
    return 0;
} 