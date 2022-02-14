// 判断字串相等2
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  ifstream in("string.txt");
  for (string s, t; in >> s >> t;)  //in>>s>>t充当了循环变量初始化、条件判断和循环迭代三重身份
  {
    int sc1=count(s.begin(), s.end(), '1');
    cout << sc1<<endl;
    int sc0=count(s.begin(), s.end(), '0');
    int tc1=count(s.begin(), s.end(), '1');
    int tc0=count(s.begin(), s.end(), '0');
    cout << (sc1 == tc1 && sc0==tc0 ? "yes\n" : "no\n");
  }
}