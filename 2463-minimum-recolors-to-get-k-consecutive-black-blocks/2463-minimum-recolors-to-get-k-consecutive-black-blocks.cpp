class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, result = INT_MAX;
        int count = 0;

        for(int right = 0; right < blocks.size(); right++){
            if(blocks[right] == 'W') count++;
            if(right - left + 1 == k){
                result = min(result, count);
                if(blocks[left] == 'W') count--;
                left++;
            }
        }
        return result;
    }
};