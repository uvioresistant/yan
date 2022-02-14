// 消除全局数据
//通过参数传递的方法消除全局数据
#include<iostream>
#include<vector>
#include<iomanip>
#include<vector>
using namespace std;

typedef vector<vector<int>> Mat;
Mat input();
Mat transpose(const Mat& a);
void print(const Mat& a);

int main(){
  print(transpose(input()));
}

Mat input(){
  ifstream in ("a.txt");
  int row, col;
  in>>row>>col;
  Mat a(row, vector<int>(col));
  for(int i=0; i<row; ++i)
  for(int j=0; j<col; ++j)
    in>>a[i][j]
  return a;
}

Mat transpose(const Mat& a){
  Mat b(a[0].size(), vector<int>(a.size()));
  for(int i=0; i<a.size(); ++i)
  for(int j=0; i<a[0].size(); ++j)
    b[j][i]=a[i][j];
  return b;
}

void print(const Mat& a){
  for（int i=0; i<a.size(); ++i){
    for(int j=0; j<a[0].size(); ++j)
      cout<<setw(4)<<a[i][j];
    cout<<endl;
  }
}