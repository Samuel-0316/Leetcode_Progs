/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Initialize a dummy node to handle cases where the head needs to be removed
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* prev = dummy;
    struct ListNode* current = head;
    
    while (current != NULL) {
        if (current->val == val) {
            // Remove the current node
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            // Move to the next node
            prev = current;
            current = current->next;
        }
    }
    head = dummy->next;
    free(dummy); // Free the dummy node
    
    return head;   
}