#include <iostream>
using namespace std;

string remvov(string s, int n)
{
    if(n==0)
        return "";
    else if(s[n-1]=='a'||s[n-1]=='e'||s[n-1]=='i'||s[n-1]=='o'||s[n-1]=='u')
        return remvov(s,n-1);
    else
        return remvov(s,n-1)+s[n-1];
    
}

int main()
{
    string s = "asdfersf";
    cout<<remvov(s, s.length());
}