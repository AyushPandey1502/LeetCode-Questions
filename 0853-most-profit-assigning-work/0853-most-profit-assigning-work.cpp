class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); i++) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        vector<int> maxProfitAtDifficulty;
        int maxProfit = 0;

        for (const auto& job : jobs) {
            maxProfit = max(maxProfit, job.second);
            maxProfitAtDifficulty.push_back(maxProfit);
        }

        int result = 0;
        int j = 0;

        for (const int& ability : worker) {
            while (j < jobs.size() && jobs[j].first <= ability) {
                j++;
            }
            if (j > 0) {
                result += maxProfitAtDifficulty[j - 1];
            }
        }

        return result;
    }
};
