// 求素数个数筛法版
#include<iostream>
#include <bitset>
using namespace std;

int main(){
  bitset<100000000>* p = new bitset<100000000>;
  p->set();
  for(int i=2; i<=10000; ++i)
    if(p->test(i))
      for(int j=i*i; j<p->size(); j+=i)   //完成素数标记
        p->reset(j);
  int num=0;
  for(int i=2; i<100000000; ++i)     //清点素数
    if(p->test(i))
      num++;
  cout<<num<<endl;
  delete[] p;
}