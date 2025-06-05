class Solution {
public:
    char dfs(unordered_map<char, vector<char>> adjList, char ch, vector<int>& visited){
        visited[ch-'a'] = 1;
        char result = ch;
        for(auto it : adjList[ch]){
            if(visited[it-'a'] == 0) result = min(result, dfs(adjList, it, visited));
        }
        return result;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        unordered_map<char, vector<char>> adjList;
        for(int i = 0; i < n; i++){
            char u = s1[i], v = s2[i];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        string result;
        for(int i = 0; i < m; i++){
            vector<int> visited(26, 0);
            char minChar = dfs(adjList, baseStr[i], visited);
            result.push_back(minChar);
        }
        return result;
    }
};