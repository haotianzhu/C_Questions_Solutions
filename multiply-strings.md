https://leetcode.com/problems/multiply-strings

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

var multiply = function (num1, num2) {
  // if 0 return 0
  if (num1 === '0' || num2 === '0') {
    return '0'
  }
  // a*b = c, max c's size = a's size + b's size
  var results = new Array(num1.length + num2.length).fill(0)
  
  // O(n*m), for each digit d1 in num1, for each digit d2 in num2
  var index = 0
  for (let i = 0; i < num1.length; i++) {
    let d1 = parseInt(num1[num1.length - i - 1])
    for (let j = 0; j < num2.length; j++) {
      let d2 = parseInt(num2[num2.length - j - 1])
      // find the index 
      index = results.length - i - j - 1
      // update
      results[index] = results[index] + d1 * d2
      results[index - 1] = results[index - 1] + Math.floor(results[index] / 10) 
      results[index] = results[index] % 10
    }
  }
  
  // first not 0 element's index 
  index = results[index-1]===0? index: index-1
  // results[index] may > 9
  return results.slice(index).join('')
};

```
