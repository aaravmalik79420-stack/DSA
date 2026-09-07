struct ListNode* deleteMiddle(struct ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode* prevSlow = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prevSlow->next = slow->next;

    free(slow);

    return head;
}