class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return nums;
        unordered_map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > freq.size() - k) {
                    result.push_back(pq.top().second);
                    pq.pop();
                }
        }
        return result;
    }
};