class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int N = customers.size();
        long long currentTime = 0, totalWaitTime = 0;
        for(int i = 0; i < N; i++) {
            int arrival = customers[i][0];
            int cookTime = customers[i][1];
            if(currentTime < arrival) {
                currentTime = arrival;
            }
            currentTime += cookTime;
            totalWaitTime += (currentTime - arrival);
        }
        return (double)totalWaitTime / N;
    }
};
