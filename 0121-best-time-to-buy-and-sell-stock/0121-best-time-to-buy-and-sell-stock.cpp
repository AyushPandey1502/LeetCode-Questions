class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minNum = prices[0];
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - minNum;
            maxProf = max(maxProf, profit);
            minNum = min(minNum, prices[i]);
        }
        return maxProf;
    }
};