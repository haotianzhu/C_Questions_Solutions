question comes from leetcode



```

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

```



solution 

```python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


import heapq
import operator


def my_lt (self, other):
	'''
	create my own lt function
	'''
	return operator.lt(self.val, other.val)

class Solution:
	def mergeKLists(self, lists):
		"""
		:type lists: List[ListNode]
		:rtype: ListNode
		"""

		ListNode.__lt__ = my_lt # let ListNode cmp function to be my_lt

		# create head node and let current be head
		head = ListNode(None)
		current = head

		# q is heapq list
		q = []

		# push all nodes into q 
		for anode in lists:
			node = anode
			while(node):
				heapq.heappush(q,node)
				node = node.next
		
		# pop min val's node, and assign current's next to it
		while(q):
			current.next = heapq.heappop(q)
			current = current.next

		current.next = None

		return head.next

```

