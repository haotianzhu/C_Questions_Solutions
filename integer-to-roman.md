https://leetcode.com/problems/integer-to-roman/


```

class Solution:
    def intToRoman(self, num: 'int') -> 'str':
        d = {
            1:'I',
            5:'V',
            10:'X',
            50:'L',
            100:'C',
            500:'D',
            1000:'M'
        }

        result = ''
        mod_nums = [1,10,100,1000]
        
        r = num
        for mod_num in mod_nums[::-1]:
            q = r//mod_num
            r = r%mod_num

            if q <= 3 :
                result += q*d[mod_num]
            elif q == 4 :
                result += d[mod_num]+ d[5*mod_num]
            elif q == 5:
                result += d[5*mod_num]
            elif q <= 8:
                result += d[5*mod_num]+ (q-5)*d[mod_num]
            elif q == 9:
                result += d[mod_num] + d[10*mod_num]
            else:
                continue
        return result
        
```
