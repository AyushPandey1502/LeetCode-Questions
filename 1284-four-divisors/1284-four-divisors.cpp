class Solution {
public:
    vector<int> sumDivisors;

    void precomputeDivisors(int limit) {
        sumDivisors.assign(limit + 1, 0);
        vector<int> countDivisors(limit + 1, 0);

        for (int i = 1; i <= limit; i++) {
            for (int j = i; j <= limit; j += i) {
                countDivisors[j]++;
                sumDivisors[j] += i;
            }
        }
        for (int i = 1; i <= limit; i++) {
            if (countDivisors[i] != 4) sumDivisors[i] = 0;  
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        precomputeDivisors(maxNum);

        int result = 0;
        for (int num : nums) {
            result += sumDivisors[num]; 
        }
        return result;
    }
};
