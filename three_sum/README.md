question from leetcode







```python
'''
how to use map() in python3 
source from https://python-course.eu/python3_lambda.php
'''

'''
example 1
'''
>>> a = [1,2,3,4]
>>> b = [17,12,11,10]
>>> c = [-1,-4,5,9]
>>> list(map(lambda x,y:x+y, a,b))
[18, 14, 14, 14]
>>> list(map(lambda x,y,z:x+y+z, a,b,c))
[17, 10, 19, 23]
>>> list(map(lambda x,y,z : 2.5*x + 2*y - z, a,b,c))
[37.5, 33.0, 24.5, 21.0]
>>> 


'''
example 2
'''
>>> C = [39.2, 36.5, 37.3, 38, 37.8] 
>>> F = list(map(lambda x: (float(9)/5)*x + 32, C))
>>> print(F)
[102.56, 97.7, 99.14, 100.4, 100.03999999999999]
>>> C = list(map(lambda x: (float(5)/9)*(x-32), F))
>>> print(C)
[39.2, 36.5, 37.300000000000004, 38.00000000000001, 37.8]
>>> 




```



```python
class Solution(object):
	def threeSum(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[List[int]]
		"""
		
        # sort nums by DESC
        # re is a set containing result tuples
        # last_remain tracks if current nums[pivot] is same as nums[last pivot]
		nums.sort()
		re = set()
		last_remain = None
        
        # for each pivot(index) of nums
		for pivot in range(len(nums)):
			
            # left is pivot plus one and right always be the last index
			left = pivot+1
			right = len(nums)-1
			
            # remain is the number (1 - sum of nums[left]+nums[right])
			remain = 0 - nums[pivot]
            
            # if nums[pivot] is same as nums[last pivot], pass
            # else update last_remain
			if last_remain == remain:
				continue
			else:
				last_remain = remain
                
			# last_left_v is nums[last left]
            # last_right_v is nums[last right]
			last_left_v = None
			last_right_v = None
            

            #if left < right, we have not retrieved nums[pivot+1:] 
			while(left < right):

                # if sum(num[pivot],num[left],sum[right]) is 0 and tuple(num[pivot],num[left],sum[right]) is differ than last tuple
                # we add it into result set (re)
				if nums[left]+ nums[right] == remain and last_left_v != nums [left] and last_right_v != nums[right]:
					last_left_v = nums[left]
					last_right_v = nums[right]
					re.add((nums[pivot],last_left_v,last_right_v))
				elif nums[left]+ nums[right] > remain:	# else if sum(num[left],sum[right]) too large (the nums sorted at begin)
					right -= 1
				else:	# other cases move left right by 1
					left += 1

        # convert type set(tuples()) into type list[list[]] or list[tuples()]          
		return list(map(list,re)) # same as list(re)

```

