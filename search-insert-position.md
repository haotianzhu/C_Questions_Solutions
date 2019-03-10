https://leetcode.com/problems/search-insert-position/


```

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        l = 0
        r = len(nums)
        
        while(r-l>1):
            middle = (l+r)//2
            print(l,middle,r)
            if nums[middle] < target:
                l = middle
            elif nums[middle] > target:
                r = middle
            else:
                return middle
        if nums[l] >= target:
            return l
        else:
            return r

```
