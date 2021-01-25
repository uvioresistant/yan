/*3.顺序结构*/
//3-1.cpp
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double f, c, b;
	cout<<"请输入华氏温度："<<endl;
	cin>>f;
	cout<<"对应的摄氏温度为:"<<endl;
	c=f-32;
	b=5.00/9;
	c=b*c;
	cout<<setionsflags;(ios::fixed)<<setprecision(2)<<"c="<c<<endl;
	return 0;
}

/*3-2.cpp 选择结构 单分支结构*/
//输入两个整数，求其中较大的数
#include<iostream>
using namespace std;
int main(){
	int a,b,max;
	cout<<"input two numbers: ";
	cin>>a>>b;
	max=a;
	if(max<b) max=b;
	cout<<"max="<<max;
	return 0;
}

//双分支结构
/*3-3.cpp 计算x的绝对值*/
#include<iostream>
using namespace std;
int main()
{
	int x, y;
	cout<<"input x=";
	cin>>x;
	if(x<0) y=-x;
	else y=x;
	cout<<"x="<<x<<",y="<<y;
	return 0;
}
/*3.4.cpp 判断某年是否为闰年*/
#include<iostream>
using namespace std;
int main()
{
	int x, leap;
	cout<<"input a year:";
	cin>>x;
	leap=0;
	if(x%4==0 && x%100!=0 || x%400==0) leap=1;
	if(leap) cout<<x<<"is a leap year.";
	else cout<<x<<"isn't a leap year.";
	return 0;
}

/*3.5 求一元二次方程ax^2+bx+c=0的根*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,d,re,im;
	float x1,x2;
	cout<<"input a,b,c:";
	cin>>a>>b>>c;
	d=b*b-4*a*c;	//计算根的判别式
	re=-b/(2*a);	//计算实部
	im=sqrt(fabs(d))/(2*a); //计算虚部
	if(d<)	//判别式小于0时输出复数根
	{
		cout<<"the two complex roots are:\n";
		cout<<"x1="<<re<<"+i"<<im<<endl;
		cout<<"x2="<<re<<"-i"<<im<<endl;
	}
	else
	{
		cout<<"the real roots are:\n";
		cout<<"x1="<<re+im<<endl;
		cout<<"x2="<<re-im<<endl;
	}
	return 0;
}


/*3.多分支结构*/
/*3.6 从键盘中任意输入一个字符，判断它的类别:
1) 控制字符，其ASCII码取值范围是0~31;
2) 数字字符(0~9),其ASCII码取值范围是48~57;
3) 大写英文字母(A~Z),其ASCII码取值范围是65~90;
*/
#include<iostream>
using namespace std;
int main()
{
	char c;
	cout<<"input a character:";
	cin>>c;
	if(c<32)
		cout<<"This is a control character\n";
	else if(c>='0' && c<='9')
		cout<"This is a digit \n";
	else if(c>='A' && c<='Z')
		cout<<"This is a capital letter\n";
	else if(c>='a' && c<='z')
		cout<<"This is a small letter\n";
	else cout<<"This is an other character\n";
	return 0;
}

/*3.7 输入3个整数，求其中最大的数和最小的数*/
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,max,min;
	cout<<"input three numbers(a b c):";
	cin>>a>>b>>c;
	if(a>b) {max=a; min=b;}	//将a，b之中的最大值赋给max，最小值赋给b
	else {max=b; min=a;}
		if(max<c) max=c;
		else if(min>c) min=c;
		cout<<"max="<<max<<",min="<<min;
		return 0;
}

/*3.3.1 while语句 统计从键盘输入一行字符的个数*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n=0;
	cout<<"Input a string:\n";
	while(getchar()!='\n') n++;
	cout<<"The total number of characters:"<<n;
	return 0;
}

/*3.14 用for语句计算s=1+2+3+...+(n-1)+n */
#include<iostream>
using namespace std;
int main()
{
	int i,s,n;
	cout<<"input n:";
	cin>>n;
	for(i=1,s=0;i<n+1;i++)
		s+=i;
	cout<<"1-"<<n<<" 的和s="<<s;
	return 0;
}

/*3.15 计算s=Σai, 如n=4, a=3时，s=3+33+333+3333*/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	double s,t;
	int n,i,a;
	cout<<"input a,n:";
	cin>>a>>n;
	if(a<1 || a>9) exit(0);
	if(n<1) exit(0);
	s=0;
	t=0;
	for(i=1;i<n+1;i++)
	{
		t=10*t+a;
		s+=t;
	}
	cout<<"数列的和为:"<<s;
	return 0;
}

