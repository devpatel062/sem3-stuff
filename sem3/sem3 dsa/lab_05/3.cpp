// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    while(head != NULL)
    {
        if(head->data == 0)
            return true;
        
        head->data = 0;
        head = head->next;
    }
    return false;

}