/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    struct ListNode* current = NULL;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        if (!current) {
            result = current = (struct ListNode*)malloc(sizeof(struct ListNode));
        } else {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
        }
        
        current->val = sum % 10;
        current->next = NULL;
    }
    
    return result;
}
