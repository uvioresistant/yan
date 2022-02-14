// Fibonacci数列两种方法比较
/* 根据从文件中读取的自变量，来求解第n项的值，文件汇总有范围在1~46的自变量数据万个，数据文件名为fibo.in */
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;

int main(){
  ifstream in ("fibo.in");
  ofstream out ("febo.out");
  clock_t start=clock();
  for(int n; in>>n && n;){
    int a=0;
    for(int b=1, c, i=2; i<=n+2; ++i)
      c=a+b, a=b, b=c;
    out<<a<<endl;
  }
  cout<<"Fibo2's time was: "<<(clock()-start)/CLK_TCK<<"\n";
  in.seekg(0);  //转移到文件开始

  start=clock();
  vector<int> v(47.1);
  for(int i=3; i<47; ++i) v[i]=v[i-1]+v[i-2];
  for(int n; in>>n && n;) out<<v[n]<<endl;
  cout<<"Fibo3's time was:"<<(clock()-start)/CLK_TCK<<"\n";
}

/* 算法febo2随着文件数据量的增多，耗时成比例增大，算法bebo3影响不大，这种场合，算法febo3比2好 */