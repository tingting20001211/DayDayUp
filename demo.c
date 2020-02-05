/*******************************
    解析typedef

typedef struct Data
{
    int num;
    char name[20];
}*data1,data2;

//解析:

//data1 <<==>> (struct Data *)

//data2 <<==>> (struct Data)

********************************/

/***连续存储***/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

typedef struct Student
{
    int *pBase;
    int len;
    int cnt;
}STU;

    void init_arr(STU *pstu,int length);   //初始化数组
    bool append_arr(STU *pstu,int val);
    bool insert_arr(STU *pstu,int pot,int value);    //pos从 1 开始，插在pos的前面【占据pos的位置】
    bool deleta_arr(STU *pstu,int index,int *pval);       //pVal为删除的元素的值，delete既希望返回删除成功与否，又希望返回删除的值
    int get(STU *pstu,int index);     //得到数组中某下标的值
    bool is_empty(STU *pstu);
    bool is_full(STU *pstu);
    void show_arr(STU *pstu);
    void Bubble_sort_arr(STU *pstu);
    void inversion_arr(STU *pstu);   //倒置数组



int main(void)
{
    STU stu;
    int val=0;
    int temp =0;
    init_arr(&stu,6);
    append_arr(&stu,1);
    append_arr(&stu,2);
    append_arr(&stu,3);
    append_arr(&stu,4);
    append_arr(&stu,4);
    show_arr(&stu);
    insert_arr(&stu,4,88);
    show_arr(&stu);
    Bubble_sort_arr(&stu);
    show_arr(&stu);
    inversion_arr(&stu);
    show_arr(&stu);
    return 0;
}

void init_arr(STU *pstu,int length)
{
    if((pstu->pBase=(int *)malloc(sizeof(STU)))==NULL)
    {
        printf("申请内存失败！\n");
        exit(-1);
    }
    else
    {
        pstu->len=length;
        pstu->cnt=0;
    }
}

bool is_empty(STU *pstu)
{
    if(pstu->cnt==0)
        return true;
    else
        return false;
}

bool is_full(STU *pstu)
{
    if(pstu->cnt==pstu->len)
        return true;
    else
        return false;
}

bool append_arr(STU *pstu,int val)
{
    if(is_full(pstu))
    {
        printf("该数组已满，不能在追加元素\n");
        return false;
    }
    else
    {
        pstu->pBase[pstu->cnt]=val;
        pstu->cnt++;
        return true;
    }
}

bool insert_arr(STU *pstu,int pot,int value)
{

    if(pstu->cnt==pstu->len)
    {
        printf("数组已满！\n");
        return false;
    }
    else if(pot<1||pot>pstu->cnt+1)
    {
        printf("请输入有效数字！\n");
        return false;
    }
    else
    {
        int i=0;
        for(i=pstu->cnt+1;i>=pot;i--)
        {
            pstu->pBase[i]=pstu->pBase[i-1];
        }
        pstu->pBase[pot-1]=value;
        pstu->cnt++;
        return true;
    }
}

void show_arr(STU *pstu)
{
    if(is_empty(pstu))
        printf("该数组为空！\n");
    else
    {
        int i=0;
        for(i=0;i<pstu->cnt;i++)
            printf("%d ",pstu->pBase[i]);
        printf("\n");
    }
}

int get(STU *pstu,int index)
{
    if(index<1||index>pstu->cnt)
        return false;
    else
    {
        printf("第%d的值为%d\n",index,pstu->pBase[index-1]);
        return pstu->pBase[index-1];
    }
}

bool deleta_arr(STU *pstu,int index,int *pval)
{
    if(is_empty(pstu))
    {
        printf("该数组为空！\n");
        return false;
    }
    else if(index<1||index>pstu->cnt)
    {
        printf("你要删除的数组下标不存在！\n");
        return false;
    }
    else
    {
        int i=0;
        pval=pstu->pBase[index-1];
        for(i=index;i<=pstu->cnt;i++)
        {
            pstu->pBase[i-1]=pstu->pBase[i];
        }
        pstu->cnt--;
        return true;
    }
}

