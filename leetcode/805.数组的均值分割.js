/*
 * @lc app=leetcode.cn id=805 lang=javascript
 *
 * [805] 数组的均值分割
 *
 * https://leetcode.cn/problems/split-array-with-same-average/description/
 *
 * algorithms
 * Hard (30.27%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 22.8K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * 给定你一个整数数组 nums
 *
 * 我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) ==
 * average(B) 。
 *
 * 如果可以完成则返回true ， 否则返回 false  。
 *
 * 注意：对于数组 arr ,  average(arr) 是 arr 的所有元素除以 arr 长度的和。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7,8]
 * 输出: true
 * 解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [3,1]
 * 输出: false
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 30
 * 0 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var splitArraySameAverage = function (nums) {
  let ans = false;
  const b = nums.length,
    a = nums.reduce((pre, curr) => pre + curr, 0),
    vis = Array(nums.length).fill(0);
  const select = (n, x, i, num) => {
    if (num !== 0 && x * b === a * num) {
      ans = true;
      return;
    }
    if (num >= n || ans === true) {
      return;
    }
    for (let j = i; j < b; j++) {
      if (!vis[j]) {
        vis[j] = 1;
        select(n, x + nums[j], j + 1, num + 1);
        vis[j] = 0;
      }
    }
  };
  for (let i = 1; i < b - 1; i++) {
    select(i, 0, 0, 0);
  }
  return ans;
};
// 这个方法会超时,下面这个写的相对通俗易懂
console.log(splitArraySameAverage([1, 2, 3, 4, 5, 6, 7, 8]));
// @lc code=end

/**
 *     public boolean splitArraySameAverage(int[] nums) {
        if (nums.length == 1) {
            return false;
        }
        int n = nums.length, m = n / 2;
        int sum = 0;
        // 对数组求和
        for (int num : nums) {
            sum += num;
        }
        // 如果直接将 nums 中的每个元素减去数组和的平均值（sum/n），可能会引入浮点数，判断时出现误差
        // 所以这里先将 nums 的每个元素乘以 n，这样数组和的平均值则变为 sum （无需除以n），而 nums[i]*n-sum 一定为整数
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * n - sum;
        }

        // 将数组一分为二，从前半个数组中的 m 个元素中取出若干个元素形成不同的子集，共有 2^m 种取法，每种取法得到的子数组和用Set记录
        Set<Integer> left = new HashSet<Integer>();
        // 这里元素的选择借助位运算实现，例如对于case1的 nums=[1,2,3,4,5,6,7,8]，m=4，i取值范围为[1,15]，
        // 例如当 i=6 时，二进制表示为 110，则意味着选取第2和第3个元素求和，即 tot=nums[2]+nums[1]
        // i: 因为至少要取一个元素，所以 i 从1开始，直到 2^m-1
        for (int i = 1; i < (1 << m); i++) {
            int tot = 0;
            // 对每种取法，都要遍历前半个数组，选取相应的元素进行求和
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) != 0) {
                    tot += nums[j];
                }
            }
            // 如果前半个数组有部分元素之和为0，则剩余的所有元素之和肯定也为0，直接返回true。
            if (tot == 0) {
                return true;
            }
            left.add(tot);
        }
        // 记录后半个数组的所有元素之和，用于后面判断，避免出现同时选择数组中所有元素之和为0的情况
        int rsum = 0;
        for (int i = m; i < n; i++) {
            rsum += nums[i];
        }
        // 对后半个数组如法炮制
        for (int i = 1; i < (1 << (n - m)); i++) {
            int tot = 0;
            for (int j = m; j < n; j++) {
                if ((i & (1 << (j - m))) != 0) {
                    tot += nums[j];
                }
            }
            // 当 后半个数组有部分元素之和为0，或者 前半个数组的子集的元素之和 是 后半个数组的子集的元素之和 的相反数时，返回true。
            // 为什么不会出现 前半个数组的真子集的元素之和 是 后半个数组的全部元素之和 的相反数这种情况？
            // 因为如果是这种情况，在遍历前半个数组时就会直接返回true
            if (tot == 0 || (rsum != tot && left.contains(-tot))) {
                return true;
            }
        }
        return false;
    }
 */
