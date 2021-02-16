// 请实现一个函数，将一个字符串中的每个空格替换成“% 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。
//   这题其实就是在给定地str中找到空格，并替换成 % 20，由于是一个字符替换成三个字符，所以需要移动元素，如果从前往后移动，假设有n个空格，则第n个空格后面的元素都要被移动n次，很浪费时间，所以从后往前移动，并且不需要额外的数组，先计算出填补后的长度`newlength=oldnumber+n*2`, 然后从后遍历直接`str[pNewlength--]=str[pOldlength];`

class Solution {
  public:
    void replaceSpace(char *str, int length) {
      if (str == NULL || length < 0)
        return;
      int i = 0, oldLength = strlen(str), newLength = 0, blanks = 0;
      while (str[i] != '\0') {
        //oldLength++;
        if (str[i] == ' ')
          blanks++;
        i++;
      }
      newLength = oldLength + blanks * 2;
      if (newLength > length) return;
      while (newLength > oldLength && oldLength >= 0) {
        if (str[oldLength] == ' ') {
          str[newLength--] = '0';
          str[newLength--] = '2';
          str[newLength--] = '%';
        } else {
          str[newLength] = str[oldLength];
          newLength--;
        }
        oldLength--;
      }
    }
};
