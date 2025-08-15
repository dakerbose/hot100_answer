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
// 101. 对称二叉树
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr){
            return p == q;
        }
        return p->val == q->val && check(p->left, q->right) && check(q->left, p->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return root;
        return check(root->left, root->right);
    }
};
// 543. 二叉树的直径
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        auto dfs = [&](auto&& dfs, TreeNode* cur)->int{
          if(cur == nullptr) return -1;
          int l = dfs(dfs, cur->left);
          int r = dfs(dfs, cur->right);
          ans = max(ans, l + r + 2);
          return max(l, r) + 1;
        };
        dfs(dfs, root);
        return ans;
    }
};
// 102. 二叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> path;
        if (root == nullptr)
            return ans;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                path.push_back(t->val);
                q.pop();
                TreeNode* l = t->left;
                if (l)
                    q.push(l);
                TreeNode* r = t->right;
                if (r)
                    q.push(r);
            }
            ans.emplace_back(move(path));
        }
        return ans;
    }
};
// 108. 将有序数组转换为二叉搜索树
class Solution {
public:
    TreeNode* root; 
    TreeNode* subproblem(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = subproblem(nums, left, mid-1);
        cur->right = subproblem(nums, mid + 1, right);
        
        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int mid = left + (right - left) / 2;
        root = new TreeNode(nums[mid]);
        root = subproblem(nums, left, right);
        return root;
    }
};

// 230. 二叉搜索树中的第K小的元素
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = 0;
        auto search = [&](auto&& search, TreeNode* cur){
            if(cur == nullptr || k == cnt) return;
            // if(cur->left){
                search(search, cur->left);
            // }
            cnt++;
            if(k == cnt) res = cur->val;
            // if(cur->right){
                search(search, cur->right);
            // }
        };
        search(search, root);
        return res;
    }
};
// 199. 二叉树的右视图
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == nullptr) return {};
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* p =  q.front();
                q.pop();
                if(p->left)  q.push(p->left);
                if(p->right) q.push(p->right);
                if(i == s - 1) res.push_back(p->val);                
            }
        }
        return res;
    }
};
// 114. 二叉树展开为链表
class Solution {
public:
    TreeNode* head;
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};
// 105. 从前序与中序遍历序列构造二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        auto dfs = [&](auto&& dfs, int pre_l, int pre_r, int in_l, int in_r)->TreeNode*{
            if(pre_l == pre_r) return nullptr;
            int left_size = mp[preorder[pre_l]] - in_l;
            TreeNode* left = dfs(dfs, pre_l+1, pre_l+1+left_size, in_l, in_l+left_size);
            TreeNode* right = dfs(dfs, pre_l+1+left_size, pre_r, in_l+1+left_size, in_r);
            return new TreeNode(preorder[pre_l] , left, right);
        };
        return dfs(dfs, 0, n, 0, n);
    }
};
// 437. 路径总和Ⅲ
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> cnt;
        int res = 0;
        cnt.insert(make_pair(0, 1));
        auto dfs = [&](auto&& dfs, TreeNode* cur, long long s){
            if(cur == nullptr) return;
            s += cur->val;
            res += cnt[s - targetSum];
            cnt[s]++;
            dfs(dfs, cur->left, s);
            dfs(dfs, cur->right, s);
            cnt[s]--;
        };
        dfs(dfs, root, 0);
        return res;
    }
};

// 124. 二叉树的最大路径和
class Solution {
public:
    int maxPathSum(TreeNode* root) {
          int res = INT_MIN;
          auto dfs = [&](auto&& dfs, TreeNode* cur)->int{
                if(cur == nullptr) return 0;
                int l = dfs(dfs, cur->left);
                if(l < 0) l = 0;
                int r = dfs(dfs, cur->right);
                if(r < 0) r = 0;
                res = max(res, l + r + cur->val);
                
                return max(max(l, r), 0) + cur->val; 
          };
          dfs(dfs, root);
          return res;
    }
};

// 236. 二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == nullptr || root == p || root == q){
        return root;
      }
      TreeNode* l = lowestCommonAncestor(root->left, p, q);
      TreeNode* r = lowestCommonAncestor(root->right, p, q);
      if(l && r)  return root;
      return l ? l : r;
    }
};
// 98. 验证二叉树
class Solution {
public:
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
