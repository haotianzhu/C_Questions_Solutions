class Solution1(object):
	def searchRange(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		if not nums:
			return [-1,-1]
		else:
			return self.binary_search(0,len(nums),nums,target)


	def binary_search(self,lo,hi,nums,target):

		if lo+1 >= hi:
			#base case 
			return [(nums[lo] == target)*(lo+1)-1]*2

		mid = lo + (hi-lo)//2 # avoid overflow

		if nums[mid] < target:
			# prune right and go right part
			return self.binary_search(mid,hi,nums,target)	
		elif nums[mid] > target:
			# prune right
			return self.binary_search(lo,mid,nums,target)	
		else:
			# current is taget, figure out most left and most right index
			right_re = max( self.binary_search(mid,hi,nums,target)[1], mid)
			left_re =  min( self.binary_search(lo,mid,nums,target)[0] , mid)

			if left_re <0: left_re = mid

			return [left_re,right_re]


class Solution2(object):
	def searchRange(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		if not nums:
			return [-1,-1]
		else:
			# find target-0.5 and target+0.5
			return [self.binary_search(0,len(nums),nums,target-0.5,1),self.binary_search(0,len(nums),nums,target+0.5,0)]


	def binary_search(self,lo,hi,nums,target,left):

		if lo+1 >= hi:
			#base case 
			hi = min(hi,len(nums)-1)

			# if we check left, then 
			if left:
				hi_re =(nums[hi] == int(target+left))*(hi+1)-1  
				lo_re = (nums[lo] == int(target+left))*(lo+1)-1 

				if lo_re == -1:
					return hi_re
				else:
					return lo_re
			else:
				return max((nums[hi] == int(target+left))*(hi+1)-1,  (nums[lo] == int(target+left))*(lo+1)-1 )

		mid = lo + (hi-lo)//2 # avoid overflow

		if nums[mid] < target:
			# prune right and go right part
			return self.binary_search(mid,hi,nums,target,left)

		if nums[mid] > target:
			# prune right
			return self.binary_search(lo,mid,nums,target,left)	

		return


		



if __name__ == '__main__':
	re1 = Solution1().searchRange([5, 7, 7, 8, 8, 10],8)
	re2 = Solution2().searchRange([8,8],8)
	print(re1,re2)