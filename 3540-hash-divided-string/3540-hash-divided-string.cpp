class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string result = "";
        for(int i = 0; i < n; i += k){
            string ss = s.substr(i, k);
            int points = 0;
            for(int j = 0; j < k; j++){
                points = (points + (ss[j] - 'a')) % 26;
            }
            result += ('a' + points);
        }
        return result;
    }
};
