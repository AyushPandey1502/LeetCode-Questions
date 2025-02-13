class Solution {
public:
    int halveArray(vector<int>& nums) {
        int result = 0;
        priority_queue<double> pq(nums.begin(), nums.end());
        double totalSum = accumulate(nums.begin(), nums.end(), 0.0);
        double sum = totalSum;

        while(sum > (totalSum / 2)){
            double x = pq.top();
            pq.pop();
            pq.push(x / 2);
            sum -= (x / 2);
            result++;
        }
        return result;
    }
};