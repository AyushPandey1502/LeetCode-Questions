class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0], cnt = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == x) cnt++;
            else cnt--;
            if(cnt == 0){
                x = nums[i];
                cnt = 1;
            }
        }
        
        for(auto it : nums){
            if(it == x) count++;
        }

        int left = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == x) left++;
            int right = count - left;
            if (2 * left > (i + 1) && 2 * right > (n - i - 1)) return i;
        }
        return -1;
    }
};
