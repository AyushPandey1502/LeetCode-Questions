class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string word : words) {
            freq[word]++;
        }
        
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return (a.first != b.first) ? a.first < b.first : a.second > b.second;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }
        
        vector<string> result;
        while (result.size() < k) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
