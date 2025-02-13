class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int> str1(26, 0), str2(26, 0);
        for(int i = 0; i < n; i++){
            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }

        for(int i = n; i < m; i++){
            if(str1 == str2) return true;
            str2[s2[i] - 'a']++;
            str2[s2[i-n] - 'a']--;
        }
        return (str1 == str2);
    }
};