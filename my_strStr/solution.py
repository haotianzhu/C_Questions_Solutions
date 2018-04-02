class Solution:
	def strStr(self, haystack, needle):
		"""
		:type haystack: str
		:type needle: str
		:rtype: int
		"""

		# get size of 
		size = len(haystack)
		find_size = len(needle)

		# if size of needle is 0 then return 0
		if not find_size:
			return 0

		# if haystack size is 0 or size of haystack is larger than that in needle, return -1
		if not size or size < find_size:
			return -1

		# get fist char in needle
		head = needle[0]
		for i in range(size):
			element = haystack[i]
			if element == head and haystack[i:i+find_size] == needle:
				return i

		return -1




class Solution2:
	def strStr(self, haystack, needle):
		"""
		:type haystack: str
		:type needle: str
		:rtype: int
		"""
		return haystack.find(needle)





if __name__ == '__main__':
	re = Solution().strStr("hello","ll")
	print(re)
	re = Solution2().strStr("heao","ll")
	print(re)