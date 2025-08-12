// 215. 数组中的第K个最大元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 维护最小堆以保证堆顶是最小的，这样就可以顺利弹出
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(i >= k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

// 347. 前K个高频元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        // 用堆去模拟实现频数的排列
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto p : umap){
            pq.push({p.second, p.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

// 295. 数据流的中位数
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
    
    void addNum(int num) {
        left.push(num);
        // 先保证堆的平衡
        if(left.size() > right.size() + 1){
            int t = left.top();
            right.push(t);
            left.pop();
        }
        // 再保证堆的有序 
        if(!left.empty() && !right.empty() && left.top() > right.top()){
            int l_top = left.top();
            int r_top = right.top();
            left.pop();left.push(r_top);
            right.pop();right.push(l_top);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return static_cast<double>(left.top()+right.top()) / 2;
        }
        else{
            return static_cast<double>(left.top());
        }
    }
};
