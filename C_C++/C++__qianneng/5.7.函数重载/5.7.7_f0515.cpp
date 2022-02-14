// 别扭的参数默认
#include<iostream>
#include <vector>
using namespace std;

vector<int> b(10, 0);
void print(const vector<int>& a=b);
bool process(vector<int>& a);

int main(){
    vector<int> a(10, 5);
    if(process(a)) print(a);
    else print();
}

void print(const vector<int>& a){
    if(a==vector<int>(10, 0)){
        cout<<"failed.\n";
        return;
    }
    for(int i=0; i<a.size(); ++i)
        
}