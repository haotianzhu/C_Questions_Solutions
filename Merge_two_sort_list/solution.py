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
	def mergeTwoLists(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		
		# let left = l1 and right = l2	
		left = l1
		right = l2

		# create a head and let current = head
		head = ListNode(None)
		current = head

		# while left and right are not null 
		while(left and right):
			if left.val >= right.val: # if left value > right value, then connect right to current
				current.next = right  
				current = current.next # move current
				right = right.next  # move right
			else:
				current.next = left 
				current = current.next
				left = left.next

		# either left or right is null, connect not null one to current 
		if not left: 
			current.next = right
		else:
			current.next = left

		# return head's next => l1 or l2
		return head.next


if __name__ == '__main__':
	
	a1 = ListNode(1)
	a2 = ListNode(2)
	a3 = ListNode(4)

	b1 = ListNode(1)
	b2 = ListNode(3)
	b3 = ListNode(4)

	a1.next = a2
	a2.next = a3

	b1.next = b2
	b2.next = b3


	re = Solution().mergeTwoLists(a1,b1)
	while(re):
		print(re.val)
		re = re.next












		