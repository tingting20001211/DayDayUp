#include<malloc.h> 
#include<stdlib.h>
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

typedef struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack,*qSqStack;      // 顺序栈

Status InitStack(qSqStack S)       
{      
	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S->base=(SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(S->base==NULL)
	{
		printf("1. 内存分配失败\n");
		return ERROR;
	}
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;	 	
}

Status Push(qSqStack S,SElemType e)   
{// 在栈S中插入元素e为新的栈顶元素
	if(S->top - S->base >= STACK_INIT_SIZE)
	{
		//动态扩容
		printf("2. 栈已满，不能才存入数据了\n");	
		return ERROR;
	}

	*(S->top)=e;
	S->top++;
	return OK;	
}

Status Pop(qSqStack S,SElemType *e)   
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S->top == S->base)
	{
		printf("3. 栈为空\n");
		return ERROR;
	}

	S->top--;
	*e=*(S->top);
	return OK;	
}

Status GetTop(qSqStack S,SElemType *e)   
{ 
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S->top == S->base)
	{
		printf("4.  栈为空\n");
		return ERROR;
	}
	
	*e=*(S->top-1);
	return OK;	
}



int StackLength(qSqStack S) 
{
	//返回栈S的元素个数
	return S->top - S->base;
}

Status StackTraverse(qSqStack S)
{
	// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p; 
	p =  S->top;         //请填空
	if(p==S->base)
		printf("The Stack is Empty!"); //请填空
	else
	{	
		printf("The Stack is: ");
		p--;
		while(p >= S->base)            //请填空
		{
			printf("%d ", *p);
			p--;               //请填空
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int a;
	SqStack S;
	SElemType x, e;
	if(InitStack(&S)==OK)    // 判断顺序表是否创建成功，请填空
	{
		printf("A Stack Has Created.\n");
	}
	while(1)
	{	
		printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				if(Push(&S,x) == ERROR)
					printf("Push Error!\n"); // 判断Push是否合法，请填空
				else
					printf("The Element %d is Successfully Pushed!\n", x); 
				break;
			case 2: if(Pop(&S,&e) == ERROR)
					printf("Pop Error!\n"); // 判断Pop是否合法，请填空
				else
					printf("The Element %d is Successfully Poped!\n", e);
				break;
			case 3: if(GetTop(&S,&e) == ERROR)
					printf("Get Top Error!\n"); // 判断Get Top是否合法，请填空
				else
					printf("The Top Element is %d!\n", e);
				break;
			case 4: printf("The Length of the Stack is %d!\n",StackLength(&S)); 
				break;
			case 5: StackTraverse(&S);
				break;
			case 0: return 1;
		}		
	}
}


/*
输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现Push操作，紧跟着输入要Push的元素
2、输入2，表示要实现Pop操作
3、输入3，返回栈顶元素
4、输入4，返回栈的元素个数
5、输入5，表示从栈顶到栈底输出栈的所有元素
6、输入0，表示程序结束


输入样例
1
2
1
4
1
6
5
3
4
2
5
2
2
2
0


输出样例
A Stack Has Created.
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 2 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 4 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 6 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Stack is: 6 4 2 
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Top Element is 6!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Length of the Stack is 3!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 6 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Stack is: 4 2 
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 4 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 2 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
Pop Error!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
*/
