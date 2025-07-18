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
    struct ListNode* next = head->next;
    while(ptr->next){
        int new = gcd(ptr->val, next->val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* temp = ptr->next;
        ptr->next = newNode;
        newNode->val = new;
        newNode->next = next;
        ptr = temp;
        next = ptr->next;
    }
    return head;
}
