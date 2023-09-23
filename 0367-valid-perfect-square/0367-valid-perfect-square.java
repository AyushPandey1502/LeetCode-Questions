class Solution {
    public boolean isPerfectSquare(int num) {
        int i = 1; // Start with i = 1
        while (num > 0) {
            num -= i; // Subtract the current odd number from num
            i += 2;   // Increment i by 2 to get the next odd number
        }
        return num == 0; // If num becomes 0, it's a perfect square
    }
}
