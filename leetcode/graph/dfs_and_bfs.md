# DFS 与 BFS 总结

## DFS 两种套路

核心区别：**第一个点是在 DFS 函数里处理，还是在 main 里单独处理。**

### 套路一：第一个点在 DFS 函数内处理

main 里只调用一次 `dfs(start)`，DFS 函数内部负责处理当前点并递归访问所有未访问的邻居。

```cpp
// main：只调用一次，不处理起点
dfs(start);

// DFS：处理当前点 + 递归邻居
void dfs(int x) {
    visited[x] = true;          // 标记当前点
    res.push_back(x);           // 处理当前点
    for (int i : edges[x]) {
        if (!visited[i]) {
            dfs(i);             // 未访问才递归
        }
    }
}
```

结束机制：靠 `visited` 数组控制——所有可达点都被标记后，递归自然终止，不需要显式终止条件。

**典型题目：** 图的遍历（experiment2/1.cpp）、岛屿数量（carl_99）

---

### 套路二：第一个点在 main 里单独处理

main 里先处理起点（如 `path.push_back(start)`），然后调用 `dfs(start)`。DFS 函数内部只负责处理「下一个点」。

```cpp
// main：先处理起点
path.push_back(start);
dfs(start);

// DFS：判断终止 + 处理下一个点
void dfs(int x) {
    if (x == end) {             // 显式终止条件
        res.push_back(path);
        return;
    }
    for (int i : edges[x]) {
        path.push_back(i);      // 处理下一个点
        dfs(i);
        path.pop_back();        // 回溯
    }
}
```

**典型题目：** 找所有路径（carl_98）

---

### 两种套路对比

唯一的区别：**第一个点是在 DFS 函数内处理，还是在 main 里单独处理。**

| | 套路一 | 套路二 |
|---|---|---|
| **第一个点处理** | DFS 函数内 | **main 里单独处理** |
| DFS 处理的对象 | 当前点 | 下一个点 |

终止条件、回溯操作、适用场景都不是区分标准——两种套路都可以有终止条件，也都可以有回溯。

例如组合问题（leetcode77）有终止条件 `if(path.size()==k)` 也有回溯 `push_back`/`pop_back`，但第一个点是在 DFS 函数内处理的，属于套路一。

---

## BFS 套路

BFS 模板比较固定：**起点单独处理**，入队时立即标记，然后进入 `while` 循环逐层处理。

```
1. 起点标记 + 入队
2. while (!q.empty())
   ├─ 出队一个点 u
   ├─ 处理 u
   └─ 遍历 u 的所有邻居
       └─ 没被访问过 → 立即标记 + 入队
```

```cpp
void bfs(int start) {
    queue<int> q;
    visited[start] = true;      // ① 起点标记
    q.push(start);              // ② 起点入队

    while (!q.empty()) {        // ③ 循环处理
        int u = q.front();
        q.pop();                // ④ 出队
        // 处理 u ...

        for (int i : edges[u]) {
            if (!visited[i]) {
                visited[i] = true;   // ⑤ 进队前就标记！
                q.push(i);
            }
        }
    }
}
```

### 关键点：入队时标记，不是出队时标记

如果出队才标记，同一个节点会被多次重复入队。入队时立即标记，保证每个节点只入队一次。

**典型题目：** 图的遍历（experiment2/1.cpp）、层序遍历（leetcode102）、拓扑排序（hamster_and_mount）

---

## BFS vs DFS 选择

| 场景 | 推荐 | 原因 |
|------|------|------|
| 逐层处理（层序遍历） | BFS | 天然按层分组 |
| 找最短路径（无权图） | BFS | 第一次到达即最短 |
| 搜索所有路径 / 回溯 | DFS | 递归 + 回溯更自然 |
| 判断连通性 / 岛屿问题 | 两者皆可 | 看个人习惯 |

---

## 树的 DFS 常见变体

树的递归遍历本质上都是 DFS，前/中/后序只是「处理当前点」的时机不同。

### 前序：先处理当前点，再递归左右
```cpp
void traverse(TreeNode* root) {
    if (!root) return;
    res.push_back(root->val);   // 先处理
    traverse(root->left);
    traverse(root->right);
}
```
代表：N叉树前序遍历（leetcode589）

### 中序：先递归左，处理当前点，再递归右
```cpp
void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    res.push_back(root->val);   // 中间处理
    traverse(root->right);
}
```

### 后序：先递归左右，再处理当前点
```cpp
void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    traverse(root->right);
    res.push_back(root->val);   // 最后处理
}
```
代表：最大深度（leetcode104）、平衡判断（leetcode110）

### 迭代 DFS：用栈模拟递归
```cpp
stack<TreeNode*> s;
s.push(root);
while (!s.empty()) {
    TreeNode* cur = s.top(); s.pop();
    // 处理 cur...
    if (cur->right) s.push(cur->right);
    if (cur->left) s.push(cur->left);
}
```
代表：前/中/后序迭代遍历（iterative_traversal_of_a_binary_tree.cpp）

---

## 回溯 = DFS + 状态撤销

回溯本质是套路二的 DFS，核心模式：**做选择 → 递归 → 撤销选择**。

```cpp
void backtrack(路径, 选择列表) {
    if (满足条件) { 收集结果; return; }
    for (选择 : 选择列表) {
        做选择;          // path.push_back(...)
        backtrack(...);  // 递归
        撤销选择;        // path.pop_back()
    }
}
```

