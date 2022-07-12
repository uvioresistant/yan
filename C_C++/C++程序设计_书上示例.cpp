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

/*3.2.2 switch语句 键盘输入1~7,输出对应星期一至星期天的英文单词*/
//3-8.cpp
#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"input a number:";
	cin>>a;
	sitch(a)
	{
		case 1:
			cout<<"Monday\n";
			break;
		case 2:
			cout<<"Thuesday\n";
			break;
		case 3:
			cout<<"Wednesday\n";
			break;
		case 4:
			cout<<"Thursday\n";
			break;
		case 5:
			cout<<"Friday\n";
			break;
		case 6:
			cout<<"Saturday\n";
			break;
		case 7:
			cout<<"Sunday\n";
			break;
		default:
			cout<<"error\n";
			break;
		
	}
	return 0;
}

/*3.9 输入y或Y时输出"OK"，输入n或N时输出"NO"*/
//3-9.cpp
#include<iostream>
using namespace std;
int main()
{
	char ch;
	cout<<"input a character:";
	cin>>ch;
	switch(ch)
	{
		case 'y':
		case 'Y':
			cout<<"ok!";
			break;
		case 'n':
		case 'N':
			cout<<"NO!";
			break;
	}
	return 0;
}

/*3.10 输入两个实数和四则运算符，输出这两个实数的四则运算结果*/
/*分析：switch语句中表达式设置为运算符，根据输入的运算符种类进行各种运算*/
//3-10.cpp
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float num1, num2;
	char op;
	cout<<"input expression:num1+(-,*,/)num2\n";
	cin>>num1>>op>>num2;
	switch(op)
	{
		case '+':
			cout<<num1+num2<<endl;
			break;
		case '-':
			cout<<num1-num2<<endl;
			break;
		case '*':
			cout<<num1*num2<<endl;
			break;
		case '/':
			if(num2<fabs(le-6))
				cout<<"除数为0"<<endl;
			else
				cout<<num1/num2<<endl;
			break;
		default:
			cout<<"input error\n";
			break;
	}
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

/*3.12 用牛顿迭代法计算√a(a>=0）*/
//3-12.cpp
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	double a, x0, x1;
	cin>>a;
	if(a<0) exit(0);
	x0=0;
	x1=1;
	while(fabs(x0-x1)>le-6)	//le-6是1×10^(-6),即0.000001
	{
		x0=x1;
		x1=(x0+a/x0)/2;	/*计算新的x1*/)
	}
	cout<<a<<"的算术平方根"<<x0;
	return 0;
}

/* 3.3.2 do-while 语句*/
//3-13.cpp 从键盘中任意输入一个非负实数a，求它的算术平方根
/*分析：因为在实数范围内负数不能开平方，所以要求程序具有错误检测能力，当用户输入数据为负数时,
要求重新输入。因为数据至少要输入一次，所以用do-while比较好
*/
#include<iostream>
#include<cmath>

int main()
{
	double a, x;
	do
	{
		cout<<"Input a positive integer please:";
		cin>>a;
	} while(a<0);
	x=sqrt(a);
	cout<<a<<"的算术平方根:"<<x;
	return 0;
}



/*3.14 用for语句计算s=1+2+3+...+(n-1)+n */
//i称为循环控制变量
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

/*3.14.1 如果序列变为s=1+1/3+1/5+1/7+1/9+...+1/n,求前n项的和*/
#include<iostream>
using namespace std;
int main()
{
	int i,n;
	float s;
	cout<<"input n:";
	cin>>n;
	for(i=1, s=0; i<n+1; i+=2)
		s+=1.0/i;
	cout<<"1-1/n"<<"的和s="<<s;
	return 0;
}