void inversion_arr(STU *pstu)
{
    int i=0,j=0;
    int temp=0;
    for(i=0,j=pstu->cnt-1;i<j;i++,j--)
    {
        temp=pstu->pBase[i];
        pstu->pBase[i]=pstu->pBase[j];
        pstu->pBase[j]=temp;
    }
}

void Bubble_sort_arr(STU *pstu)
{
    int i=0,j=0;
    int temp=0;
    for(i=pstu->cnt-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(pstu->pBase[j]>pstu->pBase[j+1])
            {
                temp=pstu->pBase[j];
                pstu->pBase[j]=pstu->pBase[j+1];
                pstu->pBase[j+1]=temp;
            }
        }
    }
}


/***离散存储***/

//遍历
//查找
//清空
//销毁
//求长度
//排序
//删除节点
//插入节点
/**
 --> [ | ] --> [ | ] --> [ | ] --> [ |^]
       /\
       ||               q --> [ | ]
       p
//插入【q插在p后】
1. r=p->pNext;  q->pNext=r;   p->pNext=q;
2. q->pNext=p->pNext;  p->next=q;

//删除【删除p后的节点】
1. p->pNext=p->pNext->pNext; //存在内存泄漏
2. r=p->pNext;  p->pNext=r->pNext;  free(r);
**/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

typedef struct Node
{
    int data;                //数据域
    struct Node *pnext;     //指针域
}node,*pnode;

pnode create_list(void);
void traverse_list(pnode phead);
bool is_empty(pnode phead);
int length_list(pnode phead);
bool insert_list(pnode phead,int pos,int val);
bool delete_list(pnode phead,int pos,int *pval);
void sort_list(pnode phead);


int main()
{
    pnode phead=NULL;
    int value=0;
    phead = create_list();
    traverse_list(phead);
    sort_list(phead);
    traverse_list(phead);
    if(delete_list(phead,5,&value))
        printf("你所删除的值为%d\n",value);
    traverse_list(phead);


    return 0;
}

pnode create_list(void)
{
    pnode phead=NULL;
    phead=(pnode)malloc(sizeof(node));
    if(phead==NULL)
    {
        printf("分配内存失败！\n");
        exit(-1);
    }
    pnode ptail=phead;
    ptail->pnext=NULL;

    int len=0,i=0,value=0;
    printf("请输入你要创建的链表结点个数:");
    scanf("%d",&len);

    for(i=0;i<len;i++)
    {
        pnode pnew=(pnode)malloc(sizeof(node));
        if(pnew==NULL)
        {
            printf("分配内存失败！\n");
            exit(-1);
        }
        printf("请输入第%d个结点的数据:",i+1);
        scanf("%d",&value);

        pnew->data=value;
        ptail->pnext=pnew;
        ptail=pnew;
        ptail->pnext=NULL;
    }
    return phead;
}

void traverse_list(pnode phead)
{
    pnode p=phead->pnext;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->pnext;
    }
    printf("\n");
}

bool is_empty(pnode phead)
{
    if(phead->pnext==NULL)
        return true;
    else
        return false;
}

int length_list(pnode phead)
{
    pnode p=phead->pnext;
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->pnext;
    }
    return len;
}

bool insert_list(pnode phead,int pos,int val)
{
    int i=0;
    pnode pre=phead;
    while(pre!=NULL && i<pos-1)
    {
        pre=pre->pnext;
        i++;
    }
    if(i>pos-1 || pre==NULL)
        return false;
    pnode pnew=(pnode)malloc(sizeof(node));
    if(pnew==NULL)
    {
        printf("分配内存失败了！\n");
        exit(-1);
    }
    pnew->data=val;

    pnew->pnext=pre->pnext;
    pre->pnext=pnew;
    return true;
}

