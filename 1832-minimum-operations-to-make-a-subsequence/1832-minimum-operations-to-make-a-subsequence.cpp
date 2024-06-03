class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < target.size(); ++i) {
            indexMap[target[i]] = i;
        }
        
        vector<int> filteredArr;
        for (int num : arr) {
            if (indexMap.find(num) != indexMap.end()) {
                filteredArr.push_back(indexMap[num]);
            }
        }
        
        return target.size() - lengthOfLIS(filteredArr);
    }

private:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }
        return lis.size();
    }
};