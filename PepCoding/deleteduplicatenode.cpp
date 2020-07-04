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
    ListNode* deleteNode(ListNode* node)
    {
        Node *rm=node->next;
        node->next=rm->next;
        rm->next=NULL;
        delete rm;
        return node;
    }


    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;

        ListNode* cur=head->next;
        ListNode* prev=head;
        ListNode* frwd=NULL;
          
         while(cur->next!=NULL)
         {  frwd=cur->next;

            if(cur->val==prev->val)
            {
                prev=deleteNode(prev);
            }
             prev=cur;
             cur=frwd;

         } 
        return head;
        
    }
};