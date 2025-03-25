class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto it : lists){
            if(it) pq.push(it);
        }
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            dummy->next = node;
            dummy = dummy->next;
            if(node->next) pq.push(node->next);
        }
        return head->next;
    }
};