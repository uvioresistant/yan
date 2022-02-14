//剩下串的排列版本二
// 对两个集合分别排序的代价大，t串无需排序
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream in ("remainder.txt");
  for(string s, t; in>>s>>t;){
    sort(s.begin(),s.end());
    for(int i=0; i<s.length(); ++i)
      if(t.find(s[i])==string::npos) cout<<s[i];  //判断find搜索结果，是与string:npos进行比较，npos在string类中定义，表示搜索不到；如果搜索成功，返回的string对象中某个找到的位置
    cout<<endl;
  }
}