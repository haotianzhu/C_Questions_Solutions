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





if __name__ == '__main__':
	my_solution = Solution()
	re = my_solution.threeSum([0,0,0])
	print(re)