// 20. 有效的括号
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else {
                if(st.empty()) return false;
                if(c == ')' && st.top() == '('){
                    st.pop(); continue;
                }
                if(c == ')' && st.top() != '('){
                    return false;
                }
                if(c == ']' && st.top() == '['){
                    st.pop(); continue;
                }
                if(c == ']' && st.top() != '['){
                    return false;
                }
                if(c == '}' && st.top() == '{'){
                    st.pop(); continue;
                }
                if(c == '}' && st.top() != '{'){
                    return false;
                }
            }
        }
        return st.empty();
    }
};

// 155. 最小栈
class MinStack {
public:
    stack<pair<int, int>> st; 
    MinStack() {
        st.emplace(0, INT_MAX);
    }
    
    void push(int val) {
        st.emplace(val, min(getMin(), val));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// 194. 字符串解码
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        auto decode = [&](auto&& decode)->string{
            string str = "";
            int k = 0;
            while(i < s.size()){
                char c = s[i]; i++;
                if(isalpha(c)){
                    str += c;
                }
                else if(isdigit(c)){
                    k = k * 10 + (c - '0');
                }
                else if(c == '['){
                    string t = decode(decode);
                    for(int j = 0; j < k; j++){
                        str += t;
                    }
                    k = 0;
                }
                else 
                    break;
            }
            return str;
        };
        return decode(decode);
    }
};

// 739. 每日温度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

// 84. 柱状图中的最大矩形
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
