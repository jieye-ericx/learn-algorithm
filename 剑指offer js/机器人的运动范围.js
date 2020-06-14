/**
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
 * 每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格（35,37），
 * 因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
 * 因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * 
 * 按照我的思路 ，常规dfs，但是vis运行后不需要重新赋值为0
 */
console.log(movingCount(5, 60, 60))
function forwardCell(k, x, y) {
  let xysum = getDigitSum(x) + getDigitSum(y)
  // console.log('x:' + x + ' y:' + y + ' ' + xysum)
  if (xysum > k) {
    // console.log('x:' + x + ' y:' + y + ' out')
    return
  }
  this.cells++
  
  let newx, newy
  for (let i = 0; i < 4; i++) {
    ;(newx = x + this.directs[i][0]), (newy = y + this.directs[i][1])
    if (newx >= this.rows || newy >= this.cols || newx < 0 || newy < 0) {
      continue
    }
    if (this.vis[newx][newy] === 1) {
      // console.log(newx + '  ' + newy + 'vis===1')
      continue
    }
    this.vis[newx][newy] = 1
    // console.log(newx + '  ' + newy + '复制唯一')
    forwardCell(k, newx, newy)
    // this.vis[newx][newy] = 0
    // console.log(newx + '  ' + newy + '复制唯0')
  }
}

function getDigitSum(num) {
  let sum = new Number(0)
  while (num > 0) {
    sum += (num % 10)
    num = Math.floor(num / 10)
  }
  return sum
}

function movingCount(threshold, rows, cols) {
  // write code here
  this.directs = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ]
  // this.vis = new Array(rows).fill(new Array(cols).fill(0))
  this.vis = new Array(rows)
  for (let index = 0; index < this.vis.length; index++) {
    this.vis[index] = new Array(cols).fill(0)
  }
  this.cells = 0
  this.rows = rows
  this.cols = cols
  this.vis[0][0]=1
  forwardCell.apply(this, [threshold, 0, 0])
  return this.cells
}
