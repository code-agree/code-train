#include <iostream>
#include <vector>

// 多叉树节点
class Node {
public:
    int val;
    std::vector<Node*> children;
    
    Node(int value) : val(value) {}
};

void traverse(Node* root) {
    if (root == nullptr) return;
    for (Node* child : root->children) {
        printf("从节点 %d 进入节点 %d\n", root->val, child->val);
        traverse(child);
        printf("从节点 %d 回到节点 %d\n", child->val, root->val);
    }
}

// DFS 算法把「做选择」「撤销选择」的逻辑放在 for 循环外面
void dfs(Node* root) {
    if (root == NULL) return;
    // 做选择
    printf("我已经进入节点 %d 啦\n", root->val);
    for (Node* child : root->children) {
        dfs(child);
    }
    // 撤销选择
    printf("我将要离开节点 %d 啦\n", root->val);
}

int main() {
    // 创建一个简单的多叉树
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* grandchild1 = new Node(5);
    Node* grandchild2 = new Node(6);

    root->children = {child1, child2, child3};
    child1->children = {grandchild1, grandchild2};

    // 调用traverse函数
    std::cout << "开始遍历多叉树：" << std::endl;
    // traverse(root);
    dfs(root);

    // 释放内存
    delete grandchild2;
    delete grandchild1;
    delete child3;
    delete child2;
    delete child1;
    delete root;

    return 0;
}