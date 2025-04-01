class Solution {
public:
    long long findMaxPoints(int i, int n, vector<long long>& dp, vector<vector<int>>& ques){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        long long take = ques[i][0] + findMaxPoints(i + ques[i][1] + 1, n, dp, ques);
        long long notTake = findMaxPoints(i + 1, n, dp, ques);
        return dp[i] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return findMaxPoints(0, n, dp, questions);
    }
};