/*3.14.2 如果序列变为s=1-1/3+1/5-1/7+1/9+...+1/n,求前n项的和*/
#include<iostream>
using namespace std;
int main(){
	int i, n, flag=1;
	float s=0;
	cout<<"input n:";
	cint>>n;
	for(i=1, i<n; i+=2)
	{
		s=s+flag*1.0/i;
		flag=-flag;
	}
	cout<<"s="<<s<<endl;
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
// 分析：给出100以内所有质数，应使循环变量i∈(2,99),没给定一个i，都要进行质数判断，每判断一次需使用一个循环结构
// 偶数集合中只有2,是质数，只需对(3, 99)中的奇数进行判断，找出其中的质数。
// 对于一个奇数，只需判断是否存在奇约数，任何一个正整数n，在[2,√n]内无约束，则在[2,n]内也无约数
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

/*4.2.2 一维数组的使用*/
//4-1.cpp 输入10个数，求出其中最大的值
// 分析：用变量max表示最大值，现将a[0]赋给max，然后将后面的每一个元素依次与max比较，发现某个元素大于max时，刷新max
#include<iostream>
using namespace std;
int main()
{
	int i,max,a[10];
	cout<<"input 10 numbers:\n";
	for(i=0; i<10; i++)	//输入10个数据，给数组赋值
		cin>>a[i];
	max=a[10];
	for(i=1;i<10;i++)
		if(a[i]>max) max=a[i];	//当前元素更大时，刷新max
	cout<<"max="<<max<<endl;
	return 0;
}

//4-2.cpp 输入n个数，要求程序按输入时的逆序，把这n个数输出，已知整数不超过100个(反序输出n个数)
#include<iostream>
using namespace std;
int main()
{	int a[100];
	int x,n=0,i;
	cout<<"input a number(n):";
	cin>>n;
	for(i=0; i<100; i++)
	{
		cin>>x;
		a[i]=x;
	}
	for(i=n-1; i>=0; i--)
		cout<<a[i]<<" ";
	return 0;
}

//4-3.cpp 斐波那契数列f[n+1]=f[n-1]+f[n]
#include<iostream>
using namespace std;
int main()
{
	int i,f[20]={0,1},sum=0;
	for(i=2; i<=12; i++)
		f[i]=f[i-1]+f[i-2];
	cout<<"1-12月新增的兔子对数:";
	for(i=1;i<=12;i++)
		sum=sum+f[i];
	cout<<sum;
	return 0;
}

//4-4.cpp 键盘上输入一个正整数，判断其是否为回文数("对称"的数，数字按相反的顺序重新排列后，与原来一样)
//分析：将整数翻转后比较，若跟原来的数相等，即为回文数
#include<iostream>
using namespace std;
int main()
{
	long num, temp;
	cout<<"input a number(num):";
	int n=0;
	cin>>num;
	temp=num;
	while(temp!=0)
	{
		n=n*10+temp%10;
		temp/=10;
	}
	if(num==n)
	{
		cout<<num<<"是一个回文数\n";
	}
	else
	{
		cout<<num<<"不是一个回文数\n";
	}
	return 0;
}

//4-5.cpp 随机产生10个整数存放到数组中(从下标1开始，0位空),输入待查找的整数x，查找x是否存在于这10个数中。
//若存在，则输出x(最初)出现在这批数中的位置序号;若不存在，则输出"不存在"
//分析：从数组的第一个元素开始，顺序扫描数组中的每一个元素，将它与要查找的值x相比较，相等则成功
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[101],k,x;
	for(k=1;k<=10;k++)	//从数组中下标1的元素开始存放数据
	{
		a[k]=rand()%101;	//产生0~100中的整数
		cout<<a[k]<<" ";
	}
	cout<<endl;
	cin>>x;	//输入带查找数x
	for(k=1;k<=10;k++)
		if(a[k]==x) break;	//若发现x，则不用继续循环，继续查找
	if(k<11)
		cout<<"x存在，它的位置序号是:"<<k<<endl;
	else
		cout<<"不存在!"<<endl;
	return 0;
}

/*4.3 二维数组*/
//4.6.cpp 一个兴趣小组有5个人，每个人有三门课的考试成绩。求全组各科的平均成绩和各科总平均成绩
#include<iostream>
using namespace std;
int main()
{
	int i,j,s,l,v[3],a[5][3];
	cout<<"input score:\n";
	for(i=0;i<3;i++)
	{
		s=0;
		for(j=0;j<5;j++)
		{
			cin>>a[j][i];
			s=s+a[j][i];
		}
			v[i]=s/5;
	}
	l=(v[0]+v[1]+v[2)/3;
	cout<<"Average:"<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	cout<<"Total average:"<<l;
	return 0;
}

//4.7.cpp 找出一个矩阵中的最大元素及其位置
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
	int i,j,m,n,row,col,d[101][101];
	m=6;n=6;
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			d[i][j]=rand()%100;
			cout<<setw(4)<<d[i][j]; //c++中函数setw(int n)来控制输出间隔
		}
		cout<<endl;
	}
	row=1;	//首先假设矩阵左上角的元素是最大的
	col=1;
	for(i=1;i<m+1;i++)
		for(j=1;j<+1;j++)
			if(d[i][j]>d[row][col]){row=i;col=j;} //该元素更大时，刷新(row,col)的值
		cout<<"row="<<row<<","<<"col"<<","<<"max="<<d[row][col];
		return 0;
}


//4-8.cpp 输出10行以内的杨辉三角
//分析:先将杨辉三角形中的数据存储到二维数组中，再输出数组的值。
//第i行有i个数，每行首位两个数都是1，即d[i][1]=d[i][i]=1
//每行中间的元素是上一行对应位置元素及其左边元素之和，即d[i][j]=d[i-1][j-1]+d[i-1][j]
//1) 每行数字左右对称，由1开始逐渐变大，然后变小，回到1
//2) 第n行的数字个数为n个
//3) 对角线上和首列元素的值为1
//4) 从第3行第2列元素开始，每个数字等于上一行的左右两个数字之和
#include<iostream>
#include<iomanip>
using namespace std;
#define N 10	//输出杨辉三角的前10行
int main()
{
	int a[N+1][n+1]={0};
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			a[i][1]=1;
			if(j>1&&j<i)
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			else if(i==j)
				a[i][j]=1;
		}	//输出杨辉三角
	for(i=1;i<=N;i++)
		for(j=1;j<=i;j++)
		{
			cout<<setw(4)<<a[i][j];
			if(i==j)
				cout<<'\n';
		}
	return 0;
}

