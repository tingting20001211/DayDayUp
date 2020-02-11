#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue,*qSqQueue;

Status InitQueue(qSqQueue Q)   
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
// 请补全代码
	Q->base=(QElemType *)malloc(sizeof(QElemType)*MAXQSIZE);
	if(Q->base==NULL)
	{
		printf("分配内存失败\n");
		return ERROR;
	}
	Q->front=0;
	Q->rear=0;
	return OK;
}

Status EnQueue(qSqQueue Q,QElemType e)  
{ 
// 插入元素e为Q的新的队尾元素
// 请补全代码
	if((Q->rear+1)%MAXQSIZE==Q->front)
	{
		printf("Queue is full\n");
		return ERROR;
	}	
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return OK;
}

Status DeQueue(qSqQueue Q, QElemType *e) 
{  
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
// 请补全代码
	if(Q->rear==Q->front)
	{
		printf("Queue is empty\n");
		return ERROR;
	}
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return OK;
}

Status GetHead(qSqQueue Q, QElemType *e)
{	
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
// 请补全代码
	if(Q->rear==Q->front)
	{
		return ERROR;
	}
	*e=Q->base[Q->front];
	return OK;
}

int QueueLength(qSqQueue Q)  
{
// 返回Q的元素个数
// 请补全代码
	int i=0;
	int flag=Q->front;
	while(flag!=Q->rear)
	{
		flag=(flag+1)%MAXQSIZE;
		i++;
	}
	return i;
}

Status QueueTraverse(qSqQueue Q)  
{ 
// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
	int i;
	i=Q->front;
	if(i==Q->rear)
		printf("The Queue is Empty!");  //请填空
	else
	{
		printf("The Queue is: ");
		while(i!=Q->rear)     //请填空
		{
			printf("%d ",Q->base[i] );   //请填空
			i = (i+1)%MAXQSIZE;   //请填空
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int a;
  	SqQueue S;
	QElemType x, e;
  	if(InitQueue(&S)==OK)    // 判断顺序表是否创建成功，请填空
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
		printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				if(EnQueue(&S,x)== ERROR)
					printf("Enter Error!\n"); // 判断入队是否合法，请填空
				else
					printf("The Element %d is Successfully Entered!\n", x); 
				break;
			case 2: if(DeQueue(&S,&e)==ERROR)
					printf("Delete Error!\n"); // 判断出队是否合法，请填空
				else
					printf("The Element %d is Successfully Deleted!\n", e);
				break;
			case 3: if(GetHead(&S,&e)==ERROR)
					printf("Get Head Error!\n"); // 判断Get Head是否合法
				else
					printf("The Head of the Queue is %d!\n", e);
				break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(&S));
				break;
			case 5: QueueTraverse(&S); //请填空
				break;
			case 0: return 1;
		}
	}
}

/*

输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现入队操作，紧跟着输入要入队的元素
2、输入2，表示要实现出队操作
3、输入3，返回队头元素
4、输入4，返回队列的元素个数
5、输入5，表示从队头到队尾输出队的所有元素
6、输入0，表示程序结束


输入样例
1
1
1
2
1
3
5
2
3
5
0


输出样例
A Queue Has Created.
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Element 1 is Successfully Entered!
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Element 2 is Successfully Entered!
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Element 3 is Successfully Entered!
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Queue is: 1 2 3 
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Element 1 is Successfully Deleted!
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Head of the Queue is 2!
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:
The Queue is: 2 3 
1:Enter 
2:Delete 
3:Get the Front 
4:Return the Length of the Queue
5:Load the Queue
0:Exit
Please choose:

*/
