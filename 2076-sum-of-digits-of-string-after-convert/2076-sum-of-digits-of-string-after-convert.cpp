class Solution {
public:
    int getLucky(string s, int k) {
        int charSum = 0;
        for(int i = 0; i < s.size(); i++){
            int pos = (s[i] - 'a' + 1);
            charSum += (pos % 10) + ((pos / 10) % 10);
        }
        k--;
        int result = charSum;
        while(k > 0){
            int digSum = 0;
            while(result > 0){
                digSum += result % 10;
                result /= 10;
            }
            result = digSum;
            k--;
        }
        return result;
    }
};