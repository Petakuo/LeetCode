/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool have[100001] = {0};
    for(int i = 0; i < numsSize; i++){
        have[nums[i]] = 1;
    }
    while(have[head->val]){
        head = head->next;
    }
    struct ListNode* ptr = head;
    struct ListNode* prev = head;
    while(ptr){
        if(have[ptr->val]){
            prev->next = ptr->next;
            ptr = ptr->next;
        }
        else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}
