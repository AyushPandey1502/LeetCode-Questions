class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";
        priority_queue<pair<char, int>> pq;
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (auto& [ch, count] : freq) pq.push({ch, count});        
        while (!pq.empty()) {
            auto [ch, count] = pq.top();
            pq.pop();
            int addCount = min(count, repeatLimit);
            result += string(addCount, ch);
            if (count > addCount) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top();
                pq.pop();
                result += nextCh;
                if (nextCount > 1) pq.push({nextCh, nextCount - 1});
                pq.push({ch, count - addCount});
            }
        }
        return result;
    }
};
