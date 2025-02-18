class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        generate(0, 0, pattern, result);
        reverse(result.begin(), result.end());
        return result;
    }

    int generate(int index, int count, string pattern, string& result){
        if(index != pattern.size()){
            if(pattern[index] == 'I') generate(index + 1, index + 1, pattern, result);
            else count = generate(index + 1, count, pattern, result);
        }
        result += to_string(count + 1);
        return count + 1;
    }
};