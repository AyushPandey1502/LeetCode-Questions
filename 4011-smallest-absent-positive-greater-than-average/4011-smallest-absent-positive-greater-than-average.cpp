class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int i = max(1, total / n + 1);
        while(true){
            if(!st.count(i)) return i;
            i++;
        }
    }
};