https://leetcode.com/problems/combination-sum

```

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        solutions = []
        candidates.sort()
        def foo(index, remain, solution):    
            if index >= len(candidates):
                # base
                return None
            num = candidates[index]
            k = remain//num
            if k == 0:
                # candidates[index] < candidates[index+1]
                # remain < candidates[index]
                # prune
                return
            for i in range(k,-1,-1):
                r = remain - i*num
                if r == 0:
                    solutions.append(solution+[num]*i)
                else:
                    foo(index+1, r, solution+[num]*i )
        
        foo(0, target, [])
        return solutions

```
