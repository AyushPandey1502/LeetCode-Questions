class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr->next != nullptr) {
            if (toRemove.count(curr->next->val)) {
                curr->next = curr->next->next;
            } else curr = curr->next;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
