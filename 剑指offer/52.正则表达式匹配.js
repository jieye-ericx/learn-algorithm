function isNumeric(s) {
  var reg = /^[\+-]?\d*\.?\d+(e[\+-]?\d+)?$/i;
  return reg.test(s);
}
/**
 *
1.首先，用 开头符 ^ 和 结尾符 $ 界定待匹配字符串的界限；
2.[\+-]? 匹配字符串开头的正负号，可正可负，也可以没有正负号；
3.\d*\.?\d+ 用于匹配数值部分，此时暂不考虑用科学计数法表示的数，我们需要考虑以下几种情况：
  如果字符串数值部分只包含整数，可以使用 \d+ 匹配
  如果字符串数值部分有小数，则要使用 \d+\.\d+ 匹配
  如果是小数，则小数点前面可以没有整数部分，例如：".123"也是合法的，则修改匹配规则：\d*\.\d+
  综上，我们将所有可能的情况合并，得到匹配规则：\d*\.?\d+
4.数值中有种特殊的表示方法，即科学记数法。首先要弄懂科学计数法的表示规则，之后我们来做适配规则：\d+[eE][\+-]?\d+
5.合并上述所有的匹配规则，得到：^[\+-]?\d*\.?\d+(\d+[eE][\+-]?\d+)?$。
  乍一看以为正则表达式写好了，其实这样写有一个错误。尤其注意第3步和第4步合并的地方。
  假如是匹配"5E2"，则会返回失败。细看可以发现，在第3步，我们已经确保了数字串中至少有一位数字。
  而在第4步中，我们又考虑了使用科学计数法表示在符号"e"的前面至少有一个数字的情况，多次一举。所以我们应该做出如下修改：
  ^[\+-]?\d*\.?\d+([eE][\+-]?\d+)?$

我们知道，JavaScript中可以给正则表达式设置i标识，以忽略匹配规则中的大小写，故我们最终将正则表达改为如下表示：
  var reg = /^[\+-]?\d*\.?\d+(e[\+-]?\d+)?$/i;
 */