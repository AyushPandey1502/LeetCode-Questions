class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> vec(profits.size());
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            vec[i] = {capital[i], profits[i]};
        }
        int i = 0;
        priority_queue<int> pq;
        sort(vec.begin(), vec.end()); 
        
        while (k--) {
            while (i < n && vec[i].first <= w) {
                pq.push(vec[i].second);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};