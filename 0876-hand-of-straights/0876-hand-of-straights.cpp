class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> map;
        for (int x : hand) map[x]++;
        for (int x : hand) {
            if (map[x] == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                if (map[x + i] == 0) return false;
                map[x + i]--;
            }
        }
        return true;
    }
};
