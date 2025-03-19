/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == slow){
        free(head);
        return NULL;
    }
    fast = head;
    while(fast->next != slow){
        fast = fast->next;
    }
    fast->next = slow->next;
    slow->next = NULL;
    free(slow);
    return head;
}
