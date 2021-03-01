/**
 * 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。
 * 地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，
 * 他必须穿过地下城并通过对抗恶魔来拯救公主。
骑士的初始健康点数为一个正整数。
如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数
（若房间里的值为负整数，则表示骑士将损失健康点数）；
其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球
（若房间里的值为正整数，则表示骑士将增加健康点数）。
为了尽快到达公主，骑士决定每次只向右或向下移动一步。

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，
则骑士的初始健康点数至少为 7。

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
说明:
骑士的健康点数没有上限。

任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
 */
/**
 * 此方法为我写的dfs模拟法，应该基本没问题，但是会超时
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function (dungeon) {
    let M = dungeon.length
    if (M === 0)
        return 0
    let N = dungeon[0].length,
        ans = Infinity,
        tmpAns = 0,
        dir = [[0, 1], [1, 0]],
        reduce = [Infinity],
        zans = -Infinity,
        dfs = (x, y) => {
            if (x < 0 || y < 0 || x >= M || y >= N || zans === 1) {
                return
            }

            // console.log('x ' + x + ' y ' + y + ' cost' + tmpAns);
            if (x === M - 1 && y === N - 1) {
                tmpAns += dungeon[x][y]
                reduce.push(Math.min(tmpAns, reduce[reduce.length - 1]))
                if (1 - reduce[reduce.length - 1] <= 0) {
                    zans = 1
                    ans = 1
                    // console.log(111);
                } else {
                    ans = Math.min(ans, 1 - reduce[reduce.length - 1])
                }
                // console.log('ans ' + ans);
                // console.log('red ' + reduce[reduce.length - 1]);
                // console.log('reds ' + reduce);
                tmpAns -= dungeon[x][y]
                reduce.pop()
                return
            }
            if (1 - reduce[reduce.length - 1] >= ans) {
                return
            }
            // dir.forEach(ele => {
            //     dfs(x + ele[0], y + ele[1])
            // })
            for (let i = 0; i < dir.length; i++) {
                tmpAns += dungeon[x][y]
                reduce.push(Math.min(tmpAns, reduce[reduce.length - 1]))
                dfs(x + dir[i][0], y + dir[i][1])
                tmpAns -= dungeon[x][y]
                reduce.pop()
            }
        }
    dfs(0, 0)
    return ans
};

/**
 * 这里尝试dp
 * 假设dp[i][j]表示走到(i,j)位置时当前需要的最小初始生命值
 * 则dp[i][j]应该与dp[i-1][j]、dp[i][j-1]有关
 * 如果按照从左上往右下的顺序进行动态规划，对于每一条路径，
 * 我们需要同时记录两个值。第一个是「从出发点到当前点的路径和」，
 * 第二个是「从出发点到当前点所需的最小初始值」。
 * 白写了一个小时吧，这个正推也不行，突然发现如[[1,-3,3],[0,-2,0],[-3,-3,-3]]时
 * [2][2]也会影响[1][2]的选择，可能得倒推。
 * 为什么错误https://leetcode-cn.com/problems/dungeon-game/solution/di-xia-cheng-you-xi-by-leetcode-solution/
 * 官方题解也提到了
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function (dungeon) {
    let M = dungeon.length
    if (M === 0)
        return 0
    let N = dungeon[0].length, dp = Array(M).fill(0)
    dp.forEach((a, b, c) => { c[b] = Array(N).fill(0) })
    // console.log(dp);
    dp[0][0] = { oric: dungeon[0][0], nowhp: dungeon[0][0] }
    for (let i = 1; i < N; i++) {
        let nowVal = dungeon[0][i]
        if (nowVal >= 0) {
            dp[0][i] = {
                oric: dp[0][i - 1].oric,
                nowhp: dp[0][i - 1].nowhp + nowVal
            }
        } else {
            const newhp = dp[0][i - 1].nowhp + nowVal
            if (newhp < 0 && newhp < dp[0][i - 1].oric) {
                dp[0][i] = {
                    oric: newhp,
                    nowhp: newhp
                }
            } else {
                dp[0][i] = {
                    oric: dp[0][i - 1].oric,
                    nowhp: newhp
                }
            }
        }
    }
    for (let i = 1; i < M; i++) {
        nowVal = dungeon[i][0]
        if (nowVal >= 0) {
            dp[i][0] = {
                oric: dp[i - 1][0].oric,
                nowhp: dp[i - 1][0].nowhp + nowVal
            }
        } else {
            const newhp = dp[i - 1][0].nowhp + nowVal
            if (newhp < 0 && newhp < dp[i - 1][0].oric) {
                dp[i][0] = {
                    oric: newhp,
                    nowhp: newhp
                }
            } else {
                dp[i][0] = {
                    oric: dp[i][0].oric,
                    nowhp: newhp
                }
            }
        }
    }
    console.log('M' + M + ' N' + N);
    for (let i = 1; i < M; i++) {
        for (let j = 1; j < N; j++) {
            console.log('i ' + i + ' j ' + j);
            const upnewhp = dp[i - 1][j].nowhp + dungeon[i][j],
                leftnewhp = dp[i][j - 1].nowhp + dungeon[i][j]
            const upnewori = upnewhp > dp[i - 1][j].oric ? dp[i - 1][j].oric : upnewhp,
                leftnewori = leftnewhp > dp[i][j - 1].oric ? dp[i][j - 1].oric : leftnewhp
            if (upnewori === leftnewori)
                dp[i][j] = {
                    oric: upnewori,
                    nowhp: Math.max(upnewhp, leftnewhp)
                }
            else if (upnewori <= leftnewori) {
                if ()
                    dp[i][j] = {
                        oric: leftnewori,
                        nowhp: leftnewhp
                    }
            } else {
                dp[i][j] = {
                    oric: upnewori,
                    nowhp: upnewhp
                }
            }
        }
    }
    console.log(dp);
    // dp[0][i] = dungeon[0][i] + dp[0][i - 1]
    // console.log('M' + M + ' N' + N);
    let ans = dp[M - 1][N - 1].oric
    if (ans >= 0) return 1
    else {
        return 1 - ans
    }
};
// const a = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]
const a = [[1, -3, 3], [0, -2, 0], [-3, -3, -3]]

console.log(calculateMinimumHP(a))

/**
 * 因此，如果按照从左上往右下的顺序进行动态规划，
 * 我们无法直接确定到达 (1,2)(1,2) 的方案，因为有两个重要程度相同的参数同时影响后续的决策。
 * 也就是说，这样的动态规划是不满足「无后效性」的。
于是我们考虑从右下往左上进行动态规划。令 dp[i][j]dp[i][j] 表示从坐标 (i,j)(i,j)
到终点所需的最小初始值。换句话说，当我们到达坐标 (i,j)(i,j) 时，
如果此时我们的路径和不小于 dp[i][j]dp[i][j]，我们就能到达终点。
这样一来，我们就无需担心路径和的问题，只需要关注最小初始值。对于 dp[i][j]dp[i][j]，
我们只要关心 dp[i][j+1]dp[i][j+1] 和 dp[i+1][j]dp[i+1][j]
的最小值 \textit{minn}minn。
记当前格子的值为 dungeon(i,j)，那么在坐标 (i,j) 的初始值只要达到
 minn−dungeon(i,j) 即可。同时，初始值还必须大于等于 1。
 这样我们就可以得到状态转移方程：
dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])−dungeon(i,j),1)
最终答案即为 dp[0][0]。
边界条件为，当 i=n-1或者 j=m-1时，dp[i][j]
转移需要用到的 dp[i][j+1]和 dp[i+1][j]中有无效值，
因此代码实现中给无效值赋值为极大值。特别地，dp[n-1][m-1]
转移需要用到的 dp[n-1][m] 和 dp[n][m-1] 均为无效值，
因此我们给这两个值赋值为1。
 */