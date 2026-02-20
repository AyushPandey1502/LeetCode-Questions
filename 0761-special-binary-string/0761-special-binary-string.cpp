class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> temp;
        
        for (int j = 0; j < s.length(); j++) {
            count += (s[j] == '1') ? 1 : -1;
            if (count == 0) {
                temp.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1; 
            }
        }

        sort(temp.rbegin(), temp.rend());
        string result;
        for (const string& it : temp) result += it;
        return result;
    }
};