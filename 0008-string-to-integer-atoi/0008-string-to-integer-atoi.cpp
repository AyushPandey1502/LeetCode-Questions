class Solution {
public:
    long recursiveAtoi(int index, string s, int sign, long result){
        if(index > s.size() || !isdigit(s[index])){
            return sign * result;
        }
        result = result * 10 + (s[index] - '0');
        if(sign * result > INT_MAX) return INT_MAX;
        if(sign * result < INT_MIN) return INT_MIN;
        return recursiveAtoi(index + 1, s, sign, result);
    }
    int myAtoi(string s) {
        int index = 0;
        int sign = 1;
        while(index < s.size() && s[index] == ' ') index++;
        if(index < s.size() && (s[index] == '-' || s[index] == '+')){
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }
        long result = recursiveAtoi(index, s, sign, 0);
        return static_cast<int>(result);
    }
};