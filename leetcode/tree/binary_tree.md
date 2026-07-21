# 二叉树与递归

## 一、递归三步骤

所有二叉树递归题目遵循 **固定三步求解流程**： **确定返回值和参数 → 确定终止条件 → 确定单层递归逻辑** ，所有二叉树题型均基于该流程演变。

### 1. 确定返回值和参数

- 返回值：需要返回什么？TreeNode*（返回根节点）？int（返回高度/数量）？void（只收集结果）？
- 参数：需要传什么？当前节点指针？需要额外状态吗？

### 2. 确定终止条件

一般遍历到空节点时 return。不同题型终止条件不同：

- 遍历类：`if (!cur) return`
- 求值类：`if (!root) return 0` 或 `return nullptr`

### 3. 确定单层递归逻辑

当前节点做什么？先递归哪边？这是前中后序遍历的核心区别所在。

---

## 二、前中后序遍历

三种遍历的区别只在**单层逻辑的位置不同**：

| 遍历方式       | 单层逻辑位置 | 顺序             |
| -------------- | ------------ | ---------------- |
| **前序** | 递归前       | 当前 → 左 → 右 |
| **中序** | 两次递归之间 | 左 → 当前 → 右 |
| **后序** | 递归后       | 左 → 右 → 当前 |

**引用传递 vs 值传递**：

- **引用传递**：修改共享变量，高效，相当于全局变量
- **值传递**：每层独立变量，需要合并左右子树的返回值，多一次拷贝

---

## 三、层序遍历（BFS）

**核心**：用队列，按层遍历，用 size 控制每层边界。

**模板**：

1. 根节点入队
2. while 队列非空：记录 size，for 循环处理当前层每个节点，出队并加入 result，将子节点入队

**关键细节**：`int size = que.size()` 必须在 for 循环前记录，不能写 `i < que.size()`，因为队列在循环中会变化。

**N 叉树层序遍历**：把 `if (left/right)` 换成 `for (child : node->children)`。

**经典题：102 二叉树层序遍历（BFS标准模版）**

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();            // 必须提前记录 size
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(v);
        }
        return res;
    }
};
```

**经典题：107 二叉树层序遍历2（自底向上）**

跟 102 一样，最后 `reverse(res)` 即可。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());    // 最后翻转
        return res;
    }
};
```

**经典题：199 二叉树右视图（每层最后一个）**

BFS，每层只取最后一个节点的值。

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (i == size - 1) res.push_back(cur->val);  // 每层最后一个
            }
        }
        return res;
    }
};
```

---

## 四、树的递归问题分类

### 题型一：需要子问题返回值 → 后序遍历

当需要**子问题的返回值**来判断当前节点时，必须用后序遍历。因为后序保证先处理子问题，再用结果做决策。

**典型题目**：

- 104（最大深度）、111（最小深度）、110（是否平衡）
- 101（对称二叉树）：需要同时遍历左右子树，比较它们是否镜像对称
- 226（反转二叉树）：交换左右子树

**高度 vs 深度的定义（极其重要）**

```
        3        ← 深度1，高度3
       / \
      9   20     ← 深度2
     / \
    1   6        ← 深度3（叶子），高度1
```

- **深度（Depth）**：从**根节点**到当前节点，经过多少个节点
- **高度（Height）**：从当前节点到**叶子节点**，经过多少个节点
- 叶子节点：深度 = 最大深度，高度 = 1
- 根节点：深度 = 1，高度 = 树的最大深度

**为什么后序求高度、前序求深度？** 后序从叶子往上算，天然就是高度的方向；前序从根往下走，天然就是深度的方向。

**104 最大深度（后序遍历求高度）**

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
```

**高度 vs 深度的区分**

|                        | 后序遍历（求高度）       | 前序遍历（求深度）                          |
| ---------------------- | ------------------------ | ------------------------------------------- |
| **方向**         | 自底向上，从叶子到根     | 自顶向下，从根到叶子                        |
| **终止条件**     | 空节点 return 0          | 叶子节点更新 result                         |
| **递推**         | `max(left, right) + 1` | `depth + 1`，用全局 result 记录           |
| **终止条件写法** | 到空节点才 return        | 可以到叶子节点就 return（优化，少遍历一层） |

