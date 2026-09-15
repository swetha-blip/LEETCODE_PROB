/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* node=NULL;
    struct ListNode*temp;
    while (head != NULL) {
        temp=head->next;
        head->next=node;
        node=head;
        head=temp; 
                  
    } 
    return node; 
}