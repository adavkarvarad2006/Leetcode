/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto head:lists){
            while(head){
                pq.push(head->val);
                head = head->next;
            }
        }

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            int v = pq.top();
            pq.pop();
            tail->next = new ListNode(v);
            tail = tail->next;
        }

        return dummy.next;
    }
};