**终止条件的两种写法都对**：到空节点 return 和到叶子节点 return，结果一样，区别只是到叶子就 return 少递归一层，是小优化。

**111 最小深度（后序写法的坑）**

后序写法不能直接用 `min(left, right)`，因为当一个子树为空时 min 会取 0，结果错误。必须判断左右子树是否为空：

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;       // 叶子节点
        if (!root->left) return minDepth(root->right) + 1;   // 左空，只算右边
        if (!root->right) return minDepth(root->left) + 1;   // 右空，只算左边
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```

**104 vs 111 收集结果的位置**：

|                    | 104 最大深度                               | 111 最小深度                                   |
| ------------------ | ------------------------------------------ | ---------------------------------------------- |
| **后序写法** | `max(left, right) + 1`，不需特殊判断     | 必须判断左右是否为空，不能直接 min             |
| **前序写法** | 叶子节点收集（也可在外面收集）             | **必须**在叶子节点收集                   |
| **原因**     | 最大值一定出现在叶子，但内部节点不影响结果 | 最小深度一定是某个叶子的深度，内部节点不能收集 |

**222 完全二叉树节点个数：空节点返回 0**

后序遍历，空节点返回 0，非空节点返回 `left + right + 1`。

**为什么在空节点收集而不是叶子节点？** 因为可能只有左子树没有右子树（单只情况）。如果在叶子收集，右子树为空就没法返回值，无法正确计数。空节点返回 0、叶子返回 1，单只的情况自然就是 `1 + 0 + 1 = 2`。

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;                    // 空节点返回 0
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;                // 左 + 右 + 当前
    }
};
```

**104、111、222 终止条件对比**：

| 题目         | 终止条件                   | 原因                     |
| ------------ | -------------------------- | ------------------------ |
| 104 最大深度 | 空节点 return 0            | 求高度，空就是 0         |
| 111 最小深度 | **叶子节点**收集结果 | 最小深度一定是完整路径   |
| 222 节点个数 | 空节点 return 0            | 需要数所有节点，包括单只 |

**110 平衡二叉树：用 -1 做标记，短路优化**

后序遍历求高度，如果发现不平衡就返回 -1，利用 -1 往上传递，避免重复计算。

**核心逻辑**：

1. 空节点返回 0
2. 左子树返回 -1 → 直接 return -1（短路，不算右子树）
3. 右子树返回 -1 → 直接 return -1
4. 左右高度差 > 1 → return -1
5. 否则返回 `max(left, right) + 1`

```cpp
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int left = getDepth(root->left);
        if (left == -1) return -1;       // 左子树不平衡，短路
        int right = getDepth(root->right);
        if (right == -1) return -1;      // 右子树不平衡，短路
        if (abs(left - right) > 1) return -1;  // 高度差 > 1
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};
```

**短路优化**：左子树返回 -1 时直接 return，不算右子树，性能更好。

**257 二叉树所有路径：叶子节点收集，不是空节点**

路径类问题必须在**叶子节点**收集结果。如果在空节点收集，单只节点会重复输出路径（左空收集一次，右空又收集一次）。

```cpp
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        if (!cur->left && !cur->right) {        // 叶子节点才收集
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
                sPath += to_string(path[i]) + "->";
            sPath += to_string(path.back());
            result.push_back(sPath);
            return;
        }
        if (cur->left) { traversal(cur->left, path, result); path.pop_back(); }
        if (cur->right) { traversal(cur->right, path, result); path.pop_back(); }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        traversal(root, path, res);
        return res;
    }
};
```

### 收集结果位置的核心规则（极其重要）

**后序遍历 → 空节点收集（return 0）**：因为需要子节点的返回值来计算，null 返回 0 是计算起点。

**前序遍历 → 叶子节点收集**：因为状态从父节点传下来，叶子是路径终点。

```
后序（从下往上）：null 返回 0 → 叶子返回 1 → 父节点算 max+1
前序（从上往下）：根传 depth=1 → 往下传 depth+1 → 叶子收集结果
```

