class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] result = new int[2*n];
        for(int i = 0; i < result.length; i++){
            result[i] = nums[i%n];
        }
        return result;
    }
}