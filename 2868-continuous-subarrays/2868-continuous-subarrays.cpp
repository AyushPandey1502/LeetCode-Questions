class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int left = 0, right = 0;
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        
        while (right < nums.size()) {
            pq1.push({nums[right], right});
            pq2.push({nums[right], right});

            while (!pq1.empty() && !pq2.empty() && (pq1.top().first - pq2.top().first) > 2) {
                left++;
                while (!pq1.empty() && pq1.top().second < left) pq1.pop();
                while (!pq2.empty() && pq2.top().second < left) pq2.pop();
            }

            count += (right - left + 1);
            right++;
        }
        return count;
    }
};