| 遍历方向       | 收集位置 | 原因                  | 例子                         |
| -------------- | -------- | --------------------- | ---------------------------- |
| **后序** | 空节点   | null 返回值是计算起点 | 104 高度、222 计数、110 平衡 |
| **前序** | 叶子节点 | 叶子是路径终点        | 257 路径、111 最小深度       |

**为什么后序必须到空节点？** 因为父节点需要子树的返回值。如果停在叶子，父节点就拿不到子树的高度了。

**为什么前序可以在叶子停？** 因为深度是参数传下去的，不需要子节点返回值。

**后序遍历的工具函数写法**（如 101）：

```cpp
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left && !right) return false;
        if (!left && right) return false;
        if (!left && !right) return true;
        if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);  // 外侧
        bool inside = compare(left->right, right->left);    // 内侧
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return false;
        return compare(root->left, root->right);
    }
};
```

### 题型二：不需要返回值 → 前序/后序都可以

当不需要子问题返回值，只处理节点时，前序后序都可以。

**典型题目**：

- 226（反转二叉树）：交换操作对称，前序后序结果一样
- 100（是否相同树）

**经典题：226 反转二叉树（后序写法）**

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* leftroot = invertTree(root->left);
        TreeNode* rightroot = invertTree(root->right);
        root->left = rightroot;
        root->right = leftroot;
        return root;
    }
};
```

**经典题：100 相同的树**

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

### 题型三：构造二叉树（从前序+中序 / 后序+中序）

**核心思路**：用后序遍历的最后一个元素作为根，在中序中找到根的位置，划分左右子树，递归构造。

**关键**：用 hashmap 存中序元素的下标，避免每次 O(n) 查找。

**典型题目**：105（前序+中序）、106（后序+中序）、889（前序+后序）

**经典题：654 最大二叉树（递归构造）**

给定不含重复元素的数组，构建最大二叉树：根是最大值，左子树由最大值左边的数组构建，右子树由右边构建。

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        // 找最大值位置
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[maxIndex]) maxIndex = i;

        TreeNode* root = new TreeNode(nums[maxIndex]);
        // 递归构建左右子树
        vector<int> left(nums.begin(), nums.begin() + maxIndex);
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};
```

### 题型四：最近公共祖先（236）

**后序遍历**，从下往上找 p 和 q。

**核心逻辑**：

