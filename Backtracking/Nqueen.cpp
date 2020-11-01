#include <iostream>
using namespace std;

class boardGame
{
    public:
    int N;
    bool **board;
    boardGame(int n)
    {
        N=n;
        board=new bool*[n];
        for(int i=0;i<n;i++)
            board[i]=new bool[n];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                board[i][j]=0;
        
    }
    bool isSafe(int row, int col);
    bool solveRec(int col);
    bool solve();
    void print();

};
bool boardGame::isSafe(int row, int col)
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
bool boardGame::solveRec(int col)
{
    if(col==N) return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            if(solveRec(col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;

}
bool boardGame::solve()
{
    if(solveRec(0)==false)
    {
        cout<<"No possible solution\n";
        return false;
    }

    else
    {
        print();
        return true;
    }
}
void boardGame::print()
{
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }

}

int main()
{
    int N;
    cout<<"Enter N \n";
    cin>>N;
    boardGame game1(N);
    game1.solve();
    return 0;
}