https://leetcode.com/problems/remove-element/submissions/

```

class Solution:
    def removeElement(self, nums: 'List[int]', val: 'int') -> 'int':
        a_list = [ num for num in nums if num != val]
        for i in range(len(a_list)):
            nums[i] = a_list[i]
        return len(a_list)
                
                
```
