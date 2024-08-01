class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for(auto it : details){
            int age = (it[11] - '0') * 10 + (it[12] - '0');
            if(age > 60) result++;
        }
        return result;
    }
};