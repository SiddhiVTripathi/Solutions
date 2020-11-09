#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void topo(vector<vector<int>> adj,stack<int>st, bool visited[], int s)
{
    visited[s]=true;
    for(auto u:adj[s])
        if(visited[u]== false)
            topo(adj,st,visited,u);
    st.push(s);
}

void dfsBasedTopo(vector<vector <int>>adj,int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    stack<int> st;
    for(int i=0;i<V;i++)
        if(visited[i]==false)
            topo(adj,st,visited,i);
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
