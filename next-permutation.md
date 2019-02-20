
https://leetcode.com/problems/next-permutation


```


class Solution:
    def nextPermutation(self, nums: 'List[int]') -> 'None':
        """
        Do not return anything, modify nums in-place instead.
        """
        last = nums[-1]
        i = len(nums)-2
        while(i >= 0):
            # nums[-2] to nums[0]
            if nums[i] >= last:
                last = nums[i]
                i-=1
            else:
                break
        
        if i < 0:
            nums.sort()
            return
        
        # sort nums[i] to nums[-1]
        # find bigger nums
        result = None
        for index, x in enumerate(nums[i+1:]):
            if x > nums[i]:
                if result is None :
                    result = index+i+1
                elif x < nums[result]:
                    result = index+i+1

        tmp = nums[result]
        nums[result] = nums[i]
        nums[i] = tmp


        nums[i+1:] = sorted(nums[i+1:])

        return 
            






```
