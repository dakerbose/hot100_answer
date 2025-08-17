
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
