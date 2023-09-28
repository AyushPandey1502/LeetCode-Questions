class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        
        vector<int> result(even.size() + odd.size());
        int index = 0;
        
        for (int num : even) {
            result[index++] = num;
        }
        for (int num : odd) {
            result[index++] = num;
        }
        return result;
    }
};
