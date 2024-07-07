
循环检测

public boolean hasCycle(ListNode head) {
    if (head == null || head.next == null) {
        return false;
    }
    ListNode slow = head;
    ListNode fast = head.next;
    while (slow != fast) {
        if (fast == null || fast.next == null) {
            return false;
        }
        slow = slow.next;
        fast = fast.next.next;
    }
    return true;
}

=============================================================================================================

2(a+b) = a+b+n*(b+c)   
=>   a = (n-1)(b+c) + c
=>   a = c

ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    
    ListNode* firstp = head;
    ListNode* secondp = head;
    bool isCycle = false;
    
    while(firstp != NULL && secondp != NULL) {
        firstp = firstp->next;
        if (secondp->next == NULL) return NULL;
        secondp = secondp->next->next;
        if (firstp == secondp) { isCycle = true; break; }
    }
    
    if(!isCycle) return NULL;
    firstp = head;
    while( firstp != secondp) {
        firstp = firstp->next;
        secondp = secondp->next;
    }

    return firstp;
}
