class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }
        int index = 0;
        for(auto it : set){
            nums[index++] = it;
        }
        return set.size();
    }
};