// 53. 最大子数组和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int last = nums[0];
        for(int i = 1; i < nums.size(); i++){
            last = max(0, last);
            res = max(res, last + nums[i]);
            last = last + nums[i];
        }
        return res;
    }
};
// 56. 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(auto p : nums){
            if(res.empty()){
                res.push_back(p); continue;
            }
            vector<int>& b = res.back();
            if(b[1] < p[0]){
                res.push_back(p);
                continue;
            }
            b[1] = max(b[1], p[1]);
        }
        return res;
    }
};
// 189. 轮转数组
class Solution {
public:
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            swap(nums[left++], nums[right--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
// 238. 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1); 
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] * nums[i-1];
        }
        vector<int> back(n, 1);
        for(int i = n-2; i >= 0; i--){
            back[i] = back[i + 1] * nums[i + 1];
        }
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++){
            res[i] = pref[i] * back[i];
        }
        return res;
    }
};
// 41. 缺失的第一个正数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
