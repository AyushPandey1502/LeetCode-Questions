class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *temp;

        // Move the fast pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) return head; // Return the original head if n is greater than the length of the list
            fast = fast->next;
        }
        // Handle the case where the head node needs to be removed
        if (fast == nullptr) {
            head = head->next;
            return head;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow->next != nullptr) {
            slow->next = slow->next->next;
        }
        
        return head;
    }
};
