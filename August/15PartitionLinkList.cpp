// Problem Link : https://leetcode.com/problems/partition-list/description/


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
    ListNode* partition(ListNode* head, int x) {

        ListNode* LessHead = new ListNode(-1);
        ListNode* GreatHead = new ListNode(-1);
        ListNode* LessTail = LessHead;
        ListNode* GreatTail = GreatHead;


        while(head){
            if(head->val < x ){
                LessTail->next = head;
                LessTail = LessTail->next;
            }else{
                GreatTail->next = head;
                GreatTail = GreatTail->next;
            }

            head = head->next;
        }

        GreatTail->next = NULL;
        LessTail->next = GreatHead->next;
        return LessHead->next;
        
    }
};