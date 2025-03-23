class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int it : digits) freq[it]++;

        int result = 0;
        for (int num = 100; num < 1000; num += 2) {
            vector<int> temp = freq;
            int n = num;
            bool flag = true;

            while (n > 0) {
                int dig = n % 10;
                if (--temp[dig] < 0) {
                    flag = false;
                    break;
                }
                n /= 10;
            }
            if (flag) result++;
        }

        return result;
    }
};