bool delete_list(pnode phead,int pos,int *pval)
{
    pnode pre=phead;
    int i=0;
    while(i<pos-1 && pre->pnext!=NULL)
    {
        pre=pre->pnext;
        ++i;
    }
    if(i>pos-1 || pre->pnext==NULL)
        return false;

    pnode del=pre->pnext;
    *pval=del->data;

    pre->pnext=pre->pnext->pnext;
    free(del);
    del=NULL;
    return true;
}

void sort_list(pnode phead)
{
    int i,j,temp=0;
    int len=length_list(phead);
    pnode p,q;
    for(i=0,p=phead->pnext;i<len-1;i++,p=p->pnext)
    {
        for(j=i+1,q=p->pnext;j<len;j++,q=q->pnext)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}


/***栈【stack】***/
//'先进后出'结构;
//静态变量是在 【栈】 中分配的
//动态变量是在 【堆】 中分配的

//应用 : 函数的调用\中断\表达式求值【后序表达式】\内存分配\缓冲处理\迷宫

//出栈
//压栈~入栈

//【动态栈】

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

typedef struct Node
{
    int data;                //数据域
    struct Node *pNext;     //指针域
}NODE,*PNODE;

typedef struct stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;

void init(PSTACK pS);
void push(PSTACK pS,int val);        //入栈
void traverse(PSTACK pS);
bool pop(PSTACK pS,int *pVal);      //出栈
void clear(PSTACK pS);            //清空

int main()
{
    STACK S;
    int val;

    init(&S);
    push(&S,7);
    push(&S,27);
    push(&S,29);

    push(&S,20);

    traverse(&S); //遍历

    pop(&S,&val);
    return 0;
}

void init(PSTACK pS)
{
    pS->pBottom=(PNODE)malloc(sizeof(NODE));
    if(pS->pBottom==NULL)
    {
        printf("分配失败!");
        exit(-1);
    }
    else
    {
        pS->pTop=pS->pBottom;
        pS->pBottom->pNext=NULL;//pS->pTop->pNext=NULL;
    }
}

void push(PSTACK pS,int val)
{
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    if(pNew==NULL)
    {
        printf("分配内存失败\n");
        exit(-1);
    }
    pNew->data=val;
    pNew->pNext=pS->pTop;
    pS->pTop=pNew;

}

void traverse(PSTACK pS)
{
    PNODE p=pS->pTop;

    while(p!=pS->pBottom)
    {
        printf("%d ",p->data);
        p=p->pNext;
    }
    printf("\n");
}

bool is_empty(PSTACK pS)
{
    if(pS->pBottom==pS->pTop)
        return true;
    else
        return false;
}

bool pop(PSTACK pS,int *pVal)
{
    if(is_empty(pS))
    {
        printf("栈已空！\n");
        return false;
    }
    else
    {
        PNODE ptemp = pS->pTop;
        pVal=ptemp->data;

        pS->pTop=ptemp->pNext;
        free(ptemp);
        ptemp=NULL;

        return true;
    }
}

void clear(PSTACK pS)
{
    if(is_empty(pS))
        return;
    else
    {
        PNODE p=pS->pTop;
        PNODE q=NULL;
        while(p!=pS->pBottom)
        {
            q=p->pNext;
            free(p);
            p=q;
        }
        pS->pTop=pS->pBottom;
    }
    PNODE p=pS->pTop,q=p;
    while(p!=pS->pBottom)
    {
        p=p->pNext;
        free(q);
        q=p;
    }
}

//【静态栈】

//【自己用数组实现】


/***队列***/

//'先进先出'
//【链式队列】front rear
//【静态队列】--[循环队列]
//应用：凡是所有与 时间 有关的操作都与队列有关


//【静态队列】--[循环队列]
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

typedef struct Queue
{
    int *pBase;                //数据域
    int front;
    int rear;
    int len;
}QUEUE;

void init(QUEUE *pQ);
bool en_queue(QUEUE *pQ,int val);
void traverse_queue(QUEUE *pQ);
bool is_full_queue(QUEUE *pQ);
bool out_queue(QUEUE *pQ,int *pVal);
bool is_empty_queue(QUEUE *pQ);

int main()
{
    QUEUE Q;
    int value=0;
    init(&Q);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    en_queue(&Q,1);
    traverse_queue(&Q);
    out_queue(&Q,&value);
    return 0;
}

void init(QUEUE *pQ)
{
    int len;
    printf("请输入队列的长度：");
    scanf("%d",&len);
    len++;  //队列中存放len个元素

    pQ->pBase=(int *)malloc(sizeof(int)*len);
    pQ->front=0;
    pQ->rear=0;
    pQ->len=len;
}

bool en_queue(QUEUE *pQ,int val)
{
    if(is_full_queue(pQ))
    {
        printf("队列已满！\n");
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear]=val;
        pQ->rear=(pQ->rear+1)%(pQ->len);
        return true;
    }
}

