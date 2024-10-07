class Solution {
public:
    int minLength(string s) {
        bool found = true;
        while (found) {
            found = false;
            size_t pos = s.find("AB");
            if (pos != string::npos) {
                s.erase(pos, 2);
                found = true;
            }
            pos = s.find("CD");
            if (pos != string::npos) {
                s.erase(pos, 2);
                found = true;
            }
        }
        return s.size(); 
    }
};
