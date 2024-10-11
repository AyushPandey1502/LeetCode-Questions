class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> arrivalTimes;
        for (int i = 0; i < n; ++i) {
            arrivalTimes.push_back({times[i][0], i});
        }
        sort(arrivalTimes.begin(), arrivalTimes.end());
        priority_queue<int, vector<int>, greater<int>> freeChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingHeap;
        for (int i = 0; i < n; ++i) {
            freeChairs.push(i);
        }
        for (auto [arrival, friendIdx] : arrivalTimes) {
            while (!leavingHeap.empty() && leavingHeap.top().first <= arrival) {
                freeChairs.push(leavingHeap.top().second);
                leavingHeap.pop();
            }
            int chair = freeChairs.top();
            freeChairs.pop();
            if (friendIdx == targetFriend) {
                return chair;
            }
            leavingHeap.push({times[friendIdx][1], chair});
        }
        return -1;
    }
};
