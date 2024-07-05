class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
            l2 = l2->next;
        }
        if(carry) current->next = new ListNode(1);
        return head->next;
    }
};