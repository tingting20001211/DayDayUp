#include<malloc.h> 
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
}SqStack,*qSqStack; // 顺序栈

Status InitStack(qSqStack S)       
{   
	//构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base)
		return ERROR;
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(qSqStack S,SElemType e)   
{   
	//在栈S中插入元素e为新的栈顶元素
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return ERROR;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top++;	
	return OK;
}

Status Pop(qSqStack S,SElemType *e)   
{   
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S->top==S->base)
		return ERROR;
	S->top--;
	*e=*(S->top);
	return OK;
}

Status GetTop(qSqStack S,SElemType *e)   
{    
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S->top==S->base)
		return ERROR;
	*e=*(S->top-1);
	return OK;
}

int StackLength(qSqStack S) 
{   
	//返回栈S的元素个数
	int i;
	i=S->top-S->base;
	return i;
}

Status StackTraverse(qSqStack S)
{
	// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p; 
	p = S->top;       
	if(S->top==S->base)
		printf("The Stack is Empty!");  
	else
	{	
		p--;
		while(p>=S->base)             
		{
			printf("%d", *p);
			p--;               
		}		
	}
	printf("\n");
	return OK;
}


int main()
{
	int n;
	scanf("%d",&n);
	SqStack Stack;
	InitStack(&Stack);
	while(n!=0)
	{
		Push(&Stack,n%8);
		n=n/8;
	}
	StackTraverse(&Stack);
	return 0;
}


/*
利用顺序栈的基本操作算法，编写满足下列要求的数制转换程序：对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数。



输入格式
第一行：输入一个非负的十进制整数


输出格式
第一行：与输入等值的八进制数


输入样例
15


输出样例
17
*/
