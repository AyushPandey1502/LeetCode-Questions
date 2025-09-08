class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> findNSE(vector<int>& nums, int n){
        vector<int> result(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            result[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> findPSE(vector<int>& nums, int n){
        vector<int> result(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            result[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse = findPSE(nums, n);
        vector<int> nse = findNSE(nums, n);

        long long result = 0;
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            result = (result + (1LL * left * right * nums[i]) % MOD) % MOD;
        }
        return static_cast<int>(result);
    }
};