class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        sort(rewards.begin(), rewards.end());

        unordered_set<int> possibleRewards = {0};

        for (int reward : rewards) {
            unordered_set<int> newRewards;

            for (int x : possibleRewards) {
                if (reward > x) {
                    newRewards.insert(x + reward);
                }
            }

            possibleRewards.insert(newRewards.begin(), newRewards.end());
        }

        return *max_element(possibleRewards.begin(), possibleRewards.end());
    }
};