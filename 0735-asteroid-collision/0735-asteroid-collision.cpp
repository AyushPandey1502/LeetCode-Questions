class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int it : asteroids) {
            while (!result.empty() && result.back() > 0 && it < 0 && result.back() < -it) {
                result.pop_back();
            }
            if (!result.empty() && result.back() > 0 && it < 0 && result.back() == -it) {
                result.pop_back();
            } 
            else if (result.empty() || result.back() < 0 || it > 0) {
                result.push_back(it);
            }
        }
        return result;
    }
};
