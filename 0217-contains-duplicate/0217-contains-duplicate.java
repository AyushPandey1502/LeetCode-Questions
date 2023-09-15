class Solution {
    public boolean containsDuplicate(int[] nums) {
        int i = 0;
        int len = nums.length;
        Arrays.sort(nums);
        while(i<=len-2){
            if(nums[i]==nums[i+1]){
                return true;
            }
            i++;
        }
        return false;
    }
}