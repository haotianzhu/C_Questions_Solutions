class Solution(object):
	def search(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: int
		"""
		if not nums:
			return -1

		lo = 0
		hi = len(nums)-1
		old_size = len(nums)

		# if not rotated
		if nums[lo] <= nums[hi]:
			return self.binary_search(nums,lo,hi+1,target)
		else:
			# extent list so that new list[lo:] is sorted
			while(nums[lo] > nums[hi]):	
				lo = hi
				hi -= 1
			nums += nums[:hi+1]

			# get result
			re = self.binary_search(nums,lo,len(nums),target)

			# if index large origin list size, return index-length of origin list
			return  re - old_size if re >= old_size else re


	def binary_search(self,array,low,high,target):
		'''
		low: dtype int, index of lowest int
		high: dtype int, index of highest int
		target: dtype int, the int we search for

		this function is a normal binary search function
		O(log(n))

		'''

		mid = low +(high - low) // 2

		mid_value = array[mid]

		if low+1 >= high:
			return -1 if mid_value != target else mid

		if mid_value == target :
			return mid
		elif target > mid_value:
			return  self.binary_search(array,mid,high,target)
		else:
			return self.binary_search(array,low,mid,target)



if __name__ == '__main__':
	re = Solution().search([4,5,6,1,2,3],4)
	print(re)
