//Refer bhaicodekaro YT Explanation
//youtube.com/watch?v=FpTFQPHW5r4 

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		//To handle case of starting itself repeat - we req dummy
		//Eg. 1->1->1->2->2
       
        ListNode* dummy = new ListNode();
		dummy->next = head;

		//Current pointer traversal
		ListNode* cur = head;

		//Prev to dummy node
		ListNode* prev = dummy;

		while (cur)
		{
			while (cur->next && cur->val == cur->next->val)
				cur = cur->next;

			//Now cur points to last repeat occurence

			//If prev and cur are same ie; no repeat was found
			//Then Increment prev
			if (prev->next == cur)
				prev = prev->next;
			else
				prev->next = cur->next;

			cur = cur->next;
		}
        
		//VVI = return dummy next
        
		//Since trivial case when all empty
        //ie; 1->1->1->1
        
		return dummy->next;
	}
};