void traverse_queue(QUEUE *pQ)
{
    int i=pQ->front;
    if(i==pQ->rear)
    {
        printf("该队列为空!\n");
    }

    while(i!=pQ->rear)
    {
        printf("%d ",pQ->pBase[i]);
        i=(i+1)%(pQ->len);
    }
}

bool is_full_queue(QUEUE *pQ)
{
    if(((pQ->rear+1)%(pQ->len))==pQ->front)
        return true;
    else
        return false;
}

bool out_queue(QUEUE *pQ,int *pVal)
{
    if(is_empty_queue(pQ))
    {
        printf("该队列为空！\n");
        return false;
    }
    else
    {
        pVal=pQ->pBase[pQ->front];
        pQ->front=(pQ->front+1)%(pQ->len);
        return true;
    }
}

bool is_empty_queue(QUEUE *pQ)
{
    if(pQ->front==pQ->rear)
        return true;
    else
        return false;
}

//【链式队列】

//【自己用数组实现】


/*****递归*****/

//一个函数自己直接或者间接调用自己---------栈




/*****树*****/

//满二叉树：在不增加树的层数的前提下，无法在多添加一个节点的二叉树就是满二叉树
//完全二叉树：如果只是删除了满二叉树【最底层】【最右边】的【连续】若干个节点，这样形成的二叉树就是完全二叉树



//树的存储
//      连续存储[数组]--【完全二叉树】
//              查找某个节点的父节点和子节点（也包括判断有没有子节点）速度很快
//              耗用内存空间过大
//      链式存储[链式]
//              耗用内存较小
//
//一般树的存储
//        双亲表示法
//        孩子表示法
//        双亲孩子表示法
//        二叉树表示法:设法保证任意一个节点的
//                       左指针指向它的第一个孩子
//     【森林的存储】    右指针指向它的下一个兄弟

二叉树的遍历：

先序遍历
    if pnode != NULL
        访问根节点
        先序访问左子树
        先序访问右子树

中序遍历
    if pnode != NULL
        中序访问左子树
        访问根节点
        中序访问右子树


后序遍历
    if pnode != NULL
        后序访问左子树
        后序访问右子树
        访问根节点

已知两种遍历序列求原始二叉树




# include <stdio.h>
# include <malloc.h>

