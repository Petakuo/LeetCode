/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if(!head->next) return head;
    struct ListNode* ptr = head;
    while(ptr && ptr->next){
        int new = gcd(ptr->val, ptr->next->val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = new;
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }
    return head;
}
