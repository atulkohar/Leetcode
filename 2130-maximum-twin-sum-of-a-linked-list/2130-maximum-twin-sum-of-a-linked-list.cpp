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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prv = NULL, *fwd = NULL;
        while(curr)
        {
            fwd = curr->next;
            curr->next = prv;
            prv = curr;
            curr = fwd;
        }
        return prv;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        temp = reverse(temp);
        int sum = INT_MIN;
        while(head and temp)
        {
            sum = max(sum, head->val+temp->val);
            head = head->next;
            temp = temp->next;
        }
        return sum;
    }
};