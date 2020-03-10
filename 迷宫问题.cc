#include <iostream>
#include <stdio.h>
using namespace std;
typedef int Status;
char migong[12][12];
typedef struct
{
	int x;
	int y;
	int di;
}direct;

const int MAX_SIZE = 100;
class Stack
{
	private:
		direct *pBase;
		int length;
		int top;
	public:	
		Stack();
		~Stack();
		Status Push(direct n);
		Status Pop(direct &e);
		bool isEmpty();
		bool isFull();
		int Length();
		void read();
};
Stack::Stack()
{
	pBase = new direct[MAX_SIZE];
	length = MAX_SIZE;
	top = 0;		//top指针指向还没有数据的内存空间
}
Stack::~Stack()
{
	delete []pBase;
}
Status Stack::Push(direct n)
{
	if(!isFull())
	{
		pBase[top++]=n;
		return true;
	}
	return false;
}
Status Stack::Pop(direct &e)
{
	if(!isEmpty())
	{
		e=pBase[--top];
		return true;
	}
	return false;
}
bool Stack::isEmpty()
{
	if(top==0)
		return true;
	else 
		return false; 
} 
bool Stack::isFull()
{
	if(top==length-1)
		return true;
	else 
		return false; 
}
int Stack::Length()
{
	return top;
}
void Stack::read()
{
	int i=0;
	while(i<top)
	{
		cout<<"x="<<pBase[i].x<<" y="<<pBase[i].y<<endl;
		i++;
	}
}

void initmap(direct &start,direct &end)
{
	for(int j=1;j<11;j++)
	{
		for(int i=1;i<12;i++)
		{
			scanf("%c",&migong[j][i]);		//cin>>migong[j][i];  
				//cin是不会接受空格和回车的，scanf即接受空格有接受回车
			if(migong[j][i]=='S')
			{
				start.x=j;start.y=i;start.di=-1;
			}
			else if(migong[j][i]=='E')
			{
				end.x=j;end.y=i;end.di=-1;
			}
		}
	}
}

void printMap()
{
	for(int j=1;j<11;j++)
	{
		for(int i=1;i<11;i++)
		{
			cout<<migong[j][i];
		}
		cout<<endl;
	}
}

Stack S;	//全局栈 
Status MapPath(direct start,direct end,direct dir[])
{
	int x,y,di;		//当前所在位置及方向
	int x2,y2;		//下一个将要走的位置 
	
	direct temp=start;
	S.Push(temp);

	while(!S.isEmpty())
	{
		//cout<<"asdasd"<<endl;
		S.Pop(temp);
		x=temp.x;	y=temp.y;	di=temp.di+1;
		//printMap();
		while(di<4)			//尝试每个方向 
		{
			x2=x+dir[di].x;
			y2=y+dir[di].y;
			if(migong[y2][x2]==' '||migong[y2][x2]=='E')		//有路 
			{
				temp.x=x;temp.y=y;temp.di=di;		//先把当前位置方向存储
				S.Push(temp);
				x=x2;    y=y2;
				migong[y][x]='*';
				if(x==end.x&&y==end.y)
				{
					migong[start.y][start.x]='*';
					migong[end.y][end.x]='*';
					return true;
				}
				di=0;	//到达新的位置，方向指向右边 
			}
			else
				di++;
		}
		migong[y][x]='!';
	}
	return false;
}

//		migong[y][x]='!';


int main()
{
	//初始化迷宫
	static direct dir[4];
	dir[0].x=1;dir[0].y=0;dir[0].di=0;	//right 
	dir[1].x=0;dir[1].y=1;dir[1].di=1;	//down
	dir[2].x=-1;dir[2].y=0;dir[2].di=2;	//left
	dir[3].x=0;dir[3].y=-1;dir[3].di=3;	//up
	
	direct start,end;
	initmap(start,end);
	MapPath(start,end,dir);
	printMap();
	//S.read();
	return 0;
}


/*
【样例输入】

##########
#S #   # #
#  #   # #
#    ##  #
# ###    #
#   #    #
# #   #  #
# ### ## #
##      E#
##########

【样例输出】
##########
#**#!!!# #
# *#!!!# #
#**!!##  #
#*###    #
#***#    #
# #***#  #
# ###*## #
##   ****#
##########

【样例说明】
*/
