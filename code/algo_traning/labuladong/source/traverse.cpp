class traverse
{
private:
    /* data */
public:
    traverse(/* args */);
    ~traverse();
    int count(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int leftNum = count(root->left);
        int rightNum = count(root->right);
        return 1 + leftNum + rightNum;
    }
};

traverse::traverse(/* args */)
{
}

traverse::~traverse()
{
}
