
https://leetcode.com/problems/4sum/

```

class Solution:
    def fourSum(self, nums: 'List[int]', target: 'int') -> 'List[List[int]]':
        
        nums.sort()
        size = len(nums)
        result = []
        last_i = None
        for i in range(size):
            if last_i is not None and nums[last_i] == nums[i]:
                continue
            last_i = i
            last_j = None
            for j in range(i+1,size):
                if last_j is not None and nums[last_j] == nums[j]:
                    continue
                last_j = j
                new_target = target-nums[i]-nums[j]
                
                left = j+1
                right = size-1
                last = 1
                is_pass = False 
                while(left<right):
                    s = nums[left] + nums[right]               
                    if s < new_target:
                        # left move
                        left += 1
                        last = 1
                        is_pass = False
                    elif s > new_target:
                        # right move
                        right -= 1
                        last = -1
                        is_pass = False
                    else:
                        # equal
                        if not is_pass:
                            result.append([nums[i],nums[j],nums[left],nums[right]])
                            is_pass = True

                        if last == 1:
                            left += 1
                        elif last== -1:
                            right -= 1
                                
        return result
                        
                            


```
