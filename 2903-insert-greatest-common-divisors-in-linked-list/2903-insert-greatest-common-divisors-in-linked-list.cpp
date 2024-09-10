class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) return head; 

        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            ListNode* next = current->next;
            ListNode* temp = new ListNode(gcd(current->val, next->val)); 
            current->next = temp;
            temp->next = next;
            current = next;
        }
        return head;
    }
};
