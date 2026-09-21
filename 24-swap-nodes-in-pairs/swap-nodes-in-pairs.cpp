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
    ListNode* swapPairs(ListNode* head) {

        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        ListNode *curr = nullptr;
        ListNode *prev = nullptr;
        ListNode *temp = nullptr;

        curr = head;
        head = curr -> next;

        while(curr != nullptr && curr -> next != nullptr){
            temp = curr -> next;
            curr -> next = temp -> next;
            temp -> next = curr;
            if(prev != nullptr){
                prev -> next = temp;
            }

            prev = curr;
            curr = curr -> next;
        }

        return head;
    }
};