#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
	 int data;
	  struct LNode *next;
}LNode,*PLNode;


Status ListInsert_L(PLNode L, int i, ElemType e) { 
//	  在带头结点的单链线性表L的第i个元素之前插入元素e
	PLNode p,s;
	p = L;   
	int j = 0;
	while (p && j < i-1)\
	{  // 寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i-1)
		return ERROR;      // i小于1或者大于表长
	s = (PLNode)malloc(sizeof(LNode));  // 生成新结点
	s->data = e;
	s->next = p->next;      // 插入L中
	p->next = s;
	return OK;
} // LinstInsert_L

Status ListDelete_L(PLNode L, int i, ElemType *e) { 
//	   在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	PLNode p,q;
	p = L;
	int j = 0;
	while (p->next && j < i-1) 
	{  // 寻找第i个结点，并令p指向其前趋
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i-1)
		return ERROR;  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点
	*e = q->data;
	free(q);
	return OK;
} // ListDelete_L

void traverse(PLNode L)
{
	PLNode l=L->next;
	while(l!=NULL)
	{
		printf("%d ",l->data);
		l=l->next;
	}
	printf("\n");
}

Status Inversion(PLNode *L,int n)
{
	PLNode L2=(PLNode)malloc(sizeof(LNode));
	L2->next=NULL;

	int i=n,k=0,m=1;
	for(i=n,m=1;i>0 && m<=n;i--,m++)
	{
		ListDelete_L(*L,i,&k);
		ListInsert_L(L2,m,k);
	}
	(*L)=L2;
	return OK;
}


int main()
{
	PLNode L=(PLNode)malloc(sizeof(LNode));
	if(L==NULL)
	{
		printf("1. 分配内存失败\n");
		exit(-1);
	}
	L->next=NULL;
	int n;
	scanf("%d",&n);
	int i=1,k=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		ListInsert_L(L,i,k);
	}
	printf("The List is:");
	traverse(L);

	Inversion(&L,n);

	printf("The turned List is:");
	traverse(L);
	return 0;
}

/*
设有一线性表A=（a0,a1,..., ai,...an-1)，其逆线性表定义为A'=( an-1,..., ai,...,a1, a0)，设计一个算法，将线性表逆置，要求线性表仍占用原线性表的空间。



输入格式
第一行：输入n，表示单链表的元素个数
第二行：输入单链表的各元素，用空格分开


输出格式
第一行：输出单链表逆置前的元素列表
第二行：输出单链表逆置后的元素列表


输入样例
8
32 97 54 65 35 84 61 75


输出样例
The List is:32 97 54 65 35 84 61 75 
The turned List is:75 61 84 35 65 54 97 32
*/


