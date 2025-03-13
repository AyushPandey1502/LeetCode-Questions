class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int vow = 0, cons = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') vow++;
                else cons++;
                if (vow == cons && (vow * cons) % k == 0) result++;
            }
        }
        return result;
    }
};
