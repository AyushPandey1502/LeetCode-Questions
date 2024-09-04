class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (auto obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;
        int x = 0, y = 0;
        int maxDist = 0;

        for (int command : commands) {
            if (command == -2) {
                dirIndex = (dirIndex + 3) % 4;
            } else if (command == -1) {
                dirIndex = (dirIndex + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[dirIndex].first;
                    int nextY = y + directions[dirIndex].second;

                    if (obstacleSet.find(to_string(nextX) + "," +
                                         to_string(nextY)) ==
                        obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxDist;
    }
};
