class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long points = 0;
        int N = enemyEnergies.size();
        int i = 0;
        int j = N - 1;
        if (N == 1)
            return currentEnergy / enemyEnergies[0];
        sort(enemyEnergies.begin(), enemyEnergies.end());

        while (i <= j) {
            if (currentEnergy < enemyEnergies[i]) {
                if (points == 0)
                    return 0;
                else {
                    while (currentEnergy < enemyEnergies[i]) {
                        currentEnergy += enemyEnergies[j--];
                    }
                }
            } else {
                points += currentEnergy / enemyEnergies[i];
                currentEnergy %= enemyEnergies[i];
            }
        }
        return points;
    }
};
