#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<algorithm>
using namespace std;

vector<int> res1;
vector<int>res2;
vector<bool> visited1;
vector<bool> visited2;
vector<vector<int>> edges;

void dfs(int x)
{
    visited1[x] = true;
    res1.push_back(x);
    for(int i:edges[x])
    {
        if(!visited1[i])
        {
            dfs(i);
        }      
    }
}

void bfs(int start)
{
    queue<int> q;
    visited2[start] = true;
    q.push(start);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res2.push_back(u);

        for (int i:edges[u])
        {
            if(!visited2[i])
            {
                visited2[i] = true;
                q.push(i);
            }
        }
    }
}    


int main()
{
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    visited1.resize(n+1, false);
    visited2.resize(n+1, false);
    for (int i = 0; i <m ; i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    for (int i = 1; i <= n;i++)
    {
        sort(edges[i].begin(), edges[i].end());
    }
    dfs(1);
    bfs(1);

    for (int i = 0; i < res1.size() - 1; i++)
    {
        cout << res1[i] << " ";
    }
    cout << res1.back() << endl;

    for (int i = 0; i < res2.size() - 1; i++)
    {
        cout << res2[i] << " ";
    }
    cout << res2.back() << endl;

    return 0;
}