struct BTNode
{
	char data;
	struct BTNode * pLchild; //p是指针 L是左  child是孩子
	struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PreTraverseTree(struct BTNode *pT);
void InTraverseTree(struct BTNode *pT);
void PostTraverseTree(struct BTNode *pT);

int main()
{
    struct BTNode *pT = CreateBTree();

    PreTraverseTree(pT);
    printf("\n");
    InTraverseTree(pT);
    printf("\n");
    PostTraverseTree(pT);
}
//静态创建二叉树
struct BTNode * CreateBTree(void)
{
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}
//先序
void PreTraverseTree(struct BTNode *pT)
{
    if(pT != NULL)
    {
        printf("%c ",pT->data);

        if(pT->pLchild != NULL)
            PreTraverseTree(pT->pLchild);

        if(pT->pRchild != NULL)
            PreTraverseTree(pT->pRchild);
    }

}
//中序
void InTraverseTree(struct BTNode *pT)
{
    if(pT != NULL)
    {
        if(pT->pLchild != NULL)
            InTraverseTree(pT->pLchild);

        printf("%c ",pT->data);

        if(pT->pRchild != NULL)
            InTraverseTree(pT->pRchild);
    }

}
//后序
void PostTraverseTree(struct BTNode *pT)
{
    if(pT != NULL)
    {
        if(pT->pLchild != NULL)
            PostTraverseTree(pT->pLchild);

        if(pT->pRchild != NULL)
            PostTraverseTree(pT->pRchild);

        printf("%c ",pT->data);
    }

}


/***Binary_Search_Tree***/
//二叉搜索树，改树特征：左节点 < 根节点 < 右节点    [中序遍历 --> 排序的数字]

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE
{
    int data;
    struct NODE * left;
    struct NODE * right;
}Node;

typedef struct TREE
{
    Node *root;
}Tree;

void insert_tree(Tree *tree,int value)
{
    //创建一个新节点
    Node *tree_new = (Node *)malloc(sizeof(Node));
    tree_new->data=value;
    tree_new->left=NULL;
    tree_new->right=NULL;

    if(tree->root==NULL)
        tree->root=tree_new;
    else
    {
        Node *temp = tree->root;
        while(temp!=NULL)
        {
            if(value<temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=tree_new;
                    return;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=tree_new;
                    return;
                }
                else
                    temp=temp->right;
            }
        }
    }
}

int deep_tree(Node *node)
{
    if(node==NULL)
        return 0;
    else
    {
        int ml,mr;
        ml=deep_tree(node->left);
        mr=deep_tree(node->right);
        return ml>mr?ml+1:mr+1;
    }
}

int max_tree(Node *node)
{
    if(node==NULL)
    {
        return -1;
    }
    else
    {
        int m,ml,mr;
        m=node->data;
        ml=max_tree(node->left);
        mr=max_tree(node->right);
        int max=m;
        if(ml>max&&ml>mr)
            return ml;
        else if(mr>max&&mr>ml)
            return mr;
        else
            return m;
    }

}

