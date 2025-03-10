class Solution {
public:
    long long atleastK(string word, int k) {
        long long result = 0;
        int left = 0, right = 0, n = word.size(), count = 0;
        unordered_map<char, int> vow;
        
        while (right < n) {
            char ch = word[right];
            
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vow[ch]++;
            else count++;
            while (vow.size() == 5 && count >= k) {
                result += n - right;
                
                char rm = word[left];
                if (rm == 'a' || rm == 'e' || rm == 'i' || rm == 'o' || rm == 'u') {
                    if (--vow[rm] == 0) vow.erase(rm);
                } else count--;
                left++;
            }
            right++;
        }
        return result;
    }

    long long countOfSubstrings(string word, int k){
        return atleastK(word, k) - atleastK(word, k+1);
    }
};
