

https://leetcode.com/problems/sudoku-solver/

**Naive recurisve dsf solution**

use for-loop to reduce running time (forEach, some, are slower than for-loop)

```javascript
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function (board) {
  updateOneTile(board, 0, 0) // dfs and update
};



/**
 *
 * @param {string[][]} board
 * @param {int} row
 * @param {int} col
 * @param {string} value
 * @returns {boolean}
 */
const validation = (board, row, col, value) => {
  for (let i = 0; i < 9; i++) {
    const m = 3 * Math.floor(row / 3) + Math.floor(i / 3);
    const n = 3 * Math.floor(col / 3) + i % 3;
    if (board[i][col] === value || board[row][i] === value || board[m][n] === value) {
      return false;
    }
  }
  return true;
}

/**
 *
 * @param {int} row
 * @param {int} col
 * @returns {[int, int]}
 */
const nextStep = (row, col) => {
  if (col === 8) {
    return [row + 1, 0]
  } else {
    return [row, col + 1]
  }
}


/**
 *
 * @param {string[][]} board
 * @param {int} row
 * @param {int} col
 * @param {string} value
 * @returns {boolean}
 */
const updateOneTile = (board, row, col) => {
  // base
  if (row === 9) {
    // done and solved
    return true
  }

  // if empty tile
  if (board[row][col] === '.') {
    // each value, fill it in current tile and go deeper
    for (let i = 1; i < 10; i++) {
      let value = '' + i
      if (validation(board, row, col, value)) { // value is okay
        board[row][col] = value
        const next = nextStep(row, col)
        if (updateOneTile(board, next[0], next[1])) {
          return true
        }
      }
    }
    board[row][col] = '.'
    return false
  } else {
    // solve next tile
    const next = nextStep(row, col)
    return updateOneTile(board, next[0], next[1])
  }
}

```

