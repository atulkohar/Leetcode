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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!k || !head || !head->next)
        {
            return head;
        }
        ListNode *first = head;
        ListNode *second = head;
        int len = 0;
        int c = k;
        while (c-- && second)
        {
            second = second->next;
            len++;
        }
        if (second == NULL)
        {
            k = k % len;
            return rotateRight(head, k);
        }
        while (second && second->next)
        {
            first = first->next;
            second = second->next;
        }
        second->next = head;
        head = first->next;
        first->next = NULL;
        return head;
    }
};