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

/**
输入

输入数据只有一组，有很多行。每行的格式可能是下列一种：
insert a name
delete name
show
search name

其中 a 是一个整数，代表在第a个名字前插入名字。name是一个姓名，只包含英文字母的大小写，每个名字不超过30个字符。
输入保证不会插入列表中已经存在的姓名，不会删除列表中不存在的姓名，也不会搜索列表中不存在的姓名。

输出
起始时，列表是空的。只输出show和search name 的结果。show将列表中的姓名全部输出，search只输出找到该名字的序号（从1开始）。
每次输出占一行，姓名间用空格隔开。如果列表中没有名字了，show时也要输出一个空行。

样例输入
insert 1 Stuart
insert 2 Bernadette
show
search Stuart
delete Stuart
show
insert 2 Stuart
show
insert 1 Amy
insert 2 Leslie
insert 3 Stephanie
show
delete Leslie
show
search Stuart

样例输出
Stuart Bernadette
1
Bernadette
Bernadette Stuart
Amy Leslie Stephanie Bernadette Stuart
Amy Stephanie Bernadette Stuart
4

提示：
1、名字是不含空格的，指令也是一定的，所以可以用scanf(“%s”, str)来读取。

2、上述代码有些函数头中变量类型与变量之间有个&，这个表示该变量是引用类型的，是C++特性。
在C语言中存在值传递与指针传递，值传递中形参不可以改变实参的值，需要通过指针来修改。
而引用变量实际上就是实参的另一个名字，这种类型的形参改变会影响实参的值。

3、使用题目中的代码需要自己定义其中缺失的类型和变量，例如Status、OK以及Error等。

4、ElemType类型中可以只有一个字符数组用来存储姓名。

5、LocateElem_Sq函数在调用时需要传递一个函数指针，可以这样定义：

Status cmp(ElemType e1, ElemType e2);

注意这个函数用来判断e1和e2是否相等，如果相等则返回非零值，否则返回0。因此可以在这个函数里直接返回 !strcmp(…)但最好需要改变返回类型。

6、内存分配以及字符串操作需要的头文件分别是stdlib.h和string.h需要被包含进来。

7、题目要求每个输出占一行，所以要注意换行。

总结：
1、实际上，题目中几乎将主要代码都写出来了。解决这道题使用上面的代码是可能复杂了点，但将各个功能独立出来是个不错的思路。以后修改就方便了，特别适用于代码量较大的程序。

2、C语言中参数的传递分为值传递和指针传递，而C++中多了一个引用传递。值传递和指针传递都不可以改变传递进来的值，但指针可以改变其所指向的值。
在C语言中，调用函数时传入的参数叫做“实参”，而在函数声明或定义中在函数头中的参数叫做“形参”。
值传递与指针传递中，形参的改变是不影响实参的。C++中，引用传递，形参与实参实际上是同一个内容的不同名字，因而形参的变化会改变实参。
引用传递是C++中一个很重要也很方便的特性，比如在可能会产生不必要的复制时，采用引用传递是一个很不错的解决方案。
**/
