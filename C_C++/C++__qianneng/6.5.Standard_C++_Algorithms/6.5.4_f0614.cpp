// 判断字串相等版本3
/* 字串中非1即0，"0"的个数在总长度已知的情况下，可不使用count算法，通过并列地判断总长度的相等性直接得到 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  ifstream in("string.txt");
  for (string s, t; in >> s >> t;)
  {
    int s1=count(s.begin(), s.end(), '1');
    int t1=count(s.begin(), t.end(), '1');
    cout << (s1 == t1 && s.length()==t.length() ? "yes\n" : "no\n");
  }
}