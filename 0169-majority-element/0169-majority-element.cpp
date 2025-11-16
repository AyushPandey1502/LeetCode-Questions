class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, elem;
        for(int i = 0; i < n; i++){
            if(count == 0){
                elem = nums[i];
                count = 1;
            }else if(elem == nums[i]) count++;
            else count--;
        }
        int cnt = 0;
        for(auto it : nums){
            if(it == elem) cnt++;
        }
        if(cnt > (n / 2)) return elem;
        else return -1;
    }
};