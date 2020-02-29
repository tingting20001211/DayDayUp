#include <iostream>
using namespace std;

void hanoi(int n,char a,char b,char c)
{
	if(n==1)
	{
		cout<<a<<" --> "<<c<<endl;
	       return;
	}
	hanoi(n-1,a,c,b);
	cout<<a<<" --> "<<c<<endl; 
	hanoi(n-1,b,a,c);	
}


int main()
{
	cout<<"请输入有多少个圆盘："<<endl;
	int n;
	cin>>n;
	cout<<"请依次输入三个柱子的符号："<<endl;
	char a,b,c;
	cin>>a>>b>>c;
	hanoi(n,a,b,c);

	return 0;
}

