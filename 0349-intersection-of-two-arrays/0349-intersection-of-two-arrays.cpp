class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>vec;
        if(nums1.size()<nums2.size()){
            for(auto it:nums1){
                if(find(nums2.begin(),nums2.end(),it) != nums2.end())
                    vec.insert(it);
            }
        }
        else{
            for(auto it:nums2){
                if(find(nums1.begin(),nums1.end(),it) != nums1.end())
                    vec.insert(it);
            }
        }
        vector<int>ans(vec.begin(),vec.end());
        return ans;
    }
};