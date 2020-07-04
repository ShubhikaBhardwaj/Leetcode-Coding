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
    ListNode* TH=NULL;
    ListNode* TT=NULL;

    void addLast(ListNode* node)
    { 
        if(TT==NULL&&TH==NULL)
        {
            TT=node;
            TH=node;
        }

        else
        {
            TT->next=node;
            TT=node;
        }
        
    }

    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL||(head->next==NULL&&head->val==val))
        return NULL;

        ListNode* cur=head;

        while(cur!=NULL)
        {
            if(cur->val!=val)
            {
                ListNode* rm=cur;
                ListNode* frwd=cur->next;
                rm->next=NULL;
                addLast(rm);
                cur=frwd;
            }
            
            else
            cur=cur->next;
        }
        head=TH;
        return head;
        
    }
};