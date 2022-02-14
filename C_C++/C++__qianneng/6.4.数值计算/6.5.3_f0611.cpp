// 辛普生积分
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double g(double x){
  return 1/x;
}

template<class T>
T rectangle(T a, T b, const T Epsilon, T(*f)(T));

double simpson(double a, double b, double(*f) (double)){
  double I2n=0, h=b-a, T2n=h*(f(a)+f(b))/2, In=T2n, Tn;
  for(int n=1; abs(I2n-In)>=1e-3; n+=n, h/=2.0){
    In=I2n; Tn=T2n;
    double sigma=0;
    for(int k=0; k<n; k++)
      sigma+=f(a+(k+0.5)*h);
    T2n=(Tn+h*sigma)/2;
    I2n=(4*T2n-Tn)/3;
  }
  return I2n;
}

int main(){
  ifstream in("integral.txt");
  cout<<fixed; cout.precision(3);
  for(double b; in>>b;)
    cout<<simpson(1,b,g)<<"\n";
}

/* 如果精度要求很高，在10^-10以上，可明显看出两者的计算时间差异，循环能更快到达精度要求 */