# 1. 二叉树
## 1.1. 二叉树的遍历


前中后序是对于root节点而言.

- 中序遍历：[左子树，root，右子树]
- 前序遍历：[root，左子树，右子树]
- 后序遍历：[左子树，右子树，root]

## 1.2. 二叉树的遍历结构

```c++
void traverse(TreeNode root) {
    if (root == null) {
        return;
    }
    // 前序位置
    traverse(root.left);
    // 中序位置
    traverse(root.right);
    // 后序位置
}
```
## 1.3. 二叉搜素树[BST]
定义
> - 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值
> - 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值
> - 任意节点的左、右子树也分别为二元搜索树。 


# 2022/11/15
## 图论基础及遍历算法
> https://labuladong.github.io/algo/2/22/50/      

图由**节点**和**边**构成，图的逻辑结构：
![](./tulun.jpeg)
## 多叉树的遍历框架
```cpp
void traverse(TreeNode* root){
    if (root == null){
        return
    }
    // 前序位置
    for (TreeNode child : root.children){
        traverse(child);
    }
    // 后序位置
}
```
## 图的遍历框架
基本的图遍历算法有两种
> DFS[depth-first-search] / 深度优先搜索
> BFS [breadth-first-search] / 广度优先搜索
```cpp
// 记录被遍历过的节点
boolean[] visited;
// 记录从起点到当前节点的路径
boolean[] onPath;

/* 图遍历框架 */
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph.neighbors(s)) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}
```
## 二分图
lc 
> https://leetcode.cn/problems/is-graph-bipartite/solution/er-fen-tu-de-bian-li-by-code-agree-zknp/