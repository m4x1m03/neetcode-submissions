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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* end = dummy;

        //move end pointer by n then start a pointer that will remove the next element
        for(int i = 0; i<=n; i++){
            end = end->next;
        }
        ListNode* remove = new ListNode(-1);
        remove = dummy;
        while(end != nullptr){
            end = end->next;
            remove = remove->next;
        }
        remove->next=remove->next->next;

        return dummy->next;
    }
};
