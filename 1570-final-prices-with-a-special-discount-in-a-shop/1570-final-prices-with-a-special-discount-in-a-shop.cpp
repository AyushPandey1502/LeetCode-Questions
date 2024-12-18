class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            int j;
            for(j = i + 1; j < n; j++){
                if(prices[j] <= prices[i]) break;
            }
            if(j == n)result.push_back(prices[i]);
            else result.push_back(prices[i] - prices[j]);
        }
        return result;
    }
};