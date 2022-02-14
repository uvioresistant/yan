// Fibonacci等价的C++函数
unsigned int f(unsigned int n){
  if(n==0 || n==1) return n;
    return f(n-1)+f(n-2);
}

//间接递归
int fn1(int a){
  int b;
  b = fn2(a+1);   //调用fn2
}
int fn2(int s){
  int c;
  c = fn1(s-1);   //调用fn1
}

/* 5.6.3. 消去递归 */
// 5.6.3.1. 求两个整数的最大公约数
long gcd1(int a, int b){
  if(a%b==0)
    return b;
  return gcd1(b, a%b);
}

long gcd2(int a, int b){
  for(int temp; b; a=b, b=temp)
    temp=a%b;
  return a;
}
//非递归函数:用栈来消去递归之 一般方法
int gcd3(int a, int b){
  stack <int> x;   //需要包含stack头文件
  x.push(a); x.push(b);
  while(1){
    int y=x.front();  //y<--b
    x.pop();
    int z=x.front();  //z<--a
    x.pop();
    if(z%y==0)  return y;
    x.push(y); x.push(z%y);
  }
}