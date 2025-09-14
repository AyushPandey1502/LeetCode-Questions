class Solution {
private:
    string tol(string& r) {
        string s=r;
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });
        return s;
    }

private:
    string check(string s,unordered_map<string,string>&mp,unordered_set<string>&st){
        if(st.find(s)!=st.end())return s;
        s=tol(s);
        if(mp.find(s)!=mp.end())return mp[s];
        return "";
    }
public:
    vector<string> spellchecker(vector<string>& arr, vector<string>& q) {
        int n = arr.size();
        int m = q.size();
        vector<string> sol(m, "");
        unordered_set<string> st(arr.begin(), arr.end());
        unordered_map<string,string>mp,mp_2;
        for(int i=0;i<n;i++) {
            string g=tol(arr[i]);
            if(mp.find(g)==mp.end())mp[g]=arr[i];
            for(int k=0;k<g.length();k++)
            {
                if(g[k]=='a' || g[k]=='e' || g[k]=='i' || g[k]=='o' || g[k]=='u')g[k]='1';
            }
            if(mp_2.find(g)==mp.end())mp_2[g]=arr[i];
        }
        for (int i = 0; i < m; i++) {

            sol[i]=check(q[i],mp,st);
            if(sol[i]=="")
            {
                string str=tol(q[i]);
                for(int j=0;j<str.length();j++)
                {
                    if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u')str[j]='1';
                }
                if(mp_2.find(str)!=mp.end())sol[i]=mp_2[str];
            }
        }
        return sol;
    }
};