class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string num;
            for(int i = 0; i < s.size()-1; i++){
                num += to_string(((s[i] - '0') + (s[i+1] - '0')) % 10);
            }
            s = num;
        }
        return s.size() == 2 && s[0] == s[1];
    }
};
