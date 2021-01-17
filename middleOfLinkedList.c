struct ListNode* middleNode(struct ListNode* head){
    
    struct ListNode *ptr = head;
    int count = 0;
    int nodeIs = 0;
    
    while(ptr -> next != NULL) {
        
        count++;
        ptr = ptr -> next;
    }
    
    if (count % 2 == 0) {
        
        nodeIs = count / 2;
    }
    
    else {
        
        nodeIs = count / 2 + 1;
    }
    
    ptr = head;
    count = 0;
    while(count != nodeIs) {
        
        count++;
        ptr = ptr -> next;
    }
    
    return ptr;
}
