class Solution(object):
	def longestCommonPrefix(self, strs):
		"""
		:type strs: List[str]
		:rtype: str
		"""

		index = 0
		target = ""

		if not strs:
			return ""

		while(index < len(strs[0])):
			for each_string in strs:
				if index >= len(each_string):
					return each_string[:index]
				if target == "":
					target = each_string[index]
				else:
					if each_string[index] != target:
						return each_string[:index]
			index += 1
			target = ""

		return strs[0][:index]


if __name__ == '__main__':
	my_solution = Solution()
	re = my_solution.longestCommonPrefix(["aaaa","a"])
	print(re)