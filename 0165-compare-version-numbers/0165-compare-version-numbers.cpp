class Solution {
public:
    vector<int> splitVersion(string &str, char delimiter){
        vector<int> result;
        stringstream ss(str);
        string token;

        while(getline(ss, token, delimiter)) result.push_back(stoi(token));
        return result;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitVersion(version1, '.');
        vector<int> v2 = splitVersion(version2, '.');
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};