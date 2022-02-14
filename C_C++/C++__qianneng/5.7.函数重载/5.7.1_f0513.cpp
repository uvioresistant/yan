// 函数重载
#include<iostream>
using namespace std;
int abs(int a){
    return (a>0)? a : -a;
}
double abs(double a){
    return (a>0)? a : -a;
}

int main(){
    std::cout<<abs(-10)<<endl;
    std::cout<<abs(-12.23)<<endl;
}