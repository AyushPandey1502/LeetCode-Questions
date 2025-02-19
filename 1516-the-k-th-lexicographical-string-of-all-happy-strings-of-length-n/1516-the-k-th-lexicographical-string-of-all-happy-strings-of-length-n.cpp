class Solution {
public:
    set<string> result;

    void generateStrings(string s, int n) {
        if (n == 0) {
            result.insert(s);
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
        return *next(result.begin(), k - 1); 
    }
};
