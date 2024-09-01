class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;
        for(int i = 0; i < k; i++){
            leftSum += cardPoints[i];
        }
        int result = leftSum;
        int right = n - 1;
        for(int i = k-1; i >= 0; i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[right--];
            result = max(result, leftSum + rightSum);
        }
        return result;
    }
};
