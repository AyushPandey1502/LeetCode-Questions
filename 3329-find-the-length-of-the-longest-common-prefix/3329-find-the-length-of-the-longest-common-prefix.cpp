class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        for(auto x : arr1){
            while(!set.count(x) && x > 0){
                set.insert(x);
                x = x / 10;
            }
        }
        int maxLen = 0;
        for(auto x : arr2){
            while(x > 0){
                if(set.find(x) != set.end()){
                    maxLen = max(maxLen, static_cast<int>(to_string(x).size()));
                    break;
                }
                x = x / 10;
            }
        }
        return maxLen;
    }
};