class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;
        int N = nums.size();
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(int i = 0; i < N; i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                maxIndex = i;
            }
            if(nums[i] < minNum){
                minNum = nums[i];
                minIndex = i;
            }
        }
        int minOp = (maxIndex > minIndex) ? maxIndex + 1 : minIndex + 1; // from Front only
        int fromBack = (maxIndex < minIndex) ? N - maxIndex : N - minIndex; // from Back Only
        if(fromBack < minOp) minOp = fromBack;
        if(maxIndex < minIndex){
            int op = maxIndex + N - minIndex + 1;
            if(op < minOp) minOp = op;
        }else{
            int op = minIndex + N - maxIndex + 1;
            if(op < minOp) minOp = op;
        }
        
        return minOp;
    }
};