class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(to_string(i));
        }
        sort(nums.begin(), nums.end());
        vector<int> result;
        for(int i = 0; i < n; i++){
            result.push_back(stoi(nums[i]));
        }
        return result;
    }
};