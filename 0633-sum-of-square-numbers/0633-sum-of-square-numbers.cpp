class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right){
            long square = left*left + right*right;
            if(square == c) return true;
            else if(square < c) left++;
            else right--;
        }
        return false;
    }
};