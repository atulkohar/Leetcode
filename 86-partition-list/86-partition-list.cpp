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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *temp = head;
        ListNode *sm;            
        ListNode *gr;            
        ListNode *thead1 = NULL; 
        ListNode *thead2 = NULL; 
        ListNode *next;          
        while (temp != NULL)
        {
            if (temp->val >= x)
            {
                if (thead2 == NULL)
                {
                    thead2 = temp;
                    gr = temp;
                }
                else
                    gr->next = temp, gr = gr->next;
            }
            else
            {
                if (thead1 == NULL)
                {
                    thead1 = temp;
                    sm = temp;
                }
                else
                    sm->next = temp, sm = sm->next;
            }
            next = temp->next;
            temp->next = NULL;
            temp = next;
        }
        if (thead1 == NULL)
            return thead2; 
        if (thead2 == NULL)
            return thead1; 
        sm->next = thead2; 
        return thead1;     
    }
};