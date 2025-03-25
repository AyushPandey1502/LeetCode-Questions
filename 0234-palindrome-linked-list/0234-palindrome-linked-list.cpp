class Solution {
public:
    ListNode* curr;
    bool isPalindrome(ListNode* head) {
        curr = head;
        return check(head);
    }

    bool check(ListNode* head){
        if(head == nullptr) return true;
        bool result = check(head->next) && head->val == curr->val;
        curr = curr->next;
        return result;
    }
};