代表：找所有路径（carl_98）、路径总和II（leetcode113）、二叉树路径（leetcode257）

---

## 特殊 BFS 变体

### 层序遍历：用 `q.size()` 分层
```cpp
while (!q.empty()) {
    int size = q.size();    // 当前层的节点数
    for (int i = 0; i < size; i++) {
        TreeNode* cur = q.front(); q.pop();
        // 处理当前层...
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    // 一层处理完毕
}
```
代表：leetcode102、leetcode107、leetcode199、leetcode515、leetcode637 等所有层序遍历题目

### 拓扑排序：BFS + 入度表（Kahn算法）
```cpp
queue<int> q;
// 所有入度为0的点入队
for (int i = 1; i <= n; i++)
    if (in_degree[i] == 0) q.push(i);

while (!q.empty()) {
    int u = q.front(); q.pop();
    // 处理 u...
    for (int v : edges[u]) {
        in_degree[v]--;
        if (in_degree[v] == 0) q.push(v);
    }
}
```
代表：hamster_and_mount

---

## 仓库文件索引

### 图论

| 文件 | 算法 | 题目 |
|------|------|------|
| `experiment/experiment2/1.cpp` | DFS + BFS | 图的遍历（套路一） |
| `experiment/experiment2/2.cpp` | DFS + BFS | 图的遍历（打印序列） |
| `graph/carl_98_availble_path.cpp` | DFS | 找所有路径（套路二+回溯） |
| `graph/carl_99_solo_island_count.cpp` | DFS + BFS | 岛屿数量 |
| `experiment/experiment2/4.cpp` | DFS | 数字枚举 |

### 动态规划中的 DFS

| 文件 | 算法 | 题目 |
|------|------|------|
| `dynamic_programming/leetcode63_different_path_2.cpp` | DFS + DP | 不同路径II |

### 算法作业

| 文件 | 算法 | 题目 |
|------|------|------|
| `algorithm_homework/second_week/social_ability.cpp` | DFS | 树形DP社交能力 |
| `algorithm_homework/second_week/hamster_and_mount.cpp` | BFS（拓扑排序） | DAG最长路径 |

### 树 - 层序遍历（BFS）

| 文件 | 题目 |
|------|------|
| `tree/level_tranversal/leetcode102_leveltranversal.cpp` | 二叉树层序遍历 |
| `tree/level_tranversal/leetcode107_level_tranversal_2.cpp` | 层序遍历II（自底向上） |
| `tree/level_tranversal/leetcode429_n_level_tranversal.cpp` | N叉树层序遍历 |
| `tree/level_tranversal/leetcode116_padding_next_right_pointer.cpp` | 填充next指针 |
| `tree/level_tranversal/leetcode117_padding_next_right_pointer2.cpp` | 填充next指针II |
| `tree/level_tranversal/leetcode637_average_level_of_binary_tree.cpp` | 每层平均值 |
| `tree/level_tranversal/leetcode515_max_value_in_each_row.cpp` | 每行最大值 |
| `tree/level_tranversal/leetcode199_binary_tree_right_side_view.cpp` | 二叉树右视图 |
| `tree/level_tranversal/leetcode222_count_complete_binary_tree.cpp` | 完全二叉树节点数（BFS+DFS） |

### 树 - 前/中/后序遍历（DFS）

| 文件 | 题目 |
|------|------|
| `tree/pre_inorder_post_tranversal/leetcode144_pre_tranversal.cpp` | 前序遍历（递归+迭代） |
| `tree/pre_inorder_post_tranversal/iterative_traversal_of_a_binary_tree.cpp` | 三种遍历迭代版（栈） |
| `tree/leetcode145_post_tranversal.cpp` | 后序遍历 |
| `tree/pre_inorder_post_tranversal/leetcode104_max_depth_of_binary_tree.cpp` | 最大深度 |
| `tree/pre_inorder_post_tranversal/leetcode111_min_height_of_binary_tree.cpp` | 最小深度 |
| `tree/pre_inorder_post_tranversal/leetcode110_balance_binary_tree.cpp` | 平衡二叉树 |
| `tree/pre_inorder_post_tranversal/leetcode101_symmetric_binary_tree.cpp` | 对称二叉树 |
| `tree/pre_inorder_post_tranversal/leetcode236_lowest_common_ancestor.cpp` | 最近公共祖先 |
| `tree/pre_inorder_post_tranversal/leetcode257_binary_tree_path.cpp` | 所有路径（回溯） |
| `tree/pre_inorder_post_tranversal/leetcode559_max_n_ary_tree_depth.cpp` | N叉树最大深度 |
| `tree/pre_inorder_post_tranversal/leetcode589_n_ary_tree_pre_tranversal.cpp` | N叉树前序 |
| `tree/pre_inorder_post_tranversal/leetcode226_invert_binary_tree.cpp` | 翻转二叉树 |
| `tree/pre_inorder_post_tranversal/leetcode513_left_down_corner.cpp` | 左下角的值 |
| `tree/pre_inorder_post_tranversal/leetcode112_sum_of_path.cpp` | 路径总和 |
| `tree/pre_inorder_post_tranversal/leetcode113_sum_of_path2.cpp` | 路径总和II（回溯） |
| `tree/pre_inorder_post_tranversal/leecode404_sum_left_leaves.cpp` | 左叶子之和 |
