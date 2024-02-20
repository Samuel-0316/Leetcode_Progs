/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode *curr = head;
    while(curr->next != NULL){
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}