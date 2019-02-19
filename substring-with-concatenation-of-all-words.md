
https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/

```

class Solution:
    def findSubstring(self, s: 'str', words: 'List[str]') -> 'List[int]':
        if len(s) == 0 or len(words)==0:
            return []
        len_words = len(words[0])
        window_size = len(words)*len_words
        result = []
        d = {}
        for word in words:
            count = d.get(word, 0)
            d[word] = count + 1
        
        tmp_d = {}
            
        begin = 0
        end = window_size+begin
        while(end <= len(s)):
            sub_s = s[begin:end]
            
            sub_begin = 0
            sub_end = sub_begin+len(words[0])
            keep = True
            for word in words:
                tmp_d[word] = 0
            
            while(sub_end <= len(sub_s) and keep):
                sub_s_word = sub_s[sub_begin:sub_end]
                counted = tmp_d.get(sub_s_word,None)
                
                if counted == None :
                    keep = False
                    continue 
                else:
                    counted += 1
                    tmp_d[sub_s_word] = counted
                    target = d.get(sub_s_word,None)
                
                    if counted > target:
                        keep = False
                        continue
                    # next word
                    sub_begin = sub_end
                    sub_end = sub_begin+len(words[0])
            if keep:
                result.append(begin)
            begin += 1
            end = window_size+begin
        return result
                
                    
                
                    
                    
                
            
            
            
            
                



```
