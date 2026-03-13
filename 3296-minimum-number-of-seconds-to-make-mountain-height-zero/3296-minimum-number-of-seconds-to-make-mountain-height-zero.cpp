class Solution {
public:
    bool isPossible(long long maxTime, int mountainHeight, vector<int>& workerTimes) {
        long long totalHt = 0;
        for (int time : workerTimes) {
            long long ht = 0;
            long long currTime = 0;
            while (currTime + (ht + 1) * time <= maxTime) {
                ht++;
                currTime += ht * time;
            }
            totalHt += ht;
            if (totalHt >= mountainHeight) return true;
        }
        return totalHt >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1;
        while (!isPossible(high, mountainHeight, workerTimes)) high *= 2;
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};