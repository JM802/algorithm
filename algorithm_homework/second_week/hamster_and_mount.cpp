#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solve_max_beauty(int n, int m, const vector<long long> &beauty, const vector<pair<int, int>> &edges)
{
    const long long INF = 1e18;

    // 1. 构建邻接表和入度数组
    // 使用索引 1..n，所以大小设为 n + 1
    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (const auto &edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        in_degree[edge.second]++;
    }

    // 2. DP 数组初始化
    // dp[i] 表示从山顶（1号点）到点 i 的最大路径和
    vector<long long> dp(n + 1, -INF);

    // 3. 拓扑排序准备
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    // 4. 状态转移
    dp[1] = beauty[1]; // 起点（山顶）的初始值
    long long max_total_beauty = beauty[1];

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            // 关键：只有当 1 号点能到达 u 时，才延伸路径到 v
            if (dp[u] != -INF)
            {
                dp[v] = max(dp[v], dp[u] + beauty[v]);
                // 题目说可以随时打电话呼叫下山，所以每个到达的点都可能是终点
                max_total_beauty = max(max_total_beauty, dp[v]);
            }

            if (--in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return max_total_beauty;
}

int main()
{
    // 优化 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    // 读入每个点的美观度 (1-based)
    vector<long long> beauty(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> beauty[i];
    }

    // 读入边
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    // 计算并输出结果
    cout << solve_max_beauty(n, m, beauty, edges) << endl;

    return 0;
}