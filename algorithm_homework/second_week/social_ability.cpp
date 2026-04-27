#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 左孩子右兄弟树节点结构
struct Node
{
    string name;
    int scores;
    Node *lchild, *rsibling;
    int dp0, dp1; // dp0不选，dp1选
    bool choose;  // 是否参加聚会

    Node(string n, int s) : name(n), scores(s), lchild(nullptr), rsibling(nullptr), choose(false) {}
};

int ptr = 0;
string s;
unordered_map<string, Node *> mp;

Node *parse()
{
    ptr++; // 跳过 '('
    string name;
    int val;

    // 读取姓名
    while (isalpha(s[ptr]))
        name += s[ptr++];
    // 读取分值
    val = 0;
    while (isdigit(s[ptr]))
        val = val * 10 + s[ptr++] - '0';

    Node *u = new Node(name, val);
    mp[name] = u;

    // 读孩子
    if (s[ptr] == '(')
    {
        u->lchild = parse();
        Node *v = u->lchild;
        while (s[ptr] == '(')
        {
            v->rsibling = parse();
            v = v->rsibling;
        }
    }

    ptr++; // 跳过 ')'
    return u;
}

void dfs(Node *u)
{
    if (!u)
        return;

    // 初始化
    u->dp1 = u->scores;
    u->dp0 = 0;

    // 遍历所有孩子（左孩子+右兄弟）
    Node *v = u->lchild;
    while (v)
    {
        dfs(v);
        u->dp1 += v->dp0;              // 选u → 孩子不能选
        u->dp0 += max(v->dp0, v->dp1); // 不选u → 孩子最优
        v = v->rsibling;
    }
}

vector<string> ans_list;
void getAns(Node *u, bool isFatherChoose)
{
    if (!u)
        return;

    if (!isFatherChoose && u->dp1 > u->dp0)
    {
        u->choose = true;
        ans_list.push_back(u->name);
    }
    else
    {
        u->choose = false;
    }

    // 遍历孩子
    Node *v = u->lchild;
    while (v)
    {
        getAns(v, u->choose);
        v = v->rsibling;
    }
}