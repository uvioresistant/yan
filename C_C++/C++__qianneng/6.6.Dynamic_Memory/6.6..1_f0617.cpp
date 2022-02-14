// 清点单词数
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
typedef multimap<int,int> Mmap;

int main(){
  ifstream in ("abc.txt");
  vector<string> abc;
  // abc.reserve(1100); //如果大概知道元素的个数，可用reserve操作来预留若干空间，避免频繁申请内存和释放操作
  Mmap nums;
  int n=0;
  for(string s; getline(in,s); ){
    istringstream sin(s);
    int num=0;
    for(string t; sin>>t; num++);
    if(num){
      nums.insert(Mmap::value_type(num, n++));
      abc.push_back(s);
    }
  }
  for(Mmap::iterator it=nums.begin(); it!=nums.end(); ++it)
    cout<<abc[it->second]<<endl;
}