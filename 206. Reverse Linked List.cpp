class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* temp = NULL;
        
        while(current != NULL){
            
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        
        return prev;
        
    }
};
