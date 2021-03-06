/* 给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

!示例 1:
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
!示例 2:
输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
  */

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main()
{

    return 0;
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    vector<int> ans(n, -1), ans1;
    stack<int> s;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && nums2[s.top()] < nums2[i % n])
        {
            // ?s.top()是nums2的数组下标
            ans[s.top()] = nums2[i % n];
            s.pop();
        }
        s.push(i % n);
    }
    for (int i = 0; i < n; i++)
    {
        m[nums2[i]] = ans[i];
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans1.push_back(m[nums1[i]]);
    }
    return ans1;
}