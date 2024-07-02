class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        for(int x : nums1) map1[x]++;
        for(int x : nums2) map2[x]++;

        vector<int> result;
        for(auto it : map1){
            if(map2[it.first] > 0){
                int count = min(it.second, map2[it.first]);
                while(count > 0){
                    result.push_back(it.first);
                    count--;
                }
            }
        }
        return result;
    }
};