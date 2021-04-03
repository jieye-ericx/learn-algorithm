/**
 * 题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
   矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
示例1
输入
"ABCESFCSADEE",3,4,"ABCCED"
返回值
true
示例2
输入
"ABCESFCSADEE",3,4,"ABCB"
返回值
false
 * @param {*} matrix 
 * @param {*} rows 
 * @param {*} cols 
 * @param {*} path 
 */

function hasPath(matrix, rows, cols, path) {
    let arr = [], vis = []
    for (let i = 0; i < rows; i++) {
        arr.push(new Array(cols))
        vis.push(new Array(cols).fill(0))
        for (let j = 0; j < cols; j++) {
            arr[i][j] = matrix[i * cols + j]
        }
    }
    let flag = false
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            vis[i][j] = 1
            if (dfs(0, i, j, arr, rows, cols, path, vis) === true) flag = true
            vis[i][j] = 0
        }
    }
    return flag
}
function dfs(len, x, y, arr, rows, cols, path, vis) {

    if (arr[x][y] !== path[len]) return false
    if (len === path.length - 1) {
        // console.log(111111);
        return true
    }
    let directs = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ]
    let flag = false
    for (let i = 0; i < 4; i++) {
        let newx = x + directs[i][0], newy = y + directs[i][1]
        if (newx < 0 || newy < 0 || newx >= rows || newy >= cols) continue
        if (vis[newx][newy] === 1) continue
        vis[newx][newy] = 1
        if (dfs(len + 1, newx, newy, arr, rows, cols, path, vis) === true) flag = true
        vis[newx][newy] = 0
    }
    return flag
}
console.log(hasPath("ABCESFCSADEE", 3, 4, "ABCCED"))
console.log(hasPath("ABCESFCSADEE", 3, 4, "ABCB"))