class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> freqV, freqC;
        int vow = 0, cons = 0;

        for(auto it : s){
            if(vowels.find(it) != string::npos){
                vow = max(vow, ++freqC[it]);
            }else cons = max(cons, ++freqC[it]);
        }
        return vow + cons;
    }
};