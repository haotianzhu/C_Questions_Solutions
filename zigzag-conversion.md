https://leetcode.com/problems/zigzag-conversion/

```
class Solution:
    def convert(self, s: 'str', numRows: 'int') -> 'str':
        num_rows = numRows
        if num_rows == 1:
            return s
        
        length = len(s)
        big_col = 2*num_rows - 2 
        max_big_col =  math.ceil(length/big_col)
        result = ''
        for i in range(num_rows):
            if i == 0 or i == num_rows-1:
                # begin
                for j in range(max_big_col):
                    index = i+j*big_col
                    if index < length:
                        result += s[index]
            else:
                # middle 
                for j in  range(max_big_col+1):
                    if j == 0  :
                        index = i+j*big_col
                        if index < length:
                            result += s[index]
                    else:
                        index = i+j*big_col - 2*i
                        if index < length:
                            result += s[index]
                        index = i+j*big_col
                        if index < length:
                            result += s[index]
                            
        return result
```
