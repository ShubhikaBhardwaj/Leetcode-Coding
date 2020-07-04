/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur=headA;

    while(cur->next!=NULL)
    {
     cur=cur->next;
    
    ListNode *tail=cur;
    tail->next=headB;

    ListNode *slow=headA;
    ListNode *fast=headA;

    bool ans=false;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
          break;
    }
    ans=slow==fast?true:false;

    if(ans==false)
    {
        return NULL;
    }

    slow=headA;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;

    }

    return slow;

        
    }
};