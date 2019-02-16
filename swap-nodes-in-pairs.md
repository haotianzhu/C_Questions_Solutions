https://leetcode.com/problems/swap-nodes-in-pairs


```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: 'ListNode') -> 'ListNode':
        # 1->2->3->4
        current = head
        if head is None:
            return head

        if head.next is None:
            # only one
            return head
        
        # change first two
        current = head
        previous = head.next
        current.next = previous.next
        previous.next = current
        head = previous
        
        # reassign
        previous = current
        current = current.next
        
        while(current and current.next):
            next_node = current.next
            previous.next = next_node
            current.next = next_node.next
            next_node.next = current
            
            previous = current
            current = current.next
        return head
        



```
