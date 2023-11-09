class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {      
        int count = 0; 
        unordered_map<int,bool> map;
        for(int i=0;i<nums.size();i++)
            map[nums[i]] = true;
        for(int i=0;i<nums.size();i++)
        {
            if(map[nums[i]-diff] && map[nums[i]+diff])
                count++;
        }
        return count;
    }
};