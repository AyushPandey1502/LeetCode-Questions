class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end()); 
        double totalSum = accumulate(nums.begin(), nums.end(), 0.0);
        double halfSum = totalSum / 2, reducedSum = 0;
        int result = 0;

        while (reducedSum < halfSum) {
            double x = pq.top();
            pq.pop();
            x /= 2;
            reducedSum += x;
            pq.push(x);
            result++;
        }
        return result;
    }
};
