class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            size_t start = s.find(part);
            s = s.substr(0, start) + s.substr(start + part.size());
        }
        return s;
    }
};