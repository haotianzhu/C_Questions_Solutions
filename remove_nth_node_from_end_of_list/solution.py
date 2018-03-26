# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
	def removeNthFromEnd(self, head, n):
		"""
		:type head: ListNode
		:type n: int
		:rtype: ListNode
		"""

		# tracks of lleft -> left -> ..... -> right 
		# where the distance of left and right is n nodes
		# when right touch base, which means right is None
		# we need to remove left
		# so only thing we need is to connect lleft and left.nxet 
		left = head
		right = head
		lleft = ListNode(None)
		lleft.next = left

		for i in range(n):
			right = right.next

		# consider special cases our root node is removed
		# we directly return left.next
		if not right:
			return left.next


		while(right):
			lleft = lleft.next
			right = right.next
			left = left.next

		# remove left
		lleft.next = left.next

		return head





if __name__ == '__main__':

	a1  = ListNode(1)
	a2  = ListNode(2)
	a3  = ListNode(3)
	a4  = ListNode(4)
	a5  = ListNode(5)
	
	a1.next = a2
	a2.next = a3
	a3.next = a4
	a4.next = a5
	a5.next = None



	my_solution = Solution()
	re = my_solution.removeNthFromEnd(a1,3)
	while(re):
		print(re.val)
		re = re.next



