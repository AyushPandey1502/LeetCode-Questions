class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critIndex;
        int index = 0;
        int prevVal = head->val;
        while (head->next != NULL) {
            int currVal = head->val;
            int nextVal = head->next->val;
            if ((currVal > prevVal && nextVal < currVal) ||
                (currVal < prevVal && nextVal > currVal)) {
                critIndex.push_back(index);
            }
            prevVal = currVal;
            head = head->next;
            index++;
        }
        if (critIndex.size() < 2)
            return {-1, -1};

        int maxDist = critIndex.back() - critIndex.front();
        int minDist = INT_MAX;

        for (int i = 1; i < critIndex.size(); ++i) {
            minDist = min(minDist, critIndex[i] - critIndex[i - 1]);
        }
        return {minDist, maxDist};
    }
};