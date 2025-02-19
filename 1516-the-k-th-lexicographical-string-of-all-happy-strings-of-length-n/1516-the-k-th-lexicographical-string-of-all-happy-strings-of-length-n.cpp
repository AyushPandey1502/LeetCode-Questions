class Solution {
public:
    vector<string> result;

    void generateStrings(string s, int n) {
        if (n == 0) {
            result.push_back(s);
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) { 
            if (!s.empty() && s.back() == ch) continue;
            generateStrings(s + ch, n - 1);
        }
    }

    string getHappyString(int n, int k) {
        generateStrings("", n);
        if (result.size() < k) return "";
        sort(result.begin(), result.end());
        return result[k-1];
    }
};
