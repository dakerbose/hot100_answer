// 46. 全排列
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int s = nums.size();
        vector<bool> vis(s, false);
        auto dfs = [&](auto&& dfs){
            if(path.size() == s){
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < s; i++){
                if(!vis[i]){
                    vis[i] = true;
                    path.push_back(nums[i]);
                    dfs(dfs);
                    vis[i] = false;
                    path.pop_back();
                } 
            }
        };
        dfs(dfs);
        return ans;
    }
};
// 78. 子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> vis(n, false);
        auto dfs = [&](auto&& dfs, int i){
            if(i == n){
                ans.push_back(path);
                return;
            }
            // 不选
            dfs(dfs, i + 1);
            // 选
            vis[i] = true;
            path.push_back(nums[i]);
            dfs(dfs, i + 1);
            path.pop_back();
        };
        dfs(dfs, 0);
        return ans;
    }
};


// 17. 电话号码的字母组合
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> mp{{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
                            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res;
        string path = "";
        int s = digits.size();
        if(s == 0) return vector<string>{};
        auto dfs = [&](auto&& dfs, int i){
            if(i == s){
                res.push_back(path);
                return;
            }
            for(int j = 0; j < mp[digits[i]-'0'].size(); j++){
                string tmp = path;
                path += mp[digits[i]-'0'][j];
                dfs(dfs, i + 1);
                path = std::move(tmp);
            }
        };
        dfs(dfs, 0);
        return res;
    }
};

// 39. 组合总和
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        auto dfs = [&](auto&& dfs, int idx, int sum){
            if(sum == target){
                ans.push_back(path);
                return;
            }
            if(sum > target || idx >= nums.size()) return;
            // 不选
            dfs(dfs, idx + 1, sum);

            // 选择
            path.push_back(nums[idx]);
            dfs(dfs, idx, sum + nums[idx]);
            path.pop_back();
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};

// 22. 括号生成
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        auto dfs = [&](auto&& dfs, int left, int right){
          if(left == n && right == n){
            ans.push_back(str);
            return;
          }
          // 选)
          if(left > right && left <= n){
            string tmp = str;
            str += ")";
            dfs(dfs, left, right + 1);
            str = std::move(tmp);
          }
          // 选(
            if(left < n){
              string tmp = str;
              str += "(";
              dfs(dfs, left + 1, right);
              str = std::move(tmp);
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};

// 79. 单词搜索
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int dirs[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> res;
        vector<int> path;
        int flag = false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        auto dfs = [&](auto&& dfs, int i, int j, int idx){
            if(idx == word.size()){
                flag = true;
                return;
            }
            for(int k = 0; k < 4; k++){
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && word[idx] == board[x][y]){
                    vis[x][y] = true;
                    dfs(dfs, x, y, idx + 1);
                    vis[x][y] = false;
                    if(flag) break;
                }
            }
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    vis[i][j] = true;
                    dfs(dfs, i, j, 1);
                    vis[i][j] = false;
                    if(flag) return true;
                }
                
            }
        }
        return false;
    }
};
// 131. 分割回文串
class Solution {
public:
    vector<vector<string>> partition(string s) {
        auto check = [&](int left, int right)->bool{
            while(left < right){
                if(s[left++] != s[right--]){
                    return false;
                }
            }
            return true;
        };

        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        auto dfs = [&](auto&& dfs, int idx){
            if(idx == n){
                ans.push_back(path);
                return ;
            }
            for(int i = idx; i < n; i++){
                string sub_str = s.substr(idx, i - idx + 1);
                if(check(idx, i)){
                    path.push_back(sub_str);
                    dfs(dfs, i + 1);
                    path.pop_back();
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// 51. N皇后问题
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector board(n, string(n, '.')); // 一开始棋盘是空的，没有皇后
        vector<uint8_t> col(n), diag1(n * 2 - 1), diag2(n * 2 - 1); // vector<uint8_t> 效率比 vector<bool> 高
        auto dfs = [&](this auto&& dfs, int r) {
            if (r == n) {
                ans.push_back(board); // 复制整个棋盘
                return;
            }
            // 在 (r,c) 放皇后
            for (int c = 0; c < n; c++) {
                int rc = r - c + n - 1;
                if (!col[c] && !diag1[r + c] && !diag2[rc]) { // 判断能否放皇后
                    board[r][c] = 'Q'; // 放皇后
                    col[c] = diag1[r + c] = diag2[rc] = true; // 皇后占用了 c 列和两条斜线
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false; // 恢复现场
                    board[r][c] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};
