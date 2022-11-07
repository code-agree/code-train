# 1. 二叉树
1. 二叉树的遍历

   前中后序是对于root节点而言

- 中序遍历即：【左子树，root，右子树】
- 前序遍历：【root，左子树，右子树】
- 后序遍历：【左子树，右子树，root】

2. 二叉树的遍历结构
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
3. 二叉搜素树

    左小右大
