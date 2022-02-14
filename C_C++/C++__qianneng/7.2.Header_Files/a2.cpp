#include"abc.h"
#include"a1.h"
#include"a3.h"

static void f3();


int main(){
  f1();
  f2();
  f3();
}

void f3(){
  f1();
}

void p(){
  p3();
}