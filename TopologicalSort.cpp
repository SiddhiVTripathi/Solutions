#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void IndegreeS(vector <vector <int>> adj, int indegrees[],int s)
{
    for(auto V:adj)
        for(auto v:V)
            indegrees[v]++;
}

void topoSort(vector <vector <int>> adj, int indegrees[],int V)
{
    queue <int>q;

    for(int i=0;i<V;i++)
        if(indegrees[i]==0)
            q.push(i);
        
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(auto v:adj[u])
        {
            indegrees[v]--;
            if(indegrees[v]==0)
                q.push(v);
        }
    }
}