


class Solution:
	
	def coinChange(self, coins, amount):
		"""
		:type coins: List[int]
		:type amount: int
		:rtype: int
		"""
		if amount < 0:
			return -1
		coins.sort()
		coins.reverse()
		re = [-1]
		self.foo(coins,amount,0,re)
		return re[0]


	def foo(self,coins,remain,count,min_count):

		# this is base case
		if len(coins) == 1:
			# if reminder is not 0
			if not remain%coins[0]:
				# here calcuate coin's count and check if it is min count 
				temp_count = count+remain//coins[0] 
				if temp_count >= 0:
					if temp_count < min_count[0] or min_count[0]<0:
						min_count[0] = temp_count	
			return None		

		# set max num of coins[0] we can use,
		# and set the remain if we use max num of coins[0]
		max_num = remain//coins[0]
		remain = remain % coins[0]

		for i in range(max_num+1):
			# change number of coins[0] used and its corresponding reminder
			temp_remain = remain + i*coins[0]
			temp_count = (max_num-i)+count

			# if temp_count so far bigger than min_count we find, we PRUNE this case
			if temp_count >= min_count[0] and min_count[0]>0:
				return None

			# else recursively call self, to figure out next coin's usage situation
			self.foo(coins[1:],temp_remain,temp_count,min_count)
		return None


if __name__ == '__main__':
	mysolution = Solution()
	re2 = mysolution.coinChange([58,92,387,421,194,208,231],7798)
	print(re2)