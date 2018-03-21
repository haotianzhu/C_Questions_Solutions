question is from leetcode

Write a function to find the longest common prefix string amongst an array of strings.





```python
'''
let index = 0
Loop:
for every string in string list	
	we check if len(string) is larger than index
	if no return
	else we get string's char vai string list [index]
	check char same or not
then index plus 1, and go back to Loop
'''
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

```

