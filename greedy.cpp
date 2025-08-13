// 121. 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_num = prices[0];
        for(int i = 1; i < prices.size(); i++){
            min_num = min(min_num, prices[i]);
            res = max(res, prices[i] - min_num);
        }
        return res;
    }
};

// 55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ss = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(i > ss) return false;
            ss = max(ss, i + nums[i]);
        }
        return true;
    }
};

// 45. 跳跃游戏Ⅱ
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int ans = 0, last = 0;
        for(int i = 0; i < nums.size()-1; i++){
            end = max(end, i + nums[i]);
            if(last == i){
                last = end;
                ans++;
            }
        }
        return ans;
    }
};

// 763. 划分字母区间
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26];
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            end = max(end, last[s[i] - 'a']);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
