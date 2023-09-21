class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int result = 0;
        map<char,int>count;

        for(int i = 0; i < stones.size(); i++){
            count[stones[i]]++;
        }
        for(int i = 0; i < jewels.size(); i++){
            result += count[jewels[i]];
        }
        return result;
    }
};