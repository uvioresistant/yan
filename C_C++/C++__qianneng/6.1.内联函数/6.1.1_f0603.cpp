// 内联函数
#include <iostream>
using namespace ::std;

inline bool isnumber(char);   //内联声明


int main(){
  char c;
  while(cin>>c && c!='\n')
    if(isnumber(c)) cout<<"you entered a digit.\n";
    else cout<<"you entered a non-digit.\n";
}

bool isnumber(char ch){
  return ch>='0' && ch<='9' ? 1:0;
}