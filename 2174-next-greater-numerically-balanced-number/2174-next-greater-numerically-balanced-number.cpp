class Solution {
public:
    bool isBalanced(int x){
        vector<int> freq(10, 0);
        while(x > 0){
            freq[x % 10]++;
            x /= 10;
        }
        for(int d = 0; d < 10; d++){
            if(freq[d] > 0 && freq[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n+1; i <= 1224444; i++){
            if(isBalanced(i)) return i;
        }
        return -1;
    }
};