class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int result = 0;
        int keyCount = 0;
        while (!pq.empty()) {
            int times = pq.top();
            pq.pop();
            result += times * ((keyCount / 8) + 1);
            keyCount++;
        }
        return result;
    }
};