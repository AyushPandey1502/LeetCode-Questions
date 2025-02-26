class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            int sum = 0, count = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    sum += i;
                    count++;
                    if (i != num / i) { 
                        sum += num / i;
                        count++;
                    }
                }
            }
            if (count == 4) result += sum;
        }
        return result;
    }
};
