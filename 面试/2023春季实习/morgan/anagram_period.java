
/**
 * A string can be formed using another string "s" by repeatedly concatenating
 * the
 * anagrams of "s" any number of times. Given a string input_str of length n,
 * find
 * out the length of the smallest string s that can be used to create input_str.
 *
 * Note that the string input_str only consists of the lowercase English
 * letters.
 *
 * Example
 * input_str = "ababbaab"
 * In the above example, the length of the string n=8.
 * One of the possible strings s can be "aabb"', First append "abab" and then
 * append "baab".
 * Another possible string s can be "ab',append the anagrams of s in the
 * order:"ab", "ab", "ba"' and "ab"'.
 *
 * It can be proved that the length of s cannot be reduced further than 2.Hence,
 * we return 2 as the answer.
 *
 * Function Description
 * Complete the function getAnagramPeriod in the editor below.
 * BetAnagramPeriod has the following parameter(s):
 * string input_ str: a string of length n
 * Returns
 * int. the length of the smallest possible string 5
 *
 * Constraints
 *
 * •input. str consists of lowercase English letters
 *
 * •1≤n≤100000
 *
 *
 */

import java.util.*;

public class Solution {
  public static int getAnagramPeriod(String input_str) {
    int n = input_str.length();
    if (n == 1) {
      return 1;
    }
    int[] freq = new int[26];
    for (int i = 0; i < n; i++) {
      freq[input_str.charAt(i) - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        count++;
      }
    }
    if (count == 1) {
      return 1;
    }
    int ans = n;
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        int len = i;
        int[] temp = Arrays.copyOf(freq, 26);
        int j = 0;
        while (j < n) {
          boolean flag = true;
          for (int k = 0; k < len; k++) {
            if (temp[input_str.charAt(j + k) - 'a'] == 0) {
              flag = false;
              break;
            } else {
              temp[input_str.charAt(j + k) - 'a']--;
            }
          }
          if (flag) {
            j += len;
          } else {
            break;
          }
        }
        if (j == n) {
          ans = Math.min(ans, len);
        }
      }
    }
    return ans;
  }
}