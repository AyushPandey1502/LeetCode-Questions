class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> index(26, 0);
        for(int i = 0; i < n; i++) index[s[i]-'a'] = i;
        vector<int> result;
        int maxIndex = 0, count = 0;
        for(int i = 0; i < n; i++){
            maxIndex = max(maxIndex, index[s[i]-'a']);
            count++;
            if(maxIndex == i){
                result.push_back(count);
                count = 0;
            }
        }
        return result;
    }
};