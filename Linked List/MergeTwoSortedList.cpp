E.g. : List1: 10->15->17->20 ; List2: 5->9->13->19   => Result: 5->9->10->13->15->17->19->20
  
  
  CODE : class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        ListNode dummy{0};
        auto curr = &dummy;

        while (l1 && l2) 
        {
            if (l1->val <= l2->val) 
            {
                curr->next = l1;
                l1 = l1->next;
            } else 
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
