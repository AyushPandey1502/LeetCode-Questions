class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> set;
        for (int x : nums) {
            if(x < k) {return -1;
            } else if(x > k) set.insert(x);
        }
        return set.size();
    }
};