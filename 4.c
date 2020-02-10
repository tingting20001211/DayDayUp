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

int CreateLink_L(PLNode L,int n)
{
// 创建含有n个元素的单链表
	PLNode p,q;
	int i;
	ElemType e;
	L=(PLNode)malloc(sizeof(LNode));
	if( L == NULL )
	{
		printf(" 1   分配内存失败！\n");
		return ERROR;
	}	
	L->next = NULL;              // 先建立一个带头结点的单链表
	q=L;

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
		printf("The PLNode is:");
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
	PLNode T = (PLNode)malloc(sizeof(LNode));
	int a,n,i;
	ElemType x, e;
	printf("Please input the init size of the linklist:\n");
	scanf("%d",&n);
	printf("Please input the %d element of the linklist:\n", n);
	if(CreateLink_L(T,n)==OK)     // 判断链表是否创建成功，请填空
	{
		printf("A Link List Has Created.\n");
		LoadLink_L(T);
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				if(LinkInsert_L(T,i,x)==ERROR)
				{
					printf("Insert Error!\n"); // 判断i值是否合法，请填空
				}
				else
				{
					printf("The Element %d is Successfully Inserted!\n", x);
				}	
				break;
			case 2: scanf("%d",&i);
				if(LinkDelete_L(T,i,&e)==ERROR)
				{
					printf("Delete Error!\n"); // 判断i值是否合法，请填空
				}
				else
				{
					printf("The Element %d is Successfully Deleted!\n", e);
				}
				break;
			case 3: LoadLink_L(T);
				break;
			case 0: return 1;
		}	
	}
}


/**
输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现插入操作，紧跟着要输入插入的位置和元素，用空格分开
2、输入2，表示要实现删除操作，紧跟着要输入删除的位置
3、输入3，表示要输出顺序表的所有元素
4、输入0，表示程序结束


输入样例
3
3 6 9
3
1
4 12
2
1
3
0


输出样例
Please input the init size of the linklist:
Please input the 3 element of the linklist:
A Link List Has Created.
The LinkList is:3 6 9 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:3 6 9 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 12 is Successfully Inserted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 3 is Successfully Deleted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:6 9 12 
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
**/
