// 35. 搜索插入的位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

// 74. 搜索二维矩阵
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) { // 还有剩余元素
            if (matrix[i][j] == target) {
                return true; // 找到 target
            }
            if (matrix[i][j] < target) {
                i++; // 这一行剩余元素全部小于 target，排除
            } else {
                j--; // 这一列剩余元素全部大于 target，排除
            }
        }
        return false;
    }
};

// 34. 在排序数组中查找元素的第一个位置和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        int left_ = 0, right_ = nums.size()-1;
        while(left_ <= right_){
            int mid = left_ + (right_ - left_) / 2;
            if(nums[mid] <= target){
                left_ = mid + 1;
            }
            else{
                right_ = mid - 1;
            }
        }
        if(left == left_) return {-1, -1};
        return {left, left_ - 1};
    }
};

// 33. 搜素旋转排序数组
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        auto check = [&](int mid)->bool{
            int x = nums[mid];
            if(x > nums.back()){
                return target > nums.back() && target <= x;
            }
            else
                return target > nums.back() || target <= x;
        };
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[left] == target ? left : -1; 
    }
};

// 153.寻找旋转排序数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int x = nums.back();
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= x){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

// 4. 寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) {
            swap(a, b);
        }

        int m = a.size(), n = b.size();
        int left = -1, right = m;
        while (left + 1 < right) { // 开区间 (left, right) 不为空
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i - 2;
            if (a[i] <= b[j + 1]) {
                left = i; // 缩小二分区间为 (i, right)
            } else {
                right = i; // 缩小二分区间为 (left, i)
            }
        }
        int i = left;
        int j = (m + n + 1) / 2 - i - 2;
        int ai = i >= 0 ? a[i] : INT_MIN;
        int bj = j >= 0 ? b[j] : INT_MIN;
        int ai1 = i + 1 < m ? a[i + 1] : INT_MAX;
        int bj1 = j + 1 < n ? b[j + 1] : INT_MAX;
        int max1 = max(ai, bj);
        int min2 = min(ai1, bj1);
        return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
    }
};
