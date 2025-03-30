class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), result = 0;
        int right = 0;
        vector<int> freq(26, 0);
        
        while (right < n) {
            if (++freq[s[right] - 'a'] >= 2) {
                result++;
                fill(freq.begin(), freq.end(), 0);
                freq[s[right] - 'a'] = 1;  
            }
            right++;
        }
        
        return result + 1;
    }
};
