class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), result = 1;
        int flag = 0;
        for(int i = 0; i < n; i++){
            int val = s[i] - 'a';
            if(flag & (1 << val)){
                result++;
                flag = 0;
            }
            flag = flag | (1 << val);
        }        
        return result;
    }
};
