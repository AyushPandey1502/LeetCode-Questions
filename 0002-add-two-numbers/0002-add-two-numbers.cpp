class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
        }
        if (carry) {
            current->next = new ListNode(carry);
        }

        return head->next;
    }
};
