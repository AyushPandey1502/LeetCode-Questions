class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        long long result = 0;
        unordered_map<long long, unordered_map<long long, long long>> map;
        map[0][0] = 1; 
        
        long long vows = 0, cons = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vows++;
            else cons++;
            long long diff = vows - cons;
            for (auto it : map[diff]) {
                long long vowels = vows % k - it.first; 
                if ((vowels * vowels) % k == 0) result += it.second;
            }
            map[diff][vows % k]++;
        }
        return result;
    }
};