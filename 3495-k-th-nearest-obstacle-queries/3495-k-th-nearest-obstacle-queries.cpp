class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> result;
        priority_queue<int> maxHeap;  

        for (auto query : queries) {
            int x = query[0];
            int y = query[1];
            int dist = abs(x) + abs(y);

            maxHeap.push(dist);

            if (maxHeap.size() < k) {
                result.push_back(-1);
            } else {
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
                result.push_back(maxHeap.top());
            }
        }

        return result;
    }
};