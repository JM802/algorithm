#include <iostream>
#include <vector>
#include <string>
#include<list>
using namespace std;

vector<vector<int>>res;
vector<int> path;

// void dfs(const vector<vector<int>>&edges,int x,int n)
// {
//     if(x==n)
//     {
//         res.push_back(path);
//         return;
//     }

//     for (int i = 1; i <= n;i++)
//     {
//         if(edges[x][i]==1)
//         {
//             path.push_back(i);
//             dfs(edges, i, n);
//             path.pop_back();
//         }
//     }
// }


void dfs(const vector<list<int>>&edges,int x,int n)
{
    if(x==n)
    {
        res.push_back(path);
        return;
    }

    for(int i:edges[x])
    {
        path.push_back(i);
        dfs(edges, i, n);
        path.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<int>>edges(n+1);
    for (int i = 1; i <= m;i++)
    {
        int s, t;
        cin >> s >> t;
        edges[s].push_back(t);
    }
    path.push_back(1);
    dfs(edges, 1, n);
    
    if(res.size()==0)
    {
        cout << -1 << endl;
    }

    for (const vector<int>&pa:res)
    {
        for (int i = 0; i < pa.size()-1;i++)
        {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1];
        cout << endl;
    }
    return 0;
}
