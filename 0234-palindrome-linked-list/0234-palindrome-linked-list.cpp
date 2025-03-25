class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr && curr->val == st.top()){
            st.pop();
            curr = curr->next;
        }
        return curr == nullptr;
    }
};