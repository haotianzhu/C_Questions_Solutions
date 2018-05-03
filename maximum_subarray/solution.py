class Solution:
	def maxSubArray(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""	

		if not nums:
			return 0


		# ASSUME NUMS: .....[MAX_SUM][NEG][CURRENT].....
		# TOTAL = MAX_SUM + NEG
		# first check max of total+current and current
		# if current bigger than total+current => we prune all element before current element
		#		=> ......[CURRENT/MAX_SUM]...
		# else: update total
		# find max of total and max_sum
		# if max_sum > total => current+neg < 0  => ....[MAX_SUM][NEG].....
		# if max_sum < total => current+neg > 0 => .....[MAX_SUM].... or ...[CURRENT/MAX_SUM]...
		max_sum = nums[0]
		total = nums[0]

		for current in nums[1:]:
			total = max(total+current,current)
			max_sum = max(total,max_sum)

		return max_sum





		

if __name__ == '__main__':
	res = Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
	print(res)