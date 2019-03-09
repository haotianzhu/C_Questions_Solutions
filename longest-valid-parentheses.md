https://leetcode.com/problems/longest-valid-parentheses/


```

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # stack
        stack = [0]
        longest = 0
        for i,e in enumerate(s):
            if e == '(':
                stack.append(0)
            else:
                if len(stack) >= 2:
                    stack[-2] += stack[-1]+2
                    longest = max(longest, stack[-2])
                    del stack[-1]
                else:
                    stack = [0]
        return longest



class Solution:
    def longestValidParentheses(self, s: str) -> int:
        def foo(s, left_traget, inverse):
            left_num = 0
            i = 0
            longest = 0
            tmp_longest = 0
            while(i < len(s)):
                if inverse:
                    e = s[-(i+1)]
                else:
                    e = s[i]
                if e == left_traget:
                    left_num += 1
                else:
                    left_num -= 1
                    if left_num > 0:
                        tmp_longest += 2
                    elif left_num==0:
                        tmp_longest += 2
                        if longest < tmp_longest:
                            longest = tmp_longest
                    else:
                        # left_num < 0
                        if longest < tmp_longest:
                            longest = tmp_longest
                        left_num = 0
                        tmp_longest = 0
                i += 1

            return longest
        return max(foo(s,'(',False), foo(s,')',True))
                               
```
