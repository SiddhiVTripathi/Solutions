#include <iostream>
using namespace std;

bool isSafe(bool **board,int N, int row, int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return  false;
    for(int i=row,j=col;j>=0&&i<N;j--,i++)
        if(board[i][j])
            return false;
    return true;
}
bool solveRec(bool ** board, int N, int col)
{
    if(col==N) return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,N,i,col))
        {
            board[i][col]=1;
            if(solveRec(board,N,col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;

}
void print(bool **board, int N)
{
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }

}
bool solve(bool **board, int N)
{
    if(solveRec(board,N,0)==false)
    {
        return false;
    }

    else
    {
        print(board,N);
        return true;
    }
}


int main()
{
    int N=5;
    bool **board=new bool*[N];
    for(int i=0;i<N;i++)
    board[i]=new bool[N];
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        board[i][j]=0;
    solve(board,N);
    return 0;
}