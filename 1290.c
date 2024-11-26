/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    if(!head || !head->next) return head->val;
    int ans = 0;
    while(head){
        ans <<= 1;
        ans += head->val;
        head = head->next;
    }
    return ans;
}