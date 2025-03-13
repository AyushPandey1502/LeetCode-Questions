class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        long long result = 0;
        unordered_map<int, vector<pair<int, int>>> map;
        map[0].push_back({0, 0}); 
        
        int vows = 0, cons = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vows++;
            else cons++;
            int diff = vows - cons;
            for (auto it : map[diff]) {
                int vowels = vows - it.first; 
                int consonants = cons - it.second;  
                if (vowels == consonants && (vowels * vowels) % k == 0) result++;
            }
            map[diff].push_back({vows, cons});
        }
        
        return result;
    }
};