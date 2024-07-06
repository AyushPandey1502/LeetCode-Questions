class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int left = 0, right = enemyEnergies.size() -1;
        long long  points = 0;
        while(left <= right){
            if(currentEnergy >= enemyEnergies[left]){
                points = points + currentEnergy / enemyEnergies[left];
                currentEnergy = currentEnergy % enemyEnergies[left];
            }
            else if(points > 0){
                currentEnergy = currentEnergy + enemyEnergies[right];
                right--;
            }else{
                break;
            }
        }
        return points;
    }
};