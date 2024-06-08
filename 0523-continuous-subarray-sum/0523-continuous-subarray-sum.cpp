class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map; // <remainder, index>
        map[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;
            if(map.find(remainder) != map.end()){
                if((i - map[remainder]) >= 2) return true;
            }else{
                map[remainder] = i;
            }
        }
        return false;
    }
};