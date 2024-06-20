class Solution {
public:
    bool isPossibleToPlace(vector<int> &position, int force, int m){
        int prev = position[0];
        int count = 1;
        for(int i = 1; i < position.size(); i++){
            if(abs(prev - position[i]) >= force){
                count++;
                prev = position[i];
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int minForce = 1;
        int maxForce = position[n-1] - position[0];
        int result = 0;

        while(minForce <= maxForce){
            int midForce = minForce + (maxForce - minForce) / 2;
            if(isPossibleToPlace(position, midForce, m)){
                result = midForce;
                minForce = midForce + 1;
            }else{
                maxForce = midForce - 1;
            }
        }
        return result;
    }
};