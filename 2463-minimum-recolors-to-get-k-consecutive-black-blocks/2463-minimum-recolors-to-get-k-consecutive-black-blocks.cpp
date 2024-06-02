class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int sum = 0;
        vector<int> vec(blocks.begin(), blocks.end());
        for(int i = 0; i < blocks.size(); i++){
            if(blocks[i] == 'B') vec[i] = ++sum;
            else vec[i] = sum;
        }
        int minRecolors = abs(vec[k-1] - k);
        for(int i = k; i < blocks.size(); i++){
            minRecolors = min(minRecolors, abs(vec[i] - k - vec[i-k]));
        }
        return minRecolors;
    }
};