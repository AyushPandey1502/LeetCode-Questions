class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pts, critIndex;
        ListNode* current = head;
        while(current != NULL) {
            pts.push_back(current -> val);
            current = current -> next;
        }
        for(int i = 1; i < pts.size() - 1; i++) {
            if((pts[i] > pts[i - 1] && pts[i] > pts[i + 1]) || 
               (pts[i] < pts[i - 1] && pts[i] < pts[i + 1])) {
                critIndex.push_back(i);
            }
        }
        if(critIndex.size() < 2) return {-1, -1};
        int maxDist = critIndex.back() - critIndex.front();
        int minDist = INT_MAX;
        for(int i = 1; i < critIndex.size(); i++) {
            minDist = min(minDist, critIndex[i] - critIndex[i - 1]);
        }
        return {minDist, maxDist};
    }
};
