// 矩阵转置
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<int>> a; //全局变量

void input();
void transpose();
void print();

int main(){
  input();
  transpose();
  print();
}

void input(){
  ifstream in("a.txt");
  int row, col;
  in>>row>>col;
  a.resize(row, vector<int>(col));
  for(int i=0; i<row; ++i)
  for(int j=0; j<col; ++j)
    in>>a[i][j];
}

void transpose(){
  vector<vector<int>> b(a[0].size(), vector<int>(a.size()));
  for(int i=0; i<a.size(); ++i)
  for(int j=0; j<a[0].size(); ++j)
    b[j][i] = a[i][j];
  a=b;
}

void print(){
  for(int i=0; i<a.size(); ++i){
    for(int j=0; j<a[0].size(); ++j)
      cout<<setw(4)<<a[i][j];
    cout<<endl;
  }
}