class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = '1' + s + '1'; 
        int n = s.size();
        int right = 1, ones = 0, result = 0;
        while(s[right++] == '1') ones++;

        while (right < n) {
            if (s[right] == '1') {
                int count = 0, j = right - 1;
                while (j >= 0 && s[j] == '0') {
                    count++;
                    j--;
                }
                while (right < n && s[right] == '1') {
                    ones++;
                    right++;
                }

                if (right == n) break;
                while (right < n && s[right] == '0') {
                    count++;
                    right++;
                }
                result = max(result, count);
            } else right++;
        }

        return result + ones - 1;
    }
};
