class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto dir : moves){
            if(dir == 'L') x--;
            if(dir == 'R') x++;
            if(dir == 'U') y++;
            if(dir == 'D') y--;
        }
        return (x == 0 && y == 0);
    }
};