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
        ListNode *ansHead = NULL, *ansTail = NULL;
        ListNode *ansHead1 = NULL, *ansTail1 = NULL;
        ListNode *temp = head;
        while(temp)
        {
            if(temp->val < x)
            {
                if(!ansHead)
                {
                    ansHead = new ListNode(temp->val);
                    ansTail = ansHead;
                }
                else
                {
                    ansTail->next = new ListNode(temp->val);
                    ansTail = ansTail->next;
                }
            }
            else
            {
                if(!ansHead1)
                {
                    ansHead1 = new ListNode(temp->val);
                    ansTail1 = ansHead1;
                }
                else
                {
                    ansTail1->next = new ListNode(temp->val);
                    ansTail1 = ansTail1->next;
                }
            }
            temp = temp->next;
        }
        if(ansHead == NULL)
            return head;
        ansTail->next = ansHead1;
        return ansHead;
    }
};