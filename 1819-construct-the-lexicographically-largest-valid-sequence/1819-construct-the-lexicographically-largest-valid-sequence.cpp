class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, 0);
        vector<bool> visited(n+1, false);
        backtrack(result, visited, n, 0);
        return result;
    }

    bool backtrack(vector<int>& result, vector<bool>& visited, int n, int index){
        while(index < result.size() && result[index] != 0) index++;
        if(index == result.size()) return true;

        for(int i = n; i >= 1; i--){
            if(visited[i]) continue;
            if(i == 1){
                result[index] = 1;
                visited[1] = true;
                if(backtrack(result, visited, n, index+1)) return true;
                result[index] = 0;
                visited[i] = false;
            }else if(index + i < result.size() && result[index + i] == 0){
                result[index] = i;
                result[index+i] = i;
                visited[i] = true;
                if(backtrack(result, visited, n, index+1)) return true;
                result[index] = 0;
                result[index+i] = 0;
                visited[i] = false;
            }
        }
        return false;
    }
};