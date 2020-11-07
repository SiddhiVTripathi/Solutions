#include <iostream>
#include <string>
using namespace std;

class lcs
{
    public:
    int m,n;
    string s1,s2;
    int **C_table;
    lcs()
    {
        cout<<"enter string 1 and string 2 in separate lines\n";
        getline(cin,s1);
        getline(cin,s2);
        m= s1.length();
        n = s2.length();
        C_table= new int*[m+1];
        for(int i=0;i<m+1;i++)
                C_table[i] = new int[n+1];



        
    }

    int Count()
    {
        for(int i=0;i<=m;i++)
                C_table[i][0]=0;



        for(int i=0;i<=n;i++)
                C_table[0][i]=0;

        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(s1[i]==s2[j])
                        C_table[i][j]=C_table[i-1][j-1]+1;
                else
                        C_table[i][j]=max<int>(C_table[i][j-1], C_table[i-1][j]);
        return C_table[m][n];
    }
};
int main()
{
    lcs obj = lcs();
    cout<<"The maximum LCS is "<<obj.Count()<<endl;
}