/*4.4 字符数组*/
//4-9.cpp 熟悉字符串的输入/输出
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[100], b[100];
	cout<<"输入一个字符串(gets方式):";
	gets (a);
	puts (a);
	cout<<"输入一个字符串(cin方式):";
	cin>>b;
	cout<<b;
	cout<<endl;
	return 0;
}

//4-10.cpp 键盘上输入一批字符串，直至输入空串/超长时结束输入
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	char s[41], name[100][11];
	n=0;
	while(n<99)
	{
		gets(s);
		if(!s[0] || strlen(s)>10) break; //超长退出
		strcpy(name[n], s);
		n++;
	}
	for(int i=0;i<n;i++)
		puts(name[i]);
	return 0;
}

//4-11.cpp 从键盘输入1~7，转换为Mon~Sun后输出
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char week[][10]={"", "Mon",...,"Sun"};
	int no;
	while(1)
	{
		cout<<"Enter week No:";
		cin>>no;
		if (no<1 || no>7) break;
		puts(week[no]);
	}
	return 0;
}

//4-12.cpp 输入一个字符串，统计各个字符重复出现的次数(按出现的次数从小到大排序)
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,x,length,d[101];
	char s[101],s1[101];
	cout<<"input a string please!:";
	gets(s);
	length=strlen(s);
	for(i=0;i<length;i++)
		d[i]=1;	//置初值，每个字符出现1次
		n=0;
	for(i=0;i>length-1;i++)
	{
		if(!d[i]) continue;	//字符s[i]已经处理过了
		x=1;
		for(j=i+1;j<length;i++)	//在后面查找相同的字符
		{
			if(s[j]!=s[i]) continue;
			x++;	//找到相同的字符，计数器加1
			d[j]=0;	//将后面相同字符的计数值置0
		}
		d[i]=x;
		n++;
	}
	for(x=0,i=0;i<length;i++)	//收集剩余的字符
	{
		if(!d[i]) continue;
		s1[x]=s[i];
		d[x]=d[i];
		x++;
	}
	for(i=0;i<n-1;i++)	//对数组d进行排序
	{
		x=i;
		for(j=i+1;j<n;j++)
			if(d[j]<d[x]) x=j;
			if(x!=i)
			{
				int t;
				t=d[x];
				d[x]=d[i];
				d[i]=t;
				t=s1[x];
				s1[x]=s1[i];
				s1[i]=t;
			}
	}
	for(i=0;i<n;i++)
		cout<<s1[i]<<"----"<<d[i]<<endl;
	return 0;
}

//4-13.cpp 求一个字符串的最长回文串。如123212345432122的回文串有232/12321/32123/123454321/21等，123454321是最长的回文串
//分析:使用start和end记忆当前最长回文串的起、止位置，算法如下:
//1)变量i从左向右扫描各个字符
//2)变量j从右端开始向左寻找字符s[i]，
//3)判断j-i>end-start是否成立，即可能的回文串长度是否大于当前回文串的长度，不成立则转回步骤1，否则继续
//4)判断两个字符s[i]与s[j]之间所夹的字符串是否为回文串，不是则转回步骤2)，否则继续
//5)刷新start和end的值，转步骤1)
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char s[41];
	int i,j,start,end,k1,kr,length;
	cout<<"input a string:";
	gets(s);
	length=strlen(s);
	start=end=0;	//第1个字符是最短回文串，记忆其起止位置
	for(i=0;i<length;i++) //从左向右扫描各个字符
	{
		j=length-1;	//从最右端开始向左寻找与字符s[i]相同的字符
		while(j-i>end-start)
		{
			for(;j>=i;j--)
				if(s[j]==s[i]) break; //找到相同字符，退出
			if(j-i<=end-start) break; //可能的回文串长度不大于当前回文串长度，直接跳过
			for(k1=i,kr=j;k1<kr;k1++,kr--) //判断s[i]~s[j]能否构成回文
				if(s[k1]!=s[kr]) break;
				if(k1>=kr) //记忆新回文串的起止位置
				{
					start=i;
					end=j;
					break;
				}
			j--;	//不能构成回文串，回去继续扫描下一个配对的字符
		}
	}
	for(i=start;i<=end;i++)
		cout<<s[i];
	return 0;
}

//4-14.cpp 输出一行字符，统计单词数，单词间用空格分隔
//分析:
//1)利用gets()输入一行字符串，单词个数初始值num=0;
//2)














































































