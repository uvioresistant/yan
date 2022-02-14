// 判断字符相等1
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream in("string.txt");
  for(string s, t; in>>s>>t;){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    cout<<(s==t ? "yes\n" : "no\n");
  }
}

// 如果有数千对字符串需要比较，每个字串长达1024个字符，该程序虽然能解决问题，但算法并不十分有效