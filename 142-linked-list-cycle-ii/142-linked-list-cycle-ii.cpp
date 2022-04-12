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
    int cycleLength(ListNode *f, ListNode *s)
{
    int len = 0;
    // as they are in cycle, they will meet again
	// till then, keep moving the pointer and len++
	// when they will meet, the poinert has traversed the cycle fully
	// so len is the length of the list
    do
    {
        s = s->next;
        ++len;
    } while (f != s);

    return len;
}

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;

    // checking for cycle
    ListNode *fast = head, *slow = head;

    int len = 0;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            len = cycleLength(fast, slow);
            break;
        }
    }

    if (len == 0)
    {
        // no cycle
        return NULL;
    }

    ListNode *p = head;
    ListNode *q = head;

    // move it for length of cycle times
    for (int i = 0; i < len; ++i)
    {
        p = p->next;
    }

    // now, p from head and q from length of cycle will start moving
    // and will meet at that point where cycle start, that will be (p == q)

    while (p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p; // can return q as well, as both are pointing to same node only
}
};