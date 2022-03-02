Given the head, return the middle node. 
  E.g. : 1->2->3->4->5  => 3
    
    Approach 1 : Traverse the list and find number of nodes and return mid.
    Approach 2 : Use 2 pointers -> slow (moves by 1)    
                                   fast (moves by 2)    
      By the time fast reaches the end , slow reaches the mid.
      
  // APPROACH 1 (naive ): Code 
      class Solution {
public:
	ListNode* middleNode(ListNode* head) 
  {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) 
      {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};

// APPROACH 2 (optimal ): Code 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
