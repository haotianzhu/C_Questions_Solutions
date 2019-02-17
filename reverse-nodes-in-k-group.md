https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/

```

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: 'ListNode', k: 'int') -> 'ListNode':
        def get_item_by_pos(pos,current):
            i = 0
            while(i<pos and current):
                current = current.next
                i += 1

            return current
        
        def update(k,root):
            # base case
            if k == 1:
                
                return root, root
            elif k== 2:
                h = root
                t = root.next
                h.next = t.next
                t.next = h
                
                return t, h
            else:
                # recursive
                s_h, s_t = update(k-2, root.next)
                t = s_t.next
                h = root
                h.next = t.next
                t.next = s_h
                s_t.next = h
                
                return t, h

        if get_item_by_pos(k-1,head):
            # handle first group
            head, tail = update(k,head)
            previous = tail
            current = previous.next
            
            while(current and get_item_by_pos(k-1,current)):
                h, tail = update(k,current)
                previous.next = h
                previous = tail
                current = previous.next

        return head

                
            
            

                

```