1. 空节点返回 nullptr
2. 找到 p 或 q 就返回自身
3. 左右子树都返回非空 → 当前节点就是 LCA，返回 root
4. 只有一边返回非空 → 返回那一边

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;    // 两边都找到，当前是 LCA
        if (left) return left;
        if (right) return right;
        return nullptr;
    }
};
```

**易错点**：`left && right` 时必须返回 `root`，不能返回 `nullptr`。

### 题型五：路径求和（112、113）

**前序遍历**，值传递 sum，叶子节点判断是否等于 targetSum。

**经典题：112 路径总和（是否存在）**

```cpp
class Solution {
public:
    bool traversal(TreeNode* root, int sum) {
        if (!root->left && !root->right) return sum == 0;  // 叶子判断
        if (root->left) {
            if (traversal(root->left, sum - root->left->val)) return true;
        }
        if (root->right) {
            if (traversal(root->right, sum - root->right->val)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return traversal(root, targetSum - root->val);  // 根节点单独处理
    }
};
```

**经典题：113 路径总和2（找出所有路径）**

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void traversal(TreeNode* root, int targetSum, int sum, vector<int>& path) {
        if (!root->left && !root->right) {
            if (targetSum == sum) res.push_back(path);  // 叶子收集
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            traversal(root->left, targetSum, sum + root->left->val, path);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            traversal(root->right, targetSum, sum + root->right->val, path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<int> path = {root->val};
        traversal(root, targetSum, root->val, path);
        return res;
    }
};
```

**112 vs 113 对比**：112 只需要判断是否存在（bool），113 需要收集所有路径（vector）。核心逻辑一样，区别在于 113 需要维护 path 数组。

---

## 四点五、收集结果位置代码对比

### 后序遍历（空节点收集）

**104 最大高度**：null 返回 0，计算 max(left, right) + 1

```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;                    // 空节点返回 0
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}
```

**222 节点个数**：null 返回 0，计算 left + right + 1

```cpp
int countNodes(TreeNode* root) {
    if (!root) return 0;                    // 空节点返回 0
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
}
```

**110 平衡二叉树**：null 返回 0，用 -1 标记不平衡

```cpp
int getDepth(TreeNode* root) {
    if (!root) return 0;                    // 空节点返回 0
    int left = getDepth(root->left);
    if (left == -1) return -1;
    int right = getDepth(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}
```

### 前序遍历（叶子节点收集）

**257 所有路径**：叶子节点收集路径，不是空节点

```cpp
void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
    path.push_back(cur->val);               // 中：加入当前节点

    if (!cur->left && !cur->right) {        // 叶子节点才收集
        string sPath;
        for (int i = 0; i < path.size() - 1; i++)
            sPath += to_string(path[i]) + "->";
        sPath += to_string(path.back());
        result.push_back(sPath);
        return;
    }

    if (cur->left) {                        // 左
        traversal(cur->left, path, result);
        path.pop_back();
    }
    if (cur->right) {                       // 右
        traversal(cur->right, path, result);
        path.pop_back();
    }
}
```

**513 找树左下角的值**：前序遍历，叶子收集，和 104 前序写法一样

先遍历左，所以最深的第一个一定是最左边的。要最右边的值，先遍历右即可。

```cpp
class Solution {
public:
    int result = 0;
    int depth = 0;
    void traversal(TreeNode* root, int& d) {
        if (!root) return;
        if (!root->left && !root->right) {      // 叶子节点
            if (d > depth) {
                depth = d;
                result = root->val;
            }
            return;
        }
        if (root->left) { d++; traversal(root->left, d); d--; }
        if (root->right) { d++; traversal(root->right, d); d--; }
    }
    int findBottomLeftValue(TreeNode* root) {
        int d = 1;
        traversal(root, d);
        return result;
    }
};
```

**111 最小深度**：叶子节点收集深度

```cpp
class Solution {
public:
    int result = INT_MAX;
    void getDepth(TreeNode* root, int depth) {
        if (!root->left && !root->right) {      // 叶子节点，更新 result
            result = min(result, depth);
            return;
        }
        if (root->left) getDepth(root->left, depth + 1);
        if (root->right) getDepth(root->right, depth + 1);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        getDepth(root, 1);
        return result;
    }
};
```

**404 左叶子之和**：前序遍历，判断左孩子是叶子就加到 result

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;  // 叶子不是左叶子

        int mid = 0;
        if (root->left && !root->left->left && !root->left->right)
            mid = root->left->val;                   // 左孩子是叶子，加到 result

        int leftsum = mid + sumOfLeftLeaves(root->left);
        int rightsum = sumOfLeftLeaves(root->right);
        return leftsum + rightsum;
    }
};
```

**关键**：

1. 判断的是 `root->left` 是不是叶子（`!root->left->left && !root->left->right`），不是判断 root 是不是叶子
2. 加完 result 后**不能 return**，因为右子树里可能还有左叶子，必须继续遍历

### 对比总结

| 题目           | 遍历方式 | 收集位置 | 代码特征                             |
| -------------- | -------- | -------- | ------------------------------------ |
| 104 最大高度   | 后序     | 空节点   | `if (!root) return 0`              |
| 222 节点个数   | 后序     | 空节点   | `if (!root) return 0`              |
| 110 平衡二叉树 | 后序     | 空节点   | `if (!root) return 0`              |
| 257 所有路径   | 前序     | 叶子     | `if (!cur->left && !cur->right)`   |
| 111 最小深度   | 前序     | 叶子     | `if (!root->left && !root->right)` |

### 处理当前节点 vs 处理下一个节点（极其重要）

两种写法本质等价，但代码组织不同：

**写法一：处理当前节点（统一处理所有节点）**

上来就处理当前节点，所有节点统一逻辑，不需要单独处理第一个节点。

```cpp
bool traversal(TreeNode* cur, int sum) {
    sum -= cur->val;              // 上来就处理当前节点
    if (!cur->left && !cur->right && sum == 0) return true;
    if (cur->left) traversal(cur->left, sum);    // 值传递，不回溯
    if (cur->right) traversal(cur->right, sum);
    return false;
}
```

**写法二：处理下一个节点（第一个节点单独处理）**

当前节点已经在外面处理过了，函数内只处理后续节点。

```cpp
bool traversal(TreeNode* cur, int count) {
    // count 已经在外面减过了（第一个节点）
    if (!cur->left && !cur->right && count == 0) return true;
    if (cur->left) traversal(cur->left, count - cur->left->val);  // 传表达式
    if (cur->right) traversal(cur->right, count - cur->right->val);
    return false;
}
// 调用：traversal(root, sum - root->val);  // 第一个节点单独处理
```

**对比**：

|                      | 写法一：处理当前       | 写法二：处理下一个     |
| -------------------- | ---------------------- | ---------------------- |
| **第一个节点** | 函数内统一处理         | 函数外单独处理         |
| **代码统一性** | 更统一，不需要特殊处理 | 需要额外处理第一个节点 |
| **回溯**       | 值传递不需要回溯       | 传表达式不需要回溯     |

### 前序必须判断，后序不用判断

前序遍历在叶子收集结果，所以**必须先判断有没有左/右子树再递归**，否则子节点不存在就没法返回值。

后序遍历在空节点收集结果，**可以直接递归不用判断**，因为空节点会返回 0 参与计算。

```cpp
// 前序：必须判断，子节点不存在就没法返回值
if (cur->left) traversal(cur->left, path, result);
if (cur->right) traversal(cur->right, path, result);

