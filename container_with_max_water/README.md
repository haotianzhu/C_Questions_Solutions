

Question:

![question](./question.jpg)




```python
class Solution(object):
	def maxArea(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		max_area = 0
		i = 0
		j = len(height)-1

		while(i < j):
			a1 = height[i]
			a2 = height[j]
			max_area = max(min(a1,a2)*(j-i), max_area )

			if a1 < a2:
				i+=1

			else :
				j-=1

		return max_area
```

