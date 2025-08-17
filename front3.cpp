// 3. 无重复字符的最长字串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> uset;
        int n = s.size();
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            while(uset.count(s[right]) > 0){
                uset.erase(s[left++]);
            }
            uset.insert(s[right]);
            ans = max(ans, right - left + 1); 
        }
        return ans;
    }
};

// 438. 找到字符串中所有字母异位词
class Solution {
public:
    bool cmp(vector<int>& cnt_s, vector<int>& cnt_p){
        for(int i = 0; i < 128; i++){
            if(cnt_s[i] != cnt_p[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt_s(128), cnt_p(128);
        for(auto pp : p){
            cnt_p[pp]++;
        }
        int left = 0;
        vector<int> res;
        for(int right = 0; right < s.size(); right++){
            cnt_s[s[right]]++;
            if(cmp(cnt_s, cnt_p)){
                res.push_back(left);
            }
            if(right - left + 1 == p.size()) cnt_s[s[left++]]--;
        }
        return res;
    }
};

// 283. 移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                right++;
            }
            else if(nums[left] == 0){
                swap(nums[left], nums[right]);
                right++, left++;
            }
            else {
                right++, left++;
            }
        }
    }
};
// 11. 盛水最多的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            height[left] < height[right] ? left++ : right--;
        }
        return ans;
    }
};

// 15. 三数之和 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int x = nums[i];
            if(i > 0 && nums[i-1] == x) continue;
            if (x + nums[i + 1] + nums[i + 2] > 0) break; // 优化一
            if (x + nums[n - 2] + nums[n - 1] < 0) continue; // 优化二
            int j = i + 1, k = n-1;
            while(j < k){
                int sum = nums[j] + nums[k] + x;
                if(sum == 0){
                    res.push_back({x, nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else if(sum > 0) k--;
                else if(sum < 0) j++;
            }
        }
        return res;
    }
};
// 接雨水
class Solution {
public:
    int trap(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                int bottom = st.top(); st.pop();
                if(!st.empty()){
                    int ht = min(nums[i], nums[st.top()]);
                    res += (ht - nums[bottom]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return res;
    }
};
// 1. 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(umap.contains(target-x) > 0) return {i, umap[target-x]};
            umap[x] = i;
        }
        return {-1, -1};
    }
};
// 49. 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            string str_copy = str;
            sort(str.begin(), str.end());
            umap[str].push_back(str_copy);
        }
        for(auto p : umap){
            res.push_back(p.second);
        }
        return res;
    } 
};
// 128. 最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> umap;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            umap.insert(nums[i]);
        }
        for(int x : umap){
            if(umap.contains(x-1)) continue;
            int y = x;
            while(umap.contains(y + 1)) y++;
            res = max(res, y - x + 1);
        }
        return res;
    }
};
