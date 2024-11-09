class Solution {
public:
    int digProd(int num){
        int result = 1;
        while(num > 0){
            if(result == 0) return 0;
            result *= num % 10;
            num /= 10;
        }
        return result; 
    }

    int smallestNumber(int n, int t) {
        int result = n;
        while(true){
            if(digProd(result) % t == 0) return result;
            result++;
        }    
        return -1;
    }
};