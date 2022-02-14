#include <iostream>
#include <cstdio>

using namespace std;

int Reverse(int x){
  int revx = 0;
  while(x !=0){
    revx *= 10;
    revx += x % 10;
    x /= 10;
  }
  return revx;
}

/* int Reverse(int x){
  int revx = 0;
  while(x != 0){ //x==1089 108 10 1
    revx *= 10; //revx = 0 90 980 9810
    revx += x%10; //revx=9 98 981 9810
    x /=10; //108 10 1 0
  }
  return revx;
}
 */
int main(){
  for (int i=1000; i<=9999; ++i){
    if(i*9 == Reverse(i)) { //i=1089*9 == Reverse=9810
      printf("%d\n", i);
    }
  }
  return 0;
}
