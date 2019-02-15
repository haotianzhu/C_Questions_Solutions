
https://leetcode.com/problems/3sum-closest/


```

class Solution:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        length = len(nums)

        nums.sort()
        g_min_d = [None,None]

        for i in range(length-2):
            left = i+1
            right = length-1
            min_d = [None,None]
            last = 1
            while(left<right):
                d = abs(nums[left] + nums[right] + nums[i] -target)
                if min_d[0] is None:
                    min_d[0] = d
                    min_d[1] = nums[left] + nums[right] + nums[i]
                
                    if nums[left] + nums[right] + nums[i] > target:
                        last = -1
                        right -=1
                    else:
                        last = +1
                        left += 1
                elif d <= min_d[0]:
                    min_d[0] = d
                    min_d[1] = nums[left] + nums[right] + nums[i]
                    if nums[left] + nums[right] + nums[i] > target:
                        last = -1
                        right -=1
                    else:
                        last = +1
                        left += 1
                else:
                    if nums[left] + nums[right] + nums[i] > target and last == 1:
                        last = -1
                        right -=1
                    elif nums[left] + nums[right] + nums[i] <= target and last == -1:
                        last = +1
                        left += 1 
                    else:
                        break
                    
                    
            if g_min_d[0] is None or g_min_d[0] > min_d[0]:
                g_min_d[0] = min_d[0]
                g_min_d[1] = min_d[1]

        return g_min_d[1]
                    
                    
            
            
                
                
            
        
        


```
