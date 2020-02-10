#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*PLNode;

int CreateLink_L(PLNode *L,int n)
{
// 创建含有n个元素的单链表
	PLNode p,q;
	int i;
	ElemType e;
	(*L)=(PLNode)malloc(sizeof(LNode));
	if(*L==NULL)
	{
		printf("  1  分配内存失败\n");
		return ERROR;
	}

	(*L)->next = NULL;              // 先建立一个带头结点的单链表
	q=*L;

	for(i=0;i<n;i++)
	{
		scanf("%d", &e);
		if((p=(PLNode)malloc(sizeof(LNode)))==NULL)
		{
			printf("  2   分配内存失败！\n");
			return ERROR;
		}
		p->next=NULL;
		p->data=e;
		q->next=p;
		q=p;
  	}
	return OK;
}

int LoadLink_L(PLNode L)
{
	// 单链表遍历
	PLNode p = L->next;
	if(p==NULL)
	{
		printf("The List is empty!"); // 请填空
	}
	else
	{
		while(p!=NULL)    // 请填空
		{
			printf("%d ",p->data); 
			p=p->next;
		}
	}
	printf("\n");
	return OK;
}

int LinkInsert_L(PLNode L,int i,ElemType e)
{
// 算法2.9
// 在带头结点的单链线性表L中第i个位置之前插入元素e
// 请补全代码
	int j=0;
	PLNode p=L;
	while(p!=NULL && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p==NULL || j>i-1)
	{
		return ERROR;
	}
	PLNode pnew=NULL;
	if((pnew=(PLNode)malloc(sizeof(LNode)))==NULL)
	{
		printf("  3  内存分配失败\n");
		return ERROR;
	}
	pnew->data=e;
	pnew->next=NULL;

	pnew->next=p->next;
	p->next=pnew;
	p=pnew;
	return OK;
}

int LinkDelete_L(PLNode L,int i, ElemType *e){
// 算法2.10
// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
// 请补全代码
	int j=0;
	PLNode p=L;
	while(p->next!=NULL && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL || j>i-1)
	{
		printf(" 4 分配内存失败！\n");
		return ERROR;
	}
	PLNode free_node=p->next;
	*e=free_node->data;
	p->next=free_node->next;
	free(free_node);
	return OK;
}

int main()
{
	PLNode TA,TB;
	int nA,nB;
	scanf("%d",&nA);
	CreateLink_L(&TA,nA);	
	scanf("%d",&nB);
	CreateLink_L(&TB,nB);
	printf("List A:");
	LoadLink_L(TA);	
	printf("List B:");
	LoadLink_L(TB);	

	PLNode T=(PLNode)malloc(sizeof(LNode));
	T->next=NULL;

	int k=0,j=1;
	while(j<=nA+nB)
	{
		if(TA->next!=NULL && TB->next!=NULL)
		{
			if(TA->next->data<TB->next->data)
			{
				LinkDelete_L(TA,1,&k);
				LinkInsert_L(T,j,k);
			}
			else// if(TA->next->data>TB->next->data)
			{
				LinkDelete_L(TB,1,&k);
				LinkInsert_L(T,j,k);
			}

		}
		else if(TA->next==NULL && TB->next!=NULL)
		{
			LinkDelete_L(TB,1,&k);
			LinkInsert_L(T,j,k);
		}
		else if(TA->next!=NULL && TB->next==NULL)
		{
			LinkDelete_L(TA,1,&k);
			LinkInsert_L(T,j,k);
		}
		
		j++;
	}
	printf("List C:");
	LoadLink_L(T);
	return 0;
}
/**
设计一个算法将两个非递减有序链表A和B合并成一个新的非递减有序链表C。



输入格式
第一行：单链表A的元素个数
第二行：单链表A的各元素（非递减），用空格分开
第三行：单链表B的元素个数
第四行：单链表B的各元素（非递减），用空格分开


输出格式
第一行：单链表A的元素列表
第二行：单链表B的元素列表
第三行：合并后单链表C的元素列表


输入样例
6
12 24 45 62 84 96
4
15 31 75 86


输出样例
List A:12 24 45 62 84 96 
List B:15 31 75 86 
List C:12 15 24 31 45 62 75 84 86 96

**/
