---
name: algorithm-note-style
description: Convert Chinese voice-style algorithm learning thoughts into the user's existing Markdown algorithm-note style inside E:\universtity_cs\algorithm. Use when the user wants to add, correct, reorganize, or merge personal algorithm理解、刷题总结、LeetCode notes, especially from口语化中文、语音输入、错别字、零散想法. Apply only within this repository or when the user explicitly refers to these algorithm notes.
---

# Algorithm Note Style

Use this skill only for algorithm notes in `E:\universtity_cs\algorithm`.

## Core Workflow

1. Read `CLAUDE.md` and the likely target Markdown note before editing.
2. Treat the user's input as voice-first Chinese: infer intent from context, repair speech-recognition errors, and preserve the user's original insight.
3. First judge the user's understanding:
   - If correct, say what is correct and why.
   - If partially correct, separate the correct part from the wrong or incomplete part.
   - If wrong, explicitly point out the error before writing notes.
4. Route the idea to the correct algorithm note file automatically when possible.
5. Make incremental Markdown edits only. Do not rewrite the whole file unless explicitly requested.
6. Keep the final note in Chinese and match the existing file structure.

## Automatic File Routing

Prefer existing topic summary files. When the user mentions a new learning topic, map it to the matching folder and Markdown file:

| User topic | Target file |
|---|---|
| 回溯、组合、排列、子集、切割、N 皇后、数独 | `leetcode/backtracing/backtracing.md` |
| 动态规划、DP、背包、子序列、编辑距离、区间 DP | `leetcode/dynamic_programming/dynamic_programming.md` |
| 贪心、局部最优、分发饼干、摆动序列、跳跃游戏 | `leetcode/greedy/greedy.md` |
| 二叉树、递归、前中后序、层序、LCA、路径 | `leetcode/tree/binary_tree.md` |
| DFS、BFS、图、岛屿、拓扑排序 | `leetcode/graph/dfs_and_bfs.md` |
| 链表、反转链表、环形链表、双指针链表 | create or use a topic Markdown under `leetcode/linklist/` |

If no suitable Markdown file exists, create one in the matching topic folder. The naming rule is:

```text
leetcode/<topic_folder>/<algorithm_point>.md
```

Use lowercase English with underscores for new file names, matching the repository's code naming style. Examples:

- `leetcode/greedy/greedy.md`
- `leetcode/linklist/linklist.md`
- `leetcode/graph/dfs_and_bfs.md`

Do not create a new Markdown file when a suitable topic summary file already exists. Insert into the existing topic note instead.

## Understanding Check

Before editing notes, decide whether the user's idea is technically correct.

Use this response pattern when needed:

```markdown
你这个理解里，正确的是：...

需要修正的是：...

正确说法应该是：...
```

Then convert the corrected idea into note style.

Do not silently write a wrong idea into the notes. If the user's idea is wrong but useful as a trap, add it under `易错点` as a contrast:

```markdown
**易错点**：不能认为 ...。真正原因是 ...
```

## Voice Input Cleanup

Correct likely speech and typo forms by algorithm context:

| Voice-like input | Intended meaning |
|---|---|
| 回字算法、回朔、回数 | 回溯算法 |
| 减脂、剪支 | 剪枝 |
| 动规、动态、dp | 动态规划 |
| 贪心策略、局部最优 | 贪心算法 |
| 二叉数、二叉、树递归 | 二叉树递归 |
| 层次遍历 | 层序遍历 |
| 前序后序说混 | 根据“先处理当前”或“需要子问题返回值”判断 |
| 递归公式、推导公式 | 根据上下文改为递推公式或递归逻辑 |

Rewrite口语化表达 into precise note prose:

- "我感觉这个东西就是..." → `**本质**：...`
- "这里为什么不能..." → `**为什么不能这样写？** ...`
- "这个点容易错" → `**易错点**：...`
- "这俩差不多但是..." → build a comparison table.

## Writing Style

Use the user's framework-first style:

- Start with a fixed process, core rule, or classification criterion.
- Emphasize `核心`、`本质`、`关键`、`为什么`、`一句话记忆`.
- Organize by algorithm pattern, not by isolated problem whenever possible.
- Prefer comparison tables for confusing concepts.
- Use C++ snippets only when they expose the key template or trap.
- Keep comments short and explanatory.
- Prefer `典型题目` lists over full problem statements.

Common section shapes:

````markdown
### 题型X：主题

**核心**：...

**什么时候用**：
- ...

**为什么**：...

```cpp
// 关键代码模板
```

**易错点**：
1. ...
````

For comparisons:

```markdown
| | A | B |
|---|---|---|
| **本质** | ... | ... |
| **代码特征** | ... | ... |
| **适用题目** | ... | ... |
```

For one-line memory:

```markdown
**一句话记忆**：...
```

## Insertion Rules

1. Read the target Markdown and locate the closest existing section.
2. If the idea extends an existing concept, insert into that section.
3. If it compares two concepts, add or extend a comparison table.
4. If it is a common mistake, add it under `易错点`.
5. If it is a new major pattern, add a new `### 题型X：...` section before the final `易错点` section.
6. Preserve existing Chinese numbering style such as `一、二、三` and local variants like `五点五`.
7. Do not renumber large sections unless necessary.

## Content Preferences

Prioritize:

- 判断标准: "什么时候用这个方法？"
- 本质原因: "为什么这个写法成立？"
- 易错区别: "这个和另一个看起来像的点差在哪里？"
- 代码特征: "看到什么代码结构就说明用了这个思路？"

Avoid:

- Long generic definitions.
- Full LeetCode editorials.
- Rewriting entire files for a small idea.
- Adding complete unrelated code files.
- Keeping unclear voice phrasing if it can be made precise.

## Greedy Note Guidance

When routing to `leetcode/greedy/greedy.md`, keep this emphasis:

- Greedy must explain the chosen local optimum.
- Always ask: "局部最优为什么能推出全局最优？"
- If the proof is weak, write it as a trial strategy plus validation, not as a guaranteed formula.
- Prefer comparing greedy with DP when the user is transitioning from DP or backtracking.

Recommended greedy structure:

```markdown
### 题型X：主题

**贪心策略**：...

**为什么这样贪心？**
- ...

**局部最优如何推出全局最优**：...

**代码特征**：...

**易错点**：...
```
