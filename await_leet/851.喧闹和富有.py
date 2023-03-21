#
# @lc app=leetcode.cn id=851 lang=python3
#
# [851] 喧闹和富有
#
# https://leetcode-cn.com/problems/loud-and-rich/description/
#
# algorithms
# Medium (49.01%)
# Likes:    137
# Dislikes: 0
# Total Accepted:    13.8K
# Total Submissions: 23.1K
# Testcase Example:  '[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]\n[3,2,5,4,6,1,7,0]'
#
# 有一组 n 个人作为实验对象，从 0 到 n - 1
# 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为 x 的人简称为 "person x "。
#
# 给你一个数组 richer ，其中 richer[i] = [ai, bi] 表示 person ai 比 person bi 更有钱。另给你一个整数数组
# quiet ，其中 quiet[i] 是 person i 的安静值。richer 中所给出的数据 逻辑自恰（也就是说，在 person x 比
# person y 更有钱的同时，不会出现 person y 比 person x 更有钱的情况 ）。
#
# 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是，在所有拥有的钱肯定不少于 person x
# 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
#
#
#
# 示例 1：
#
#
# 输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet =
# [3,2,5,4,6,1,7,0]
# 输出：[5,5,2,5,4,5,6,7]
# 解释：
# answer[0] = 5，
# person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0
# 有更多的钱。唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
# 但是目前还不清楚他是否比 person 0 更有钱。
# answer[7] = 7，
# 在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
# 最安静（有较低安静值 quiet[x]）的人是 person 7。
# 其他的答案也可以用类似的推理来解释。
#
#
# 示例 2：
#
#
# 输入：richer = [], quiet = [0]
# 输出：[0]
#
#
#
# 提示：
#
#
# n == quiet.length
# 1 <= n <= 500
# 0 <= quiet[i] < n
# quiet 的所有值 互不相同
# 0 <= richer.length <= n * (n - 1) / 2
# 0 <= ai, bi < n
# ai != bi
# richer 中的所有数对 互不相同
# 对 richer 的观察在逻辑上是一致的

from typing import List
# @lc code=start

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        relation = [[[], []] for i in range(n)]
        for [ai, bi] in richer:
            # person ai 比 person bi 更有钱
            relation[bi][1].append(ai)
            relation[ai][0].append(bi)
        for [ai, bi] in richer:
            self.ree(ai, bi, relation)
        a = []
        i = 0
        for bigarr in relation:
            ans = 0xffff
            ansP = 0xfff
            bigarr[1].append(i)
            i += 1
            for e in bigarr[1]:
                if ans > quiet[e]:
                    ans = quiet[e]
                    ansP = e
            a.append(ansP)
        # print(relation[15])
        # print(a)
        return a

    def ree(self, ai, bi, rela):
        # if ai == 7 or bi == 7 or ai == 15 or bi == 15:
        #     print(ai, bi, rela[bi][0], '==', rela[15])
        for e in rela[bi][0]:
            # if ai == 7 or bi == 7 or ai == 15 or bi == 15:
            #     print(e)
            if(ai in rela[e][1]):
                # if ai == 7 or bi == 7 or ai == 15 or bi == 15:
                #     print(ai, 'in rela[', e, '][1]')
                continue
            else:
                # if ai == 7 or bi == 7 or ai == 15 or bi == 15:
                #     print(ai, 'not in rela[', e, '][1]')
                rela[e][1].append(ai)
                self.ree(ai, e, rela)


# a = Solution()

# # a.loudAndRich([[1, 0], [2, 1], [3, 1], [3, 7], [4, 3], [
# #               5, 3], [6, 3]], [3, 2, 5, 4, 6, 1, 7, 0])
# a.loudAndRich([[0, 6], [0, 7], [1, 12], [2, 14], [2, 16], [3, 14], [3, 17], [5, 14], [6, 14], [7, 14], [7, 15], [
#               11, 15], [13, 18], [14, 19], [16, 17]], [6, 15, 17, 12, 0, 11, 19, 16, 13, 2, 8, 18, 10, 5, 4, 7, 14, 3, 1, 9])

# 0 1 7 23 3
#
# 0 71 23 456
#
# @lc code=end
# Time Limit Exceeded
# 85/86 cases passed(N/A)
#  555最后超时了
