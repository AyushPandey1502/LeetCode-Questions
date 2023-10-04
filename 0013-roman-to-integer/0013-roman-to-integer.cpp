class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int preVal = 0;
        int result = 0;
        for(int i = s.size()-1; i >= 0; i--){
            int currentVal = roman[s[i]];
            
            if(currentVal < preVal) result -= currentVal;
            else result += currentVal;
            preVal = currentVal;
        }
        return result;
    }
};