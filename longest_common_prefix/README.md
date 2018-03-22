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

		# index is the index of strs where we have retrieved so far
		index = 0
		target = ""

		# if strs is "" or None, return "" 
		if not strs:
			return ""

		# consider the first string's length in strs
		# index must be less than it
		while(index < len(strs[0])):

			# for each string in strs, we need to compare each string [index] 
			# if they all same, index += 1
			# else we found the longest common prefix
			for each_string in strs:
				if index >= len(each_string):	# consider case len(strs[0]) large than some other strings in strs
					return each_string[:index]
				if target == "":	# when target is "" means we have retrieved all strings for last index
					target = each_string[index]
				else:	#check if char is same as last one
					if each_string[index] != target:
						return each_string[:index]
			# we have retrieved all strings for last index
			# reset target as "" and index += 1
			index += 1
			target = ""
		
		return strs[0][:index]

```

