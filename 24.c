/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = head->next;
    if(ptr2){
        head = ptr2;
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while(ptr1 && ptr1->next){
        ptr2->next = ptr1->next;
        ptr1->next = ptr1->next->next;
        ptr2 = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return head;
}
