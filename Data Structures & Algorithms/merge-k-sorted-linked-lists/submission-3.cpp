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
        if(lists.size() == 0){return nullptr;}
        for(int step = 1; step < lists.size(); step *= 2){
            for(int i =0; i+step<lists.size(); i += 2*step){
                lists[i]=mergeTwoLists(lists[i], lists[i+step]);
            }
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else{
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        curr->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};
