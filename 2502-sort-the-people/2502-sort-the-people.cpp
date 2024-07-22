class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> order;
        for(int i = 0; i < names.size(); i++){
            order.push_back({heights[i], names[i]});
        }
        sort(order.rbegin(), order.rend());
        for(int i = 0; i < names.size(); i++){
            names[i] = order[i].second;
        }
        return names;
    }
};