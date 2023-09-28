class Solution {
    public int[] sortArrayByParity(int[] nums) {
        ArrayList<Integer> even = new ArrayList<>();
        ArrayList<Integer> odd = new ArrayList<>();

        for (int num : nums) {
            if (num % 2 == 0) {
                even.add(num);
            } else {
                odd.add(num);
            }
        }

        int[] result = new int[nums.length];
        int index = 0;

        for (int num : even) {
            result[index++] = num;
        }

        for (int num : odd) {
            result[index++] = num;
        }

        return result;
    }
}
