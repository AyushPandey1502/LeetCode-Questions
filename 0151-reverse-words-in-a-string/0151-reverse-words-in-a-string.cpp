class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
        reverse(s.begin(), s.end());
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if (i >= n) break;
            int start = j;
            while(i < n && s[i] != ' ') s[j++] = s[i++];
            reverse(s.begin() + start, s.begin() + j);
            s[j++] = ' ';
        }
         if(j > 0) j--;
        return s.substr(0, j);
    }
};