void inorder(Node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

void preorder(Node *node)
{
    if(node!=NULL)
    {
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}


int main()
{
    int a[10]={5,6,9,7,1,2,10,4,8,3};
    //int a[7]={6,3,8,2,5,1,7};
    int i=0,h=0,max=0;
    Tree tree;
    tree.root=NULL;

    for(i=0;i<7;i++)
    {
        insert_tree(&tree,a[i]);
    }
    inorder(tree.root);
    printf("\n");
    preorder(tree.root);
    h=deep_tree(tree.root);
    printf("\n%d\n",h);

    max=max_tree(tree.root);
    printf("\nmax == %d",max);
    return 0;
}

//heap 
//【堆】 与 【堆排序】

#include <stdio.h>
#include <stdlib.h>

void swap(int tree[],int x,int y)
{
    int temp=tree[y];
    tree[y]=tree[x];
    tree[x]=temp;
}

//n是总共多少个结点，i代表要构造堆的下标
void heapify(int tree[],int n,int i)
{
    if(i>=n)
        return ;
    int max=i;
    int m1=2*i+1,m2=2*i+2;
    if(m1<n && tree[max]<tree[m1])
        max=m1;
    if(m2<n && tree[max]<tree[m2])
        max=m2;

    if(max!=i)
    {
        swap(tree,max,i);
        heapify(tree,n,max);
    }
}

void build_heap_tree(int tree[],int n)
{
    int last_node=n-1,i=0;
    int last_node_parent=(last_node-1)/2;
    for(i=last_node_parent;i>=0;i--)
        heapify(tree,n,i);

}

void heap_sort(int tree[],int n)
{
    build_heap_tree(tree,n);
    int i=0;
    for(i=n-1;i>=0;i--)
    {
        swap(tree,0,i);
        //build_heap_tree(tree,i);//可以直接使用heapify(int tree[],int n,int i)函数，应为只有最顶端的堆是乱的
        heapify(tree,i,0);
    }
}

int main()
{
    int tree[]={2,5,3,1,10,4};
    int n=6;
    heap_sort(tree,n);
    int i;
    for(i=0;i<n;i++)
        printf("%d ",tree[i]);
    return 0;
}




//动态创建二叉树
/**#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//定义二叉树的链表储蓄结构
typedef int TElemType;
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode *lchild;
  struct BiTNode *rchild;
}*BiTree;

//令队列的每一个元素为BiTree类型
typedef BiTree QElemType;


/**
    1.形参是个指向结构体变量的指针的指针
    2.我们假定输入0表示该节点为空
    3.我们是以先序的顺序来创建二叉树的，
    但问题是无论是哪种排序都无法唯一确定该二叉树，
    解决办法是创建一些结点为空的值 也以先序或是中序又
    或是后序的顺序来输入，以唯一确定该二叉树

*/
/**
void CreateBiTree(BiTree t)
{
    int temp;
    scanf("%d",&temp);

    if(temp)
    {//如果temp非0的话，我们为其分配储存空间
        t=(BiTree)malloc(sizeof(struct BiTNode));
        if(!t)//如果分配失败
        {
            exit(-1);
        }
        t->data=temp;
        CreateBiTree(&(t->lchild));
        CreateBiTree(&(t->rchild));
    }
    else
        t=NULL;
}

int main()
{
    struct BiTNode root;
    CreateBiTree(&root);

    return 0;
}
**/



/***快速排序***/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int FindPos(int *a,int low,int high);
void QuickSort(int *a,int low,int high);

int main()
{
    int a[6]={5,6,1,8,4,3};
    int i=0;

    QuickSort(a,0,5);  //

    for(i=0;i<6;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void QuickSort(int *a,int low,int high)
{
    int pos=0;
    if(low<high)
    {
        pos = FindPos(a,low,high);
        QuickSort(a,low,pos-1);
        QuickSort(a,pos+1,high);
    }
}

int FindPos(int *a,int low,int high)
{
    int val = a[low];

    while(low<high)
    {
        while(low<high && a[high]>=val)
        {
            --high;
        }
        a[low] = a[high];
        while(low<high && a[low]<=val)
        {
            ++low;
        }
        a[high] = a[low];
    }
    //low==high
    a[low]=val;
    return low;
}









































//********************************************1******************************************************//

# include <stdio.h>
# include <malloc.h>  //包含了malloc函数
# include <stdlib.h>  //包含了exit函数


#define bool int
#define true 1
#define false 0
//定义了一个数据类型，该数据类型的名字叫做struct Arr, 该数据类型含有三个成员，分别是pBase, len, cnt
struct Arr
{
	int * pBase; //存储的是数组第一个元素的地址
	int len; //数组所能容纳的最大元素的个数
	int cnt; //当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length);  //分号不能省
bool append_arr(struct Arr * pArr, int val); //追加
bool insert_arr(struct Arr * pArr, int pos, int val); // pos的值从1开始
bool delete_arr(struct Arr * pArr, int pos, int * pVal);
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);

int main(void)
{
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 10);
	append_arr(&arr, -3);
	append_arr(&arr, 6);
	append_arr(&arr, 88);
	append_arr(&arr, 11);
	if ( delete_arr(&arr, 4, &val) )
	{
		printf("删除成功!\n");
		printf("您删除的元素是: %d\n", val);
	}
	else
	{
		printf("删除失败!\n");
	}
//	append_arr(&arr, 2);
//	append_arr(&arr, 3);
//	append_arr(&arr, 4);
//	append_arr(&arr, 5);
//	insert_arr(&arr, -1, 99);
//	append_arr(&arr, 6);
//	append_arr(&arr, 7);
//	if ( append_arr(&arr, 8) )
//	{
//		printf("追加成功\n");
//	}
//	else
//	{
//		printf("追加失败!\n");
//	}

	show_arr(&arr);
	inversion_arr(&arr);
	printf("倒置之后的数组内容是:\n");
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);

	//printf("%d\n", arr.len);

	return 0;
}

void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败!\n");
		exit(-1); //终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr * pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr * pArr)
{
	if ( is_empty(pArr) )
	{
		printf("数组为空!\n");
	}
	else
	{
		for (int i=0; i<pArr->cnt; ++i)
			printf("%d  ", pArr->pBase[i]); //int *
		printf("\n");
	}
}

bool append_arr(struct Arr * pArr, int val)
{
	//满是返回false
	if ( is_full(pArr) )
		return false;

	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	int i;

	if (is_full(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt+1)  //
		return false;

	for (i=pArr->cnt-1; i>=pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	(pArr->cnt)++;
	return true;
}

bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
	int i;

	if ( is_empty(pArr) )
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos-1];
	for (i=pos; i<pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for (i=0; i<pArr->cnt; ++i)
	{
		for (j=i+1; j<pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}


//*********************************************************2*********************************************************//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

typedef struct Node
{
    int data;               //数据域
    struct Node *pNext;     //指针域
}NODE , *PNODE;     //struct Node <==> NODE  /  (struct Node *) <==> PNODE

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead,int pos ,int val);
bool delete_list(PNODE pHead,int pos ,int *pval);
void sort_list(PNODE pHead);


int main(void)
{
    int val;
    PNODE pHead = NULL;

    pHead  = create_list();
    traverse_list(pHead);       //遍历
    sort_list(pHead);
    traverse_list(pHead);

    return 0;
}

PNODE create_list(void)
{
    int len=0;
    int i=0;
    int val=0;

    //分配了一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead == NULL)
    {
        printf("分配内存失败！");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入要创建的链表节点的个数:");
    scanf("%d",&len);

    for(i=0;i<len;i++)
    {
        printf("请输入第%d个节点的数据:",i+1);
        scanf("%d",&val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("分配内存失败！");
            exit(-1);
        }
        pNew->data=val;

        pTail->pNext=pNew;
        pNew->pNext=NULL;
        pTail=pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;     //此处已经考虑到了p没有有效数据，p仅有一个不存放有效数据的头结点，其next刚好为NULL

    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead)
{
    if(pHead->pNext==NULL)
        return true;
    else
        return false;
}

int length_list(PNODE pHead)
{
    int len=0;
    PNODE p=pHead->pNext;
    while(p!=NULL)
    {
        len++;
        p=p->pNext;
    }
    return len;
}

//在pos结点的前面插入一个新的结点,并pos是从1开始【占据pos的结点】
bool insert_list(PNODE pHead,int pos,int val)
{
    int i=0;
    PNODE p=pHead;

    while(p!=NULL && i<pos-1)
    {
        p=p->pNext;
        ++i;
    }
    if(i>pos-1 || p==NULL)
        return false;

    //此时pos已经指向了pos的前一个结点

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(pNew == NULL)
    {
        printf("分配内存失败！");
        exit(-1);
    }
    pNew->data=val;

    PNODE q=p->pNext;
    p->pNext=pNew;
    pNew->pNext=q;

    return true;
}

bool delete_list(PNODE pHead,int pos,int *pVal)
{
    int i=0;
    PNODE p=pHead;

    while(p->pNext!=NULL && i<pos-1)
    {
        p=p->pNext;
        ++i;
    }
    if(i>pos-1 || p->pNext==NULL)
        return false;

    //此时pos已经指向了pos的前一个结点

    PNODE q=p->pNext;
    *pVal=q->data;

    //删除p结点后面的结点
    p->pNext=p->pNext->pNext;
    free(q);
    q=NULL;

    return true;

}

void sort_list(PNODE pHead)
{
    int i,j,temp;
    int len = length_list(pHead);
    PNODE p,q;
    for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
    {
        for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}
