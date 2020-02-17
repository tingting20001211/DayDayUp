注意事项
================================

### 注意一
1. 如果单链表中的头指针已经有指向【非乱指状态】，并且在函数中不修改头指针的指向，则可以不需要二级指针，直接使用一级指针即可修改,**修改头指针**才需要用到**二级指针**。

#### 二级指针
```c
bool InitList(qNode *List,int n)
{
	qNode p,q;
	int i;
	ElemType e;
	(*List)=(qNode)malloc(sizeof(Node));//重新改了头的指向【需要用到二级指针】
	if(*List==NULL)
	{
		printf("1.分配内存失败\n");
		return false;
	}
	(*List)->next = NULL;    // 先建立一个带头结点的单链表
	q=*List;

	for(i=0;i<n;i++)
	{
		scanf("%d", &e);
		if((p=(qNode)malloc(sizeof(Node)))==NULL)
		{
			printf("2.分配内存失败！\n");
			return false;
		}
		p->next=NULL;
		p->data=e;
		q->next=p;
		q=p;
  	}
	return true;
}

int main(void)
{
	int n;
	...
	qNode List;			//无指向
	InitList(&List,n);
	......
}
```


#### 一级指针
```c
bool InitList(qNode List,int n)
{
	qNode p,q;
	int i;
	ElemType e;
	q=List;

	for(i=0;i<n;i++)
	{
		scanf("%d", &e);
		if((p=(qNode)malloc(sizeof(Node)))==NULL)
		{
			printf("2.分配内存失败！\n");
			return false;
		}
		p->next=NULL;
		p->data=e;
		q->next=p;
		q=p;
  	}
	return true;
}

int main(void)
{
	int n;
	...
	qNode List=(qNode)malloc(sizeof(Node));   //有指向
	if(List==NULL)
	{
		printf("1.分配内存失败！\n");
		return false;
	}
	List->next=NULL;
	InitList(List,n);
	......
}
```
### 注意二：

当题目中没有说到 **输入什么时候** 结束时：
```c
	while(~scanf("%d", &n));
	//以下二者效果相同
	while(scanf()!=EOF);
    while(~scanf());
```

> ~  是按位取反 

**scanf的返回值是输入值的个数**
若scanf()无输入其返回结果为  

```c
-1 --->  EOF
~(-1) == ~(EOF) == 0
```
