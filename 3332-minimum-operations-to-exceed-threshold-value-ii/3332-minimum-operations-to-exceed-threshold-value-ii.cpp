class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
        while(pq.top() < k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            result++;
        }
        return result;
    }
};