#include <iostream>
using namespace std;
//全局变量
int N;
int QueenPos[100];	//假设棋盘不超过100行
int m=0;		//m为可能的情况数目 1,2,3,4,...
int abs(int n)
{
	return n>0?n:-n;
}

void queen(int k)	//假设0,1,...,k-1,已经摆放好了，准备摆放第k个皇后
{
	int i=0;
	if(k==N)	//k==N时，说明最后一个皇后N-1已经摆放完毕
	{
		m++;
		cout<<endl<<"第"<<m<<"种情况"<<endl;
		for(i=0;i<N;i++)
			cout<<"第"<<i+1<<"行:"<<QueenPos[i]+1<<"\n";
		cout<<endl;
		return;		//!!!不要忘记return,之前忘记就错了	
	}

	for(i=0;i<N;i++)	//第k行皇后预计要放的位置
	{
		int j;
		for(j=0;j<k;j++)	//讲皇后预计要放的位置，与之前已经放好的0,1,...,k-1的皇后位置进行比较
		{
			if(i==QueenPos[j] || abs(k-j)==abs(i-QueenPos[j]))
			{
				break;	//第k皇后位置在第j皇后位置的正下方 or k,j皇后位置的横坐标与纵坐标之间的差值相等
			}
		}
		//最后比较完后，如果j==k，则说明并没有跳出循环，没有发生冲突
		if(j==k)
		{
			QueenPos[k]=i;
			queen(k+1);	//继续将k行以后的皇后经行比较
		}
	}
}

int main()
{
	cout<<"请输入有几个皇后："<<endl;
	cin>>N;	  //修改全局变量
	while(N>100 || N<1)
	{
		cout<<"请重新输入queen的个数[1,2,3,...,99,100]："<<endl;
		cin>>N;
	}
	queen(0);
	return 0;
}

