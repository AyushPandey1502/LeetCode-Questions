class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto it : happiness) pq.push(it);
        long long result = 0;
        int count = 0;
        for(int i = 0; i < k; i++){
            result += max(0, pq.top() - count);
            pq.pop();
            count++;
        }
        return result;
    }
};