// 后序：不用判断，空节点返回 0
int left = maxDepth(root->left);    // 直接调用，nullptr 会 return 0
int right = maxDepth(root->right);
```

---

## 五、什么时候用后序遍历？

**核心判断：是否需要子问题的返回值？**

| 场景                                 | 遍历方式           | 例子                         |
| ------------------------------------ | ------------------ | ---------------------------- |
| 不需要返回值，只处理节点             | 前序/后序都可以    | 226 反转二叉树               |
| **需要子问题返回值来判断当前** | **必须后序** | 101 对称、104 深度、110 平衡 |

**一句话记忆**：后序 = 先干完子问题，再用子问题的答案做决策。

**前序 vs 后序的本质区别**：

- 前序：先处理当前，再递归子问题（适合需要**先操作再递归**的场景）
- 后序：先递归子问题，再处理当前（适合需要**子问题结果**的场景）

---

## 五点五、前序 vs 后序：两个核心总结

### 总结一：前序遍历

**为什么不需要处理空节点？** 因为 `if (cur->left)` 判断后再递归，空节点根本不会进入函数，函数自动 return。

**一般在叶子节点收集结果**，收集完就 return。

**404 是例外**：在叶子的**上一个节点**收集（因为要判断左孩子是不是叶子，不到叶子就没法判断）。收集完不能 return，因为右子树可能还有左叶子。

### 总结二：后序遍历

**必须处理空节点**：空节点返回值（0 或 nullptr）是父节点的计算起点。

**自底向上必须后序**：需要子树结果来判断当前（如 236 最近公共祖先）。

**236 要加 count**：题目保证 p 和 q 一定在树中，否则只找到一个也会返回错误结果。加 count 计数，只有 count == 2 时才信任返回值。

---

## 六、易错点

1. **层序遍历 size 必须提前记录**：`int size = que.size()` 写在 for 循环外面
2. **后序遍历别忘返回值**：用工具函数时，记得 `return outside && inside`
3. **构造树时用 hashmap**：中序中找根的位置，用 map 存下标避免 O(n) 查找
4. **101 对称二叉树参数**：传的是 `left->left, right->right`（外侧）和 `left->right, right->left`（内侧），不是 `left, right`
5. **104 终止条件**：前序求深度时，到叶子节点 return 和到空节点 return 结果一样，叶子写法更优（少递归一层）
6. **收集结果位置**：后序遍历 → 空节点收集（null 返回值是计算起点）；前序遍历 → 叶子节点收集（叶子是路径终点）
