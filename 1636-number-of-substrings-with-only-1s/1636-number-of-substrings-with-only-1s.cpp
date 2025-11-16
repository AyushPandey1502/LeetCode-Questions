class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        long long result = 0, count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                result = (result + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }else count++;
        }
        result = (result + (count * (count + 1) / 2) % MOD) % MOD;
        return result;
    }
};