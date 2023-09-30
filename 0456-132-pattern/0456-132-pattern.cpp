class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> stack;
        for(int i = nums.size()-1; i>= 0; i--){
            if(nums[i] < s3) return true;
            else while(!stack.empty() && nums[i] > stack.top()){
                s3 = stack.top(); stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }
};