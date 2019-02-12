
https://leetcode.com/problems/palindrome-number/

```
class Solution:
    def isPalindrome(self, x: 'int') -> 'bool':
        if x < 0:
            return False
        
        r = x % 10 #digit
        q = x // 10
        result = 0
        while(q > 0):
            result = result*10 + r
            r = q % 10
            q = q // 10
        result = result*10 + r
        return result == x
        



```
