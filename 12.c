//行编辑程序

//利用栈编写简单的行编辑程序：接受用户从终端输入的程序或数据，在输入过程中，允许用户输入出差错，并在发现有误时可以及时更正。例如：当用户发现刚刚键入的一个字符是错的时，可以补进一个退格符“#”，以表示前一个字符无效；如果发现当前键入的行内差错较多或难以补救，则可以键入一个退行符“@”，以表示当前行中的字符均无效。例如：假设从终端接受了这样两行字符： whli##ilr#e (s#*s) outcha@putchar(*s=#++); 则实际有效的是下列两行： while (*s) putchar(*s++); 本题目给出部分函数，要求将行编辑函数补充完整，并完成整个程序。
typedef char SElemType;
#include"malloc.h" 
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
typedef struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack,*qSqStack; // 顺序栈

Status InitStack(qSqStack S)
{ // 构造一个空栈S
	S->base=(SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if(S->base==NULL)
	{
		printf("1. 分配内存失败 \n");
		return ERROR;
	}
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty(qSqStack S)
{ // 若栈S为空栈，则返回TRUE，否则返回FALSE
	if(S->top==S->base)
		return TRUE;
	else
		return FALSE;
}
Status ClearStack(qSqStack S)
{ // 把S置为空栈
	S->top=S->base;
	return OK;
}
Status DestroyStack(qSqStack S)
{ // 销毁栈S，S不再存在  

	/**** 对于销毁栈存在疑问，等待以后改正************/
	/*
	int i=0;
	SElemType *p=S->base;
	for(i=0;i<S->stacksize;i++)
	{
		p++;
		free(S->base);
		S->base=p;
	}
	*/

	free(S->base);
	S->base=NULL;
	S->top=NULL;
	S->stacksize=0;
	return OK;
}
Status Push(qSqStack S,SElemType e)
{ // 插入元素e为新的栈顶元素
	if(S->top-S->base>=S->stacksize)
	{
		//动态申请内存
		/*********等以后背会了栈的realloc函数，自己在写一遍********/


	}
	*(S->top)=e;
	S->top++;
	return OK;	
}
Status Pop(qSqStack S,SElemType *e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S->top==S->base)
	{
		printf("2. 栈为空 \n");
		return ERROR;
	}
	S->top--;
	*e=*(S->top);
	return OK;
}



Status StackTraverse(qSqStack S,Status(*visit)(SElemType))
{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()。
// 一旦visit()失败，则操作失败
	SElemType *p=S->base;
	while(S->top>p)
		visit(*(p++));
	printf("\n");
	return OK;
}

Status visit(SElemType c)
{
	printf("%c",c);
	return OK;
}


void LineEdit()
{ // 利用字符栈s，从终端接收一行并送至调用过程的数据区。算法3.2
	SqStack s;
	char ch,c;
	int n,i;
	InitStack(&s);
	scanf("%d",&n);
	ch=getchar();	//接收回车符??
	
	for(i=1;i<=n;i++)
	{
		ch=  getchar()   ;	//接收回车符??
		while(ch!='\n')
		{
			switch(ch)
			{
				case '#':Pop(&s,&c);
                  			break; // 仅当栈非空时退栈
         			case '@':ClearStack(&s);
                  			break; // 重置s为空栈
         			default :Push(&s,ch); // 有效字符进栈
       			}
     			scanf("%c",&ch); // 从终端接收下一个字符
     		}
     		StackTraverse(&s,visit); // 将从栈底到栈顶的栈内字符输出
 		ClearStack(&s);          // 重置s为空栈
    	}
   	DestroyStack(&s);
}
 void main()
 {
 	LineEdit(); 
 }


/*
输入格式
第一行：第一个字符为输入文本的行数n;
第二行至第n行：每行均为一串字符，其间可以含有“#”和“@”符号，以回车键结束本行的输入；


输出格式
输出第一至第n行的内容如下：
第一行：第一行从终端输入的有效字符。
第二行：第二行从终端输入的有效字符。
…… ……
第n行：第n行从终端输入的有效字符。


输入样例
2
defne##ine OK 1
typp cila@type int element


输出样例
define OK 1
type int element
*/
