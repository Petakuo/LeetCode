/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = NULL;
    while(head){
        head = head->next;
        ptr1->next = ptr2;
        ptr2 = ptr1;
        ptr1 = head;
    }
    return ptr2;
}

void reorderList(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* rev = slow->next;
    slow->next = NULL;
    rev = reverse(rev);
    struct ListNode* temph1 = head;
    struct ListNode* temph2 = head;
    struct ListNode* tempr = rev;
    while(temph1 && tempr){
        temph1 = temph1->next;
        tempr = tempr->next;
        temph2->next = rev;
        temph2 = temph1;
        rev->next = temph2;
        rev = tempr;
    }
}
