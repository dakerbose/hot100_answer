
//62. 不同路径
/class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
        auto dfs = [&](auto&& dfs, int i, int j)->int{
            if(i < 0 || j < 0) return 0;
            if(vis[i][j] != INT_MAX) return vis[i][j];
            vis[i][j] = dfs(dfs, i-1, j) + dfs(dfs, i, j-1);
            return vis[i][j];
        };
        vis[0][0] = 1;
        return dfs(dfs, m-1, n-1);
    }
};

// 64. 最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        auto dfs = [&](auto&& dfs, int i, int j)->int{
            if(i < 0 || j < 0) return INT_MAX / 2;
            if(i == 0 && j == 0) return grid[0][0];
            int& res = memo[i][j];
            if(res != 0) return memo[i][j];
            res = min(dfs(dfs, i-1, j), dfs(dfs, i, j-1)) + grid[i][j];
            return res;
        };
        memo[0][0] = grid[0][0];
        return dfs(dfs, m-1, n-1);
    }
};
// 5. 最长回文子串
class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        int ans_left = 0, ans_right = 0;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(left >= 0 && right < n && str[left] == str[right]){
                left--;
                right++;
            }
            if(ans_right - ans_left < (right - 1) - (left + 1)){
                ans_left = left + 1;
                ans_right = right - 1;
            }
        }
        for(int i = 0; i < n - 1; i++){
            int left = i, right = i + 1;
            while(left >= 0 && right < n && str[left] == str[right]){
                left--;
                right++;
            }
            if(ans_right - ans_left < (right - 1) - (left + 1)){
                ans_left = left + 1;
                ans_right = right - 1;
            }
        }
        return str.substr(ans_left, ans_right - ans_left + 1);
    }
};
// 5. 最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        auto center_diffusion = [&](int left, int right){
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--;
                right++;
            }
            if(right - left - 1 > res.size()){
                res = s.substr(left+1, right-left-1);
            }
        };
        for(int i = 0; i < s.size(); i++){
            center_diffusion(i, i);
            center_diffusion(i, i+1);
        }
        return res;
    }
};
// 1143. 最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s = text1.size(), t = text2.size();
        vector<vector<int>> memo(s, vector<int>(t, -1));
        auto dfs = [&](auto&& dfs, int i, int j)->int{
            if(i < 0 || j < 0) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            if(text1[i] == text2[j]) {
                memo[i][j] = dfs(dfs, i-1, j-1) + 1;
            }
            else{
                memo[i][j] = max(dfs(dfs, i-1, j), dfs(dfs, i, j-1));
            }
            return memo[i][j];
        };
        return dfs(dfs, s-1, t-1);
    }
};
// 72. 编辑距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        int s = word1.size(), t = word2.size();
        vector memo(s, vector<int>(t, -1));
        auto dfs = [&](auto&& dfs, int i, int j)->int{
            if(i < 0) return j + 1;
            if(j < 0) return i + 1;
            if(memo[i][j] != -1) return memo[i][j];
            if(word1[i] == word2[j]){
                memo[i][j] = dfs(dfs, i-1, j-1);
                return memo[i][j];
            }
            memo[i][j] = min(min(dfs(dfs, i-1, j), dfs(dfs, i-1, j-1)), dfs(dfs, i, j-1)) + 1;
            return memo[i][j];
        };
        return dfs(dfs, s-1, t-1);
    }
};
// 70. 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        vector<int> f(n+1);
        f[1] = 1, f[2] = 2;
        for(int i = 3; i <= n; i++){
            f[i] = f[i-1] + f[i-2];
        } 
        return f[n];
    }
};
// 118. 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> c(numRows);
        for(int i = 0; i < numRows; i++){
            c[i].resize(i + 1, 1);
            for(int j = 1; j < i; j++){
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
        return c;
    }
};
// 198. 打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, INT_MIN);
        auto dfs = [&](auto&& dfs, int i)->int{
            if(i < 0) return 0;
            if(vis[i] != INT_MIN) return vis[i];
            vis[i] = max(dfs(dfs, i-1), dfs(dfs, i-2) + nums[i]);
            return vis[i];
        };
        return dfs(dfs, n-1);
    }
};
// 198. 打家劫舍
class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n+1, INT_MAX/2);
        auto dfs = [&](auto&& dfs, int i)->int{
            if(i < 0) return INT_MAX/2;
            if(i == 0) return 0;
            if(memo[i] < INT_MAX/2) return memo[i];
            for(int j = 1; j * j <= i; j++){
                memo[i] = min(memo[i], dfs(dfs, i - j * j) + 1);
            }
            return memo[i];
        };
        return dfs(dfs, n);
    }
};
// 279. 完全平方数
class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n+1, INT_MAX/2);
        auto dfs = [&](auto&& dfs, int i)->int{
            if(i < 0) return INT_MAX/2;
            if(i == 0) return 0;
            if(memo[i] < INT_MAX/2) return memo[i];
            for(int j = 1; j * j <= i; j++){
                memo[i] = min(memo[i], dfs(dfs, i - j * j) + 1);
            }
            return memo[i];
        };
        return dfs(dfs, n);
    }
};
// 322. 零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector memo(n, vector<int>(amount+1, -1));
        auto dfs = [&](auto&& dfs, int i, int c)->int{
            if(i < 0) return c == 0 ? 0 : INT_MAX / 2;
            if(memo[i][c] != -1) return memo[i][c];
            if(c < coins[i]){
                memo[i][c] = dfs(dfs, i-1, c);
                return memo[i][c];
            }
            memo[i][c] = min(dfs(dfs, i, c-coins[i])+1, dfs(dfs, i-1, c));
            return memo[i][c];
        };
        int ans = dfs(dfs, n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
// 139. 单词拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = ranges::max(wordDict, {}, &string::length).length();

        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size() + 1, -1);
        auto dfs = [&](auto&& dfs, int i)->bool{
            if(i == 0) return true;
            if(memo[i] != -1) return memo[i];
            for(int j = i - 1; j >= max(i-max_len, 0); j--){
                if(uset.count(s.substr(j, i - j)) && dfs(dfs, j)){
                    memo[i] = true;
                    return true;
                }
            }
            return memo[i] = false;
        };
        return dfs(dfs, s.size());
    }
};
// 300. 最长递增子序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dfs = [&](auto&& dfs, int i)->int{
            if(memo[i] != -1) return memo[i];
            int max_len = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    max_len = max(max_len, dfs(dfs, j) + 1);
                }
            }
            return memo[i] = max_len;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(dfs, i));
        }

        return ans;
    }
};
// 152. 乘积最大子数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_nums(n), min_nums(n);
        max_nums[0] = min_nums[0] = nums[0];
        for(int i = 1; i < n; i++){
            max_nums[i] = max({max_nums[i-1] * nums[i], min_nums[i-1] * nums[i], nums[i]});
            min_nums[i] = min({max_nums[i-1] * nums[i], min_nums[i-1] * nums[i], nums[i]});
        }
        return *max_element(max_nums.begin(), max_nums.end());
    }
};
// 32. 最长有效括号
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        auto dfs = [&](auto&& dfs, int i)->int{
            if(i < 0) return 0;
            if(memo[i] != -1) return memo[i];
            int& res = memo[i];
            if(s[i] == ')') {
                if(i-1>0 && s[i-1] == '('){
                    res =  dfs(dfs, i-2) + 2;
                    return res;
                }
                if(i-dfs(dfs, i-1)-1 >= 0 && s[i-dfs(dfs, i-1)-1] == '('){
                    res = dfs(dfs, i-1) + 2 + dfs(dfs, i-dfs(dfs, i-1)-2);
                    return res;
                }
            }
            res = 0;
            return res;
        };
        int ans = 0;
        dfs(dfs, s.size()-1);
        for(int i = 0; i < s.size(); i++){
            ans = max(ans, dfs(dfs, i));
        }
        return ans;
    }
};
