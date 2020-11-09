#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int calculateDist(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **dp = new int*[m+1];
    for(int i=0; i<m+1;i++)
        dp[i] = new int[n+1];
    
    for(int i=0;i<=m;i++) dp[i][0]=i;
    for(int j=0;j<=n;j++) dp[0][j]=j;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j] =1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
    return dp[m][n];
}

int main()
{
    string s1,s2;
    cout<<"Enter Strng 1:\t";
    getline(cin,s1);
    cout<<"Enter Strng 2:\t";
    getline(cin,s2);
    cout<<"Minimum edits required = "<<calculateDist(s1,s2)<<"\n";
}