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
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S->base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base)
		return ERROR;
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(qSqStack S,SElemType e)   
{   
// 在栈S中插入元素e为新的栈顶元素
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return ERROR;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top+;
	return OK;
}

Status Pop(qSqStack S,SElemType *e)   
{   
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S->top==S->ase)
		return ERROR;
     	S->top--;
	*e=*(S->top);
	return OK;
}

Status GetTop(qSqStack S,SElemType e)   
{    
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S->top==S->base)
		return ERROR;
	e=*(S->top-1);
	return OK;
}

int StackLength(qSqStack S) 
{   
// 返回栈S的元素个数
	int i;
	i=S->top-S->base;
	return i;
}

Status StackTraverse(qSqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
	p = S->top;       
	if(S->top==S->base)
		printf("The Stack is Empty!");  
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S->base)             
		{
			printf("%d ", *p);
			p--;               
		}
	}
	printf("\n");
	return OK;
}



int main()
{
	char receive,s_num[81];
	int k=0;
	SqStack s_symbol;

	if(InitStack(&s_symbol)==ERROR)
	{
		printf("1. 分配内存失败\n");
		exit(-1);
	}
	char a[81];
	scanf("%s",&a);
	char *p=a;
	while(*p!='=')
	{
		if(*p=='(')
		{
			Push(&s_symbol,*p);
		}
		else if(*p==')')
		{
			receive='#';
			while(receive!='(')
			{
				Pop(&s_symbol,&receive);
				s_sum[k]=receive;
				k++;
			}
			Pop(&s_symbol,&receive);
		}
		else if(*p<='9'&&*p>='0')
		{	//暂且先考虑一位数字
			s_num[k]=*p;
			k++;
		}
		else
		{
			if(*p=='*' || *p=='/')
			{
				

			if(*p=='+' && )



	}
	while(StackLength(&s_symbol)!=0)
	{
		Pop(&s_symbol,&receive);
		s_num[k]=receive;
		k++;
	}




	return 0;
}
/*
利用栈编写表达式求值程序：输入含有“+”、“-”、“*”、“/”四则运算的表达式，其中负数要用（0-正数）表示，并以=结束。要求输出表达式的值（两运算符号的优先关系见教材表3.1）。



输入格式
第一行：一个算术表达式


输出格式
第一行：算术表达式的值


输入样例
3*(9-7)=


输出样例
6
*/
