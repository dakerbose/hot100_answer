// 200. 岛屿数量
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](auto&& dfs, int i, int j){
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){
                return;
            }
            grid[i][j] = '2';
            dfs(dfs, i+1, j);
            dfs(dfs, i-1, j);
            dfs(dfs, i, j + 1);
            dfs(dfs, i, j - 1);
        };
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(dfs, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// 994. 腐烂的橘子
class Solution {
public:
    int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool has_one = false, has_two = false, has_zero = false;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) has_zero = true;
                else if(grid[i][j] == 1) has_one = true;
                else if(grid[i][j] == 2){
                    has_two = true;
                    q.push({i, j});
                } 
            }
        }
        // 全是腐烂的
        if(!has_zero && !has_one) return 0;
        if(!has_two && !has_one) return 0;
        int cnt = -1;
        while(!q.empty()){
            int s = q.size();
            cnt++;
            for(int i = 0; i < s; i++){
                auto p = q.front(); q.pop();
                for(int k = 0; k < 4; k++){
                    int x = p.first + dirs[k][0], y = p.second + dirs[k][1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return cnt;
    }
};
// 207. 课程表
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> umap;
        vector<int> indegree(n);
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i][1]].push_back(nums[i][0]);
            indegree[nums[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto pp : umap[p]){
                if(--indegree[pp] == 0){
                    q.push(pp);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};
// 207. 课程表
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> umap;
        vector<int> indegree(n);
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i][1]].push_back(nums[i][0]);
            indegree[nums[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto pp : umap[p]){
                if(--indegree[pp] == 0){
                    q.push(pp);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};
