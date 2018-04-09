
class Solution1:
	def countAndSay(self, n):
		"""
		:type n: int
		:rtype: str
		"""

		# base case n = 1 and return "1"
		if n == 1:
			return "1"
		else:
			# get result string from next level
			string = self.countAndSay(n-1)+" "
			# last check last char visited in string, let last = string's first char
			last = string[0]
			# result is the return string 
			result = ""
			# count is the count of sequence last, since the first char alway == last, we set count as 0
			count = 0
			for s in string:
				if s == last: # if new char == last char, count of last +=1
					count+=1
				else: # if a sequence of last char done, add count and last to result
					result+=str(count)+last 
					count = 1 # set last to new char, count= 1
					last = s
			return result


import re
class Solution2:
	'''
		this solution comes from leetcode user StefanPochmann, I add some comments to his method
	'''
	def countAndSay(self, n):
		s = '1' # base case n=1, result is "1"
		for _ in range(n - 1): # since we already done base case, we total need n-1 iterations 
			# re.sub(pattern, repl, string, count=0, flags=0)
			# r'(.)\1*' (.) finds any char and \1* tries to match the same char until fails
			# group(0) is whole entire match, group(1) is the value of first paranthesized subgroup which is (.)
			s = re.sub(r'(.)\1*', lambda m: str(len(m.group(0))) + m.group(1), s) # replace every match by str(len(m.group(0))) + m.group(1)
		return s

if __name__ == '__main__':
	res = Solution1().countAndSay(5)
	print(res)
	res = Solution2().countAndSay(5)
	print(res)


