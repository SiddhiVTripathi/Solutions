// Solving the N queen problem using backtracking.

#include <iostream>
#include <cmath>
using namespace std;

class sudoku
{
    public:
    int **grid;
    int N;
    
    sudoku(int n)
    {
        N=n;
        grid= new int*[n];
        for(int i=0;i<n;i++)
            grid[i]=new int[n];
    }
    bool isSafe(int i,int j, int n);
    bool solve();
    void fillSudoku();
    void printSudoku();
};

bool sudoku::solve()
{
    int i,j;
    bool flag = false;
    for(i=0;i<N && !flag;i++)
        for(j=0;j<N && !flag;j++)
            if(grid[i][j]==0)
                flag=true;

    if(i==N && j==N)
        return true;
    
    for(int n=1;n<=N;n++)
    {
        if(isSafe(i,j,n))
        {
            grid[i][j]=n;
            if(solve())
                return true;
            else
                grid[i][j]=0;
        }
    }

    return false;
}

bool sudoku::isSafe(int i, int j, int n)
{
    for(int k=0;k<N;k++)
        if(grid[k][j]==n || grid[i][k]==n)
                return false;

    int s= sqrt(N);
    int rs = i - i%s;
    int cs = j - j%s;
    for(int i =0;i<s;i++)
        for(int j=0;j<s;j++)
            if(grid[rs+i][cs+j]==n)
                return false;
    return true;
}

void sudoku::fillSudoku()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
}

void sudoku::printSudoku()
{
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
            cout<<endl;
        }

}

int main()
{
    cout<<"Enter sudoku size:"<<" ";
    int N;
    cin>>N;
    sudoku p1(N);
    p1.fillSudoku();
    cout<<endl;
    p1.printSudoku();
    if(p1.solve())
       p1.printSudoku();
    else
        cout<<"No solution"<<endl;
    return 1;
}