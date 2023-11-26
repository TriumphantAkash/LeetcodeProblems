/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = NULL, *next=NULL;
    if(head == NULL || head->next == NULL)
    {return head;}

    //2 nodes only
    if(head->next->next == NULL)
    {
      next = head->next;
      next->next = head;
      head->next = NULL;
      return next;
    }

    //3 or more nodes
    prev = head;
    cur = head->next;
    next = cur->next;
    while(cur->next != NULL)
    {
      next = cur->next;
      cur->next = prev;

      //for next iteration
      prev = cur;
      cur = next;
      next = next->next;
    }
    cur->next = prev;
    head->next = NULL;
    return cur;
}