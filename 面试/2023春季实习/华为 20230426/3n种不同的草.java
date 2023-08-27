
/*
将n种不同的草随机种在一块广漠无垠的二维平面上(直角坐标系内），给定二维数组 points 表示第0天所有草的初始位置，
第i项 points[i]=[xi, yi] 表示第0天草i在点[xi,yi]。每天，
被草覆盖的点会向外蔓延到它上、下、 左、右、左上、左下、右上、右下8个邻居点。注意，初始状态下，可能有多种草在同一点上。

现给定一个整数 M，问最少需要多少天，方能找到一点同时至少有M种草？

输入:
第一行输入整数M。 (2<=M <=n)
第二行输入草的种数n。（2<=n <=50)
后面连续n行输入草i初始位置[xi, yi]。 (1<=xi, yi ≤= 10^9)

输出
返回找到一点至少生长 M 种草的最少天数，找不到返回0

样例1
输入：
2
2
2 1
6 2
输出：
2
*/
import java.util.*;

class Solution {
  static int minDaysToFindMGrasses(int M, int n, int[][] points) {
    Map<List<Integer>, Set<Integer>> grassPoints = new HashMap<>();
    Queue<List<Integer>> queue = new LinkedList<>();

    for (int i = 0; i < n; i++) {
      int x = points[i][0];
      int y = points[i][1];
      List<Integer> point = new ArrayList<>(Arrays.asList(x, y, i));
      grassPoints.computeIfAbsent(point.subList(0, 2), k -> new HashSet<>()).add(i);
      queue.offer(point);
    }

    int days = 0;

    while (!queue.isEmpty()) {
      days++;
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        List<Integer> point = queue.poll();
        int x = point.get(0);
        int y = point.get(1);
        int grass = point.get(2);
        for (List<Integer> neighbor : getNeighbors(x, y)) {
          grassPoints.computeIfAbsent(neighbor, k -> new HashSet<>()).add(grass);
          if (grassPoints.get(neighbor).size() >= M) {
            return days;
          }
          queue.offer(Arrays.asList(neighbor.get(0), neighbor.get(1), grass));
        }
      }
    }

    return 0;
  }

  static List<List<Integer>> getNeighbors(int x, int y) {
    List<List<Integer>> neighbors = new ArrayList<>();
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx != 0 || dy != 0) {
          neighbors.add(Arrays.asList(x + dx, y + dy));
        }
      }
    }
    return neighbors;
  }

  public static void main(String[] args) {
    int M = 2;
    int n = 3;
    int[][] points = { { 2, 1 }, { 6, 2 }, { 100, 100 } };
    System.out.println(minDaysToFindMGrasses(M, n, points)); // 输出：2
  }
}