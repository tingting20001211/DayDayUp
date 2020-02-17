#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define list_init_size 100    //定义起始时最大人数
#define Elemtype name

typedef int Status;

typedef struct name_list
{
	char a[30];
}name,*pname;

typedef struct sqlist
{
	name *elem;    //每一个指向一个人
	int length;          //当前表中的实际人数
	int listsize;        //当前表中能存储的最大人数
}Sqlist,*qSqlist;


void init(qSqlist list);
void insert(qSqlist list,int pos,name people);
void delete(qSqlist list,name people);
void show(qSqlist list);
Status search(qSqlist list,name people);

void init(qSqlist list)
{
	list->elem=(pname)malloc(list_init_size*sizeof(name));
	list->length=0;
	list->listsize=list_init_size;
}

void show(qSqlist list)
{
	int i=0;
	for(i=0;i<list->length;i++)
	{
		printf("%s ",list->elem[i].a);
	}
	printf("\n");
}


Status search(qSqlist list,name people)
{
	pname p;
	int i=0;
	for(i=0;i<list->length;i++)
	{
		p=&(list->elem[i]);
		if(strcmp(people.a,p->a)==0)
		{
			//printf("%d",i+1);
			return i+1;
		}
	}
	return ERROR;
}

void insert(qSqlist list,int pos,name people)
{
//题目并没有说会输入错误的位置，所以我就默认他输入的是正确的位置
	if(search(list,people)==ERROR)   //如果不存在了
	{
		name *p;
		name *q=&(list->elem[pos-1]);   //q是将要插入的位置
		for(p=&list->elem[list->length-1];p>=q;p--)
		{
			strcpy((p+1)->a,(p->a));
		}
		strcpy((q->a),people.a);
		list->length++;
	}
}

void delete(qSqlist list ,name people)
{
	int i;
	if((i=search(list,people))!=ERROR)
	{
		name *p=&(list->elem[i-1]);   //将要被删除元素的位置
		name *q=&(list->elem[list->length-1]);

		for(++p;p<=q;++p)
		{
			strcpy((p-1)->a,(p->a));
		}
		list->length--;
	}
}

int main()
{
	char f1[]="insert";
	char f2[]="delete";
	char f3[]="show";
	char f4[]="search";
	Sqlist list;
	init(&list);
	char str[15];
	int pos;
	name people;
	while(~scanf("%s",str))
	{
		if(strcmp(f3,str)==0)
		{
			show(&list);
		}	
		if(strcmp(f1,str)==0)
		{
			scanf("%d",&pos);
			scanf("%s",people.a);
			insert(&list,pos,people);
		}
		if(strcmp(f2,str)==0)
		{
			scanf("%s",people.a);
			delete(&list,people);
		}
		if(strcmp(f4,str)==0)
		{
			scanf("%s",people.a);
			pos=search(&list,people);
			printf("%d\n",pos);
		}
	}
	return 0;
}
