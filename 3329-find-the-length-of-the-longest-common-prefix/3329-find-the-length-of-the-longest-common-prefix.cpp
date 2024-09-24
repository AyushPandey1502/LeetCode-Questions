class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> map;
        for(int it : arr1){
            string num = to_string(it);
            string prefix = "";
            for(int i = 0; i < num.size(); i++){
                prefix += num[i];
                map[prefix]++;
            }
        }

        int maxLen = 0;
        for(int it : arr2){
            string num = to_string(it);
            string prefix = "";
            for(int i = 0; i < num.size(); i++){
                prefix += num[i];
                if(map.find(prefix) != map.end()){
                    maxLen = max(maxLen, i + 1);
                }
            }
        }
        return maxLen;
    }
};