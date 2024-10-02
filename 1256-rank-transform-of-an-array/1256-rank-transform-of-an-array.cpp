class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> rank;
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i = 0; i < nums.size(); i++){
            rank[nums[i]] = i + 1;
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};