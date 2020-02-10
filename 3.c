#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int 
typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList *L) 
{  // 算法2.3
  // 构造一个空的线性表L。
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L->elem)
	{
		return ERROR;        // 存储分配失败
	}
	L->length = 0;                  // 空表长度为0
	L->listsize = LIST_INIT_SIZE;   // 初始存储容量
	return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList *L, int i, ElemType e) 
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
	ElemType *p;
	if (i < 1 || i > L->length+1)
	{
		return ERROR;  // i值不合法
	}
	if (L->length >= L->listsize)
	{   // 当前存储空间已满，增加容量
		ElemType *newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof (ElemType));
		if(newbase==NULL)
		{
			return ERROR;   // 存储分配失败
		}
	L->elem = newbase;             // 新基址
	L->listsize += LISTINCREMENT;  // 增加存储容量
	}
	ElemType *q = &(L->elem[i-1]);   // q为插入位置
	for (p = &(L->elem[L->length-1]); p>=q; --p)
	{
		*(p+1) = *p;
	}	// 插入位置及之后的元素右移
	*q = e;       // 插入e
	++L->length;   // 表长增1
	return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList *L, int i, ElemType *e) 
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
  ElemType *p, *q;
  if (i<1 || i>L->length) 
  {
	  return ERROR;  // i值不合法
  }
  p = &(L->elem[i-1]);                   // p为被删除元素的位置
  *e = *p;                               // 被删除元素的值赋给e
  q = &(L->elem[L->length-1]);                // 表尾元素的位置
  for (++p; p<=q; ++p)
  {
	  *(p-1) = *p;     // 被删除元素之后的元素左移
  }
  --L->length;                           // 表长减1
  return OK;
} // ListDelete_Sq

Status List_inversion(SqList *L)
{
	int *p,*q;
	p=&(L->elem[0]);
	q=&(L->elem[L->length-1]);
	for(;p<q;p++,q--)
	{
		int temp=*p;
		*p=*q;
		*q=temp;
	}
	return OK;
}



int main()
{
	SqList L;
	InitList_Sq(&L);
	int n,i=0,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		ListInsert_Sq(&L,L.length+1,k); 
	}

	printf("The List is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",L.elem[i]);
	}
	
	List_inversion(&L);

	printf("\nThe turned List is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",L.elem[i]);
	}
	printf("\n");
	return 0;
}



/**
设有一顺序表A=（a0,a1,..., ai,...an-1)，其逆顺序表定义为A'=( an-1,..., ai,...,a1, a0)。设计一个算法，将顺序表逆置，要求顺序表仍占用原顺序表的空间。



输入格式
第一行：输入顺序表的元素个数
第二行：输入顺序表的各元素，用空格分开


输出格式
第一行：逆置前的顺序表元素列表
第二行：逆置后的顺序表元素列表


输入样例
10
1 2 3 4 5 6 7 8 9 10


输出样例
The List is:1 2 3 4 5 6 7 8 9 10 
The turned List is:10 9 8 7 6 5 4 3 2 1
*/
