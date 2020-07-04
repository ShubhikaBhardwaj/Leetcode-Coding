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

      ListNode* reverseList(ListNode* head) {

        ListNode* cur=head;
        ListNode* prev=NULL;

        while(cur!=NULL)
        {
           ListNode* frwd=cur->next;

           cur->next=prev;

           prev=cur;
           cur=frwd;

        }
        
        return prev;
   
        
    }

    int getDecimalValue(ListNode* head) {

    head=reverseList(head);

    int ans=0;
    ListNode* cur=head;
    
    int k=0;
    while(cur!=NULL)
    {  if(cur->val==1)
        {
            ans+=pow(2,k);
        }
        cur=cur->next;
        k++;
    }

    return ans;        
       
    }
};