// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<string> &,int,int);

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m;
		cin>>m;
		vector<string> arr;
		for(int i=0;i<n;i++){
			string S;
			cin>>S;
			arr.push_back(S);
		}
		cout<< Shape(arr,n,m)<<endl;
	}
}// } Driver Code Ends


//User function template for C++

// A : vector of given strings
void dfs(vector<string> &arr,int *count, int i, int j, bool visited[], int n, int m, bool flag)
{
    if(i<n && j<m && i>=0 && j>=0 && visited[i*m+j]== false)
    {
        visited[i*m+j] = true;
        if(arr[i][j]=='X')
        {
            if(flag == false)
            {
                flag = true;
                *count= (*count)+1;
            }
            
            dfs(arr,count,i-1,j,visited,n,m,flag);
            dfs(arr,count,i+1,j,visited,n,m,flag);
            dfs(arr,count,i,j+1,visited,n,m,flag);
            dfs(arr,count,i,j-1,visited,n,m,flag);
        }
    }
}
int Shape(vector<string> &arr,int n,int m) {
    int count =0;
    bool visited[n*m];
    memset(visited, false, sizeof(visited));
    int k=0;
    for(int i =0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            bool flag = false;
            dfs(arr, &count, i, j, visited, n, m, flag);
        }
    
    return count;
}