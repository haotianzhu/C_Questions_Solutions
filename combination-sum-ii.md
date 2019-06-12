https://leetcode.com/problems/combination-sum-ii/



```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  // sort candidates
  var results = []
  const copyArray = candidates.sort((x1, x2) => x1 - x2)
  dfs(copyArray, target,[],results)
  // convert to string and store them into a Set 
  let set = new Set(results.map(JSON.stringify));
  return Array.from(set).map(JSON.parse);   // distinct array of arrays
};

/**
 * @param {number[]} array
 * @param {number} remain
 * @param {number[]} prefix
 * @param {number[][]} results
 */
const dfs = (array, remain, prefix, results) => {

  for (let i = 0; i < array.length; i++) {
    let newRemain = remain - array[i]
    if (newRemain > 0) {
      dfs(array.slice(i + 1), newRemain, [...prefix, array[i]], results)
    } else if (newRemain == 0) {
      results.push([...prefix, array[i]])
    } else {
      // done
      return
    }
  }
}
```
