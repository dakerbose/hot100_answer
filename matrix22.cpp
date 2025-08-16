// 矩阵置零
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row_zero = false, col_zero = false;
        // 1. 判断第0行、列是否是有零
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col_zero = true;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                row_zero = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(col_zero){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        if(row_zero){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};

// 54. 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int m = matrix.size(), n = matrix[0].size();
        int d = 0;
        vector<int> res; res.push_back(matrix[0][0]);

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        int last_x = 0, last_y = 0;
        for(int i = 1; i < m * n; i++){
            int x = last_x + dirs[d][0], y = last_y + dirs[d][1];
            if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y]){
                d = (d + 1) % 4;
            }
            x = last_x + dirs[d][0], y = last_y + dirs[d][1];
            vis[x][y] = true;
            res.push_back(matrix[x][y]);
            last_x = x, last_y = y;
        }
        return res;
    }
};
 // 240. 搜索二维矩阵
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while(true){
            if(matrix[i][j] == target) return true;
            while(i < m && matrix[i][j] < target) i++;
            if(i == m) return false;
            if(matrix[i][j] == target) return true;
            while(j >= 0 && matrix[i][j] > target) j--;
            if(j < 0) return false;
        }
    }
};
