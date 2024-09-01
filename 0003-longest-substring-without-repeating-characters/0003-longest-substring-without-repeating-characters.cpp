class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0); 
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            freq[currentChar]++;
            while (freq[currentChar] > 1) {
                char leftChar = s[left];
                freq[leftChar]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};