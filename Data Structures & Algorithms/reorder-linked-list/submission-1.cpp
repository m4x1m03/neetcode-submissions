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
    void reorderList(ListNode* head) {
        ListNode* start = head;
        ListNode* prevMid = nullptr;
        ListNode* mid = head;
        ListNode* end = head;

        while(end!=nullptr && end->next!=nullptr){
            prevMid=mid;
            mid = mid->next;
            end = end->next->next;
        }
        if(prevMid!=nullptr){prevMid->next=nullptr;}

        //reverse second half
        ListNode* curr = mid;
        ListNode* prev = nullptr; //head of reversed second half
        ListNode* next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        ListNode* answer = new ListNode(-1);
        curr = answer;
        while(start != nullptr && prev != nullptr && start != prev){
            curr->next=start;
            curr = curr->next;
            start = start->next;
            curr->next=prev;
            curr = curr->next;
            prev = prev->next;
        }
        if(prev != nullptr){
            curr->next = prev;
        }
    }
};
