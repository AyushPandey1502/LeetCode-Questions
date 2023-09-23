class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        long long int answer = -1;

        while(start <= end){
            long long int mid = start + (end - start)/2;
            long long int square = mid * mid;

            if(square == num){
                return true;
            }else if(square < num){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            
        }
        return false;
    }
};