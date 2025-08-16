// 560. 和为k的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] + nums[i];
        }
        for(auto p : nums){
            ans += umap[p-k];
            umap[p]++;
        }
        return ans;
    }
};
// 239. 滑动窗口最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> dq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.back().first <= nums[i]){
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
            // if(dq.size() > k) dq.pop_front();
            if(dq.front().second < i - k + 1) dq.pop_front();
            if(i >= k-1) res.push_back(dq.front().first);
        }
        return res;
    }
};
// 76. 最小覆盖子串
class Solution {
public:
    bool compare(vector<int>& cnt_A, vector<int>& cnt_B) const{
        for(int i = 0; i < 128; i++){
            if(cnt_A[i] < cnt_B[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> cnt_A(128);
        vector<int> cnt_B(128);
        int left = 0;
        for(int i = 0; i < t.size(); i++){
            cnt_B[t[i]]++;    
        }
        int min_left = INT_MIN/2, min_right = INT_MAX/2;
        for(int right = 0; right < s.size(); right++){
            cnt_A[s[right]]++;
            while(compare(cnt_A, cnt_B)){
                if(right - left < min_right - min_left){
                    min_left = left, min_right = right;
                }
                cnt_A[s[left++]]--;                
            }
        }
        if(min_right == INT_MAX/2) return "";
        return s.substr(min_left, min_right-min_left+1);
    }
};
