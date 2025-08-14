// 94. 二叉树的中序遍历
class Solution {
public:
    vector<int> res = {};
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        if(root->left) inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
        return res;
    }
};

// 104. 二叉树的最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        auto dfs = [&](auto&& dfs, TreeNode* root)->int{
            if(root == nullptr) return 0;
            return max(dfs(dfs, root->left), dfs(dfs, root->right)) + 1;
        };
        return dfs(dfs, root);
    }
};

// 226.翻转二叉树
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* lres = invertTree(root->left);
        TreeNode* rres = invertTree(root->right);
        root->left = rres;
        root->right = lres;
        return root;
    }
};
