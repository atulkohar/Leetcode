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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head; // -1 -> 1 -> 2 -> 2 -> 4 -> 4 -> 5  // just add node ahead
        ListNode *curr = dummyNode;

        while (curr->next != NULL and curr->next->next != NULL)
        {
            if (curr->next->val != curr->next->next->val)
            {
                curr = curr->next;
            }
            else
            {
                int value = curr->next->val;
                // loop until we get the repeated value
                while (curr->next and curr->next->val == value)
                {
                    curr->next = curr->next->next;
                }
            }
        }
        return dummyNode->next;
        // T(n) -> O(n) // SC ->(1)
    }
};