// OPTIMAL APPROACH : MOORE'S VOTING ALGORITHM
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count++;
            }else if(nums[i] == element){
                count++;
            }else{
                count--;
            }
        }

        // If it is possible that majority element not present then
        // we need to check the occurence of element in array.
        count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                count++;
            }
            if(count > n/2){
                return element;
            }
        }
        return -1;
    }
};