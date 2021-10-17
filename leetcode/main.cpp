#include "defs.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    uint8_t marks[256];
    int maxValue = 0, length = s.length();
    const char *str = s.c_str();
    memset(marks, 0, sizeof(uint8_t) * 256);
    // // 滑动窗口的开始和停止
    // int p = -1, e = 0;
    // while (e < length) {
    //   if (marks[str[e]]) {
    //     while (str[p + 1] != str[e]) {
    //       p++;
    //     }
    //     marks[str[p]] = 1;
    //   }
    //   e++;
    //   marks[str[e]] = 1;
    // maxValue = max(maxValue, int(e - p));
    int p = 0;
    for (int i = 0; i < length; i++) {
      // 左指针：i，右指针：p
      if (i) marks[str[i - 1]] = 0;
      while (p < length && !marks[str[p]]) {
        marks[str[p]] = 1;
        p++;
      }
      maxValue = max(maxValue, p - i);
    }
#ifdef DEBUG
    // const char *pp = str;
    // while (*pp) {
    //   if (pp - str == p) putchar('(');
    //   putchar(*pp);
    //   if (pp - str == e) putchar(')');
    //   pp++;
    // }
    // puts("");
#endif
    return maxValue;
  }
};