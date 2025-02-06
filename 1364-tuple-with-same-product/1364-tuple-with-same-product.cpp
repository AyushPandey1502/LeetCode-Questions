class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                map[nums[i] * nums[j]]++;
            }
        }
        for(auto it : map){
            result += 8 * ((it.second - 1) * it.second / 2);
        }
        return result;
    }
};