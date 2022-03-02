Given a linked list, return reversed list.
E.g. : 1->2->3->4   =>  4->3->2->1

// We can do it by reversing all the links and make the next pointer point to the previous node.

//ITERATIVE APPROACH : 
We will use 3 variables: prevNode, head, and nextNode.
prevNode to NULL
nextNode can stay empty;
Then we will continue our loop until our current maidenhead pointer is truthy (ie: not NULL), which implies that we reached the end of the linked list
During our loop, we first of all update nextNode so that it acquires its namesake value, as head->next.
Finally, we update the head with the value we stored in nextNode.
And finally, we go on with the loop until we can. After the loop, we return prevNode.

Code : ListNode* reverseList(ListNode* head) 
{
        ListNode *prev = NULL, *cur=head, *tmp;
        while(cur)
        {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
   }

//RECURSIVE APPROACH : 
The recursive approach to reverse a linked list is simple, just we have to divide the linked lists in two parts and i.e first node and the rest of the linked list,
and then call the recursion for the other part by maintaining the connection.
  
Code : ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
