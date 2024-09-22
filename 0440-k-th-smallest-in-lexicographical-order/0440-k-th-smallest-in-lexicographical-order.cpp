class Solution {
public:
    int findKthNumber(int n, int k) {
        int currentNumber = 1;
        --k; 
        while (k > 0) {
            long stepCount = calculateSteps(currentNumber, n);
            
            if (stepCount <= k) {
                currentNumber++;
                k -= stepCount;
            } else {
                currentNumber *= 10;
                k--;
            }
        }
        return currentNumber;
    }

    long calculateSteps(long prefix, long n) {
        long stepCount = 0;
        long first = prefix;
        long last = prefix;
        
        while (first <= n) {
            stepCount += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return stepCount;
    }
};
