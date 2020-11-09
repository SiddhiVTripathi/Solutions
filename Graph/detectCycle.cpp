// Detect CCycle in  a directed graph represented in an adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

bool DFSrec(vector<vector <int>> adj, bool visited[], bool resSt[], int s)
{
    visited[s]=true;
    resSt[s]=true;
    for(auto u:adj[s])
    {
        if(visited[u]==false && DFSrec(adj,visited,resSt,u))
            return true;
        else if(resSt[u])
            return true;
    }
    resSt[s]=false;
    return false;
}

bool DFS(vector <vector <int>>adj, int v)
{
    bool visited[v],recSt[v];
    for(int i=0;i,v;i++)
    {
        visited[i]=recSt[i]=false;
    }

    for(int i =0;i<v;i++)
    {
        if(visited[i]==false)
            if(DFSrec(adj,visited,recSt,i))
                return true;
    }
    return false;
}