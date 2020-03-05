#include <iostream>
using namespace std;

void mx(long long a,long long b)
{
	long long temp=1,a1=a,b1=b;
	while(temp!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	a=(a1*b1)/a;
	cout<<a<<endl;
}
int main()
{
	long long a,b,n=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		mx(a,b);
	}
	cout<<"group 1 done"<<endl;
	
	while(1)	
	{
		cin>>a>>b;
		if(a==0 && b==0)
			break;
		else
			mx(a,b);	
	}
	cout<<"group 2 done"<<endl;
	
	while(cin>>a>>b)
	{
		mx(a,b);
	}
	cout<<"group 3 done"<<endl;
	return 0;

}

//多case案例【此题用于求最大公倍数】
//1. 使用n来确定将要输入的数据数目
//2. 输入特定的数字或字符结束输入
//3. 单击CTRL+Z来结束输入