/*3.16 判断n是否为质数*/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int i,n;
	cout<<"input a number(n):";
	cin>>n;
	if(n<2) exit(0);
	for(i=2; i<n; i++)
		if(n%i==0) break; //已找到约数，退出循环
	if(i<n) cout<<n<<"不是质数";
	else cout<<n<<"是质数";
	return 0;
}

/*3.17 求正整数n的所有约数及约数个数*/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int i=0,n,count=0;
	cout<<"Input a positive integer please:";
	cin>>n;
	if(n<1) exit(0);
	for(i=1; i<n+1; i++)
	{
		if(n%i) continue;
		//若i不是n的约数，执行for
		cout<<i;
		if(i<n) cout<<",";
		count++;
	}
	cout<<"\nFind"<<count<<"factors";
	return 0;
}

/*3.18 求出100以内的所有质数及其个数*/
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	int i,j,m,count;
	count=1;
	cout<<"2";
	for(i=3;i<100;i+=2)
	{
		m=sqrt(i);
		for(j=3;j<m+1;j+=2)
			if(i%j==0) break;
			if(j<m+1) continue;	//从循环体退出循环时i不是质数
			count++;
			cout<<i<<" ";
	}
	cout<<"\n 共有"<<count<<"个质数";
	return 0;
}

/*3.19 输出4层金字塔的*号*/
#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cout<<"n=?:";
	cin>>n;
	for(i=1;j<n+1;i++)
	{
		for(j=1;j<n+1-i;j++)
			cout<<" ";
		for(j=1;j<=2*i-1;j++)	//输出一行
			cout<<"*";
		cout<<endl;
	}
	return 0;
}

/*3.20 输入若干个数，统计其中正数、负数的个数*/
#include<iostream>
using namespace std;
int main()
{
	int num;
	int zs=0, fs=0;
	while(1)
	{
		cin>num;
		if (!num) break;	//输入0时结束输入
		if (num>0) zs++;
		else fs++;
	}
	cout<<"正数个数为:"<<zs<<"\n负数个数为:"<<fs;
	return 0;
}

/*3.21 求m、n的最大公约数, 用辗转相除法*/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int m,n,r;
	cout<<"input m,n=?:";
	cin>>m>>n;
	if(!m || !n) exit(0);	//m, n应当都不为0
	r=m%n;					//先预求一次余数
	while(r)				//余数不为0时进入循环
	{
		m=n;
		n=r;
		r=m%n;				//重新求余数
	}
	cout<<"GCD="<<n;
	return 0;
}

/*3.22 求出离正整数n最近的质数。例如，当n=8时，所求质数是7; 当n=11时，结果为13*/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int i,j,m,n,n1,n2;
	while(1)
	{
		cout<<"input a number(n):";
		cin>>n;
		if(n>0) break;
			cout<<"You input invalid data. input again, please!";
	}
	n1=0;
	for(j=n-1;j>1;j--)
	{
		m=sqrt(j);
		for(i=2;j<m+1;i++)
			if(j%i==0) break;
		if(i>m) {n1=j;break;}	//左边找到质数时，将它存储到n1中
	}
	for(j=n+1; ;j++)	//循环条件永远为真，找到质数时，才结束循环
	{
		m=sqrt(j);
		for(i=2;i<m+1;i++)
			if(j%i==0) break;
		if(i>m){n2=j; break;}	//右边找到质数，将它存储到n2中，结束循环
	}
	if(!n1 || n-n1!=n2-n)
	{
		if(!n1) m=n2;
		else m=n-n1<n2-n?n1:n2;
		cout<<"The nearest prime from"<<n<<"is"<<m;
	}
	else cout<<"The nearest prime from"<<n<<"is"<<n1<<"and"<<n2;
	return 0;
}

/*3.23 求正整数m(m>=2)的所有素数因子*/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int m,i,j;
	cout<<"input an integer m(m>=2):";
	cin>>m;
	for(i=2;i<=m;i++)
	{
		if(m%i!=0) continue;
		for(j=2;j<i;j++)	//判断因子i是否为素数
			if(i%j==)	break;
		if(j==i)	cout<<i<<" ";
	}
	return 0;
}



































