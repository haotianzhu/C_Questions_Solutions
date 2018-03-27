class Solution(object):
	def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""

		# stack dtype: list, 
		# for each left_bracket by order, satck contains its corresponding right_bracket
		stack = [] 
		left_bracket = ["{","[","("]
		right_bracket = ["}","]",")"]
		convert_dict = {"{":"}","[":"]","(":")"} # a dict helps to convert left bracket to right bracket

		for e in s:
			if e in left_bracket:
				stack.append(convert_dict[e])
			if e in right_bracket:
				if len(stack) > 0 and e == stack[-1]: # when char is a right bracket, stack'length should be bigger than 1 
					stack.pop() # if left bracket and right bracket match, pop stack
				else:
					return False

		if len(stack) == 0: # if stack is empty, all left_bracket found their right brackert
			return True
		else:
			return False



if __name__ == '__main__':

	re = Solution().isValid("[")
	print(re)