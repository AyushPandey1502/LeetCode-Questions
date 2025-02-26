class Solution {
public:
    int sumDivisorsIfFour(int num) {
        vector<int> divisors;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                divisors.push_back(i);
                if (i != num / i) {
                    divisors.push_back(num / i);
                }
            }
            if (divisors.size() > 4) return 0;
        }
        
        if (divisors.size() == 4) {
            return divisors[0] + divisors[1] + divisors[2] + divisors[3];
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result += sumDivisorsIfFour(num);
        }
        return result;
    }
};