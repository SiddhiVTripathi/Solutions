#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(vector<vector<int>> grid, int row, int col)
    {
        int sumRow=0, sumDia1=0,sumDia2=0;
        int sumCol[]={0,0,0};
        for(int i=row;i<row+3;i++)
        {   
            
            sumRow=0;
            for(int j=col;j<col+3;j++)
            {   
                if(grid[i][j]>9) return 0;
                sumRow+=grid[i][j];
                sumCol[j-col]+=grid[i][j];
                if(i-row==j-col)
                    sumDia1+=grid[i][j];
                if((i+j)==2+row+col)
                    sumDia2+=grid[i][j];
            }
            cout<<sumRow<<"\n";
            if(sumRow!=15)
                return 0;
        }

        cout<<sumDia1<<" "<<sumDia2<<"\n";
        if(sumDia1!=15||sumDia2!=15)
            return 0;
        for(int i=0;i<3;i++)
            {
                cout<<sumCol[i]<<" ";
                if(sumCol[i]!=15)
                return 0;
            }
        cout<<endl;
        return 1; 
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int sum=0;
        cout<<grid.size()<<endl;
        for(int i=0;i<grid.size()-2;i++)
            for(int j=0;j<grid[i].size()-2;j++)
                sum+=calculate(grid,i,j);
        
        return sum;
    }
};

int main()
{
    vector<vector <int>> grid={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    Solution ob;
    cout<<ob.numMagicSquaresInside(grid);
}

class Solutions {
public:
    int calculate(vector<vector<int>> grid, int row, int col)
    {
        
        return (grid[row][col]+grid[row][col+1]+grid[row][col+2]==15 &&
               grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2]==15 &&
               grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2]==15 &&
               grid[row][col]+grid[row+1][col]+grid[row+2][col]==15 &&
               grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1]==15 &&
               grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2]==15 &&
               grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]==15 &&
               grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col]==15); 
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int sum=0;
        for(int i=0;i<grid.size()-2;i++)
            for(int j=0;j<grid[i].size()-2;j++)
                sum+=calculate(grid,i,j);
        
        return sum;
    }
};