class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
    ListNode* prev = head;

        for (int i=0;i<n;i++){
            curr= curr->next;
        }
        if (!curr)
            return head->next;
        while(curr->next != NULL){
            prev= prev->next;
            curr= curr->next;
        }

        prev->next = prev->next->next;
         return head;

    }
};