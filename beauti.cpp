class Solution
{

// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int colsum[n], rowsum[n], maxSum=0;
        memset(colsum,0,sizeof(colsum));
        memset(rowsum,0,sizeof(rowsum));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                colsum[j]+=matrix[i][j];
                maxSum=maxSum>colsum[j]?maxSum:colsum[j];
                rowsum[i]+=matrix[i][j];
                maxSum=maxSum>rowsum[i]?maxSum:rowsum[i];
            }
        
        int count =0;
        for(int i=0, j=0; i<n && j<n;)
        {
            int diff = min(maxSum - rowsum[i],
                           maxSum - colsum[j]);
            matrix[i][j] += diff;
            rowsum[i] += diff;
            colsum[j] += diff;
            
            count+=diff;
            
            if(rowsum[i] == maxSum)
                i++;
            if(colsum[j] == maxSum)
                j++;
        }
        
        return count;
    } 
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}

  // } Driver Code Ends