// 频繁调用一个小函数
#include <iostream>
using namespace std;

bool isnumber(char);

int main()
{
  char c;
  while (cin >> c && c != '\n') //反复读入字符，若为回车便结束
    if (isnumber(c))
      cout << "you entered a digit. \n";
    else
      cout << "your entered a non-digit. \n";
}

bool isnumber(char ch)
{
  return ch >= '0' && ch <= '9' ? 1 : 0;
}


