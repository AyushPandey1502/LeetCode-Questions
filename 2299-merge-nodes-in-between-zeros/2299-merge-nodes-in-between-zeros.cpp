class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head->next;
        ListNode* newHead = new ListNode(0);
        ListNode* newTail = newHead;
        int sum = 0;

        while (current != nullptr) {
            if (current->val == 0) {
                if (sum > 0) {
                    newTail->next = new ListNode(sum);
                    newTail = newTail->next;
                    sum = 0;
                }
            } else {
                sum += current->val;
            }
            current = current->next;
        }
        return newHead->next;
    }
};
