class Solution {
public:
    bool endsWith(const string& fullString, const string& ending) {
        if (ending.size() > fullString.size())
            return false;

        return fullString.compare(fullString.size() - ending.size(),
                                  ending.size(), ending) == 0;
    }
    
    int minOperations(vector<string>& logs) {
        int N = logs.size();
        int result = 0;
        for (auto path : logs) {
            if(endsWith(path, "../")){
                if(result <= 0) continue;
                else result--;
            }else if(endsWith(path, "./")){
                continue;
            }else{
                result++;
            }
        }
        return result;
    }
};