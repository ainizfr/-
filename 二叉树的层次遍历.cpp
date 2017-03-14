#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define STACKINITSIZE 100  
#define STACKINCREASESIZE 20  
//数的定义
typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}bitnode, *bitree;
//队列的定义
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct {
	Queueptr front;//队头指针
	Queueptr rear;//队尾指针
}LinkQueue;
/*****************队列的操作定义********************/
//队列的构造
int  InitQueue(LinkQueue &q)

{
	q.front = q.rear = (Queueptr )malloc(sizeof( QNode));
	if (!q.front)
	{
		printf("申请地址失败");
		exit(1);
	}
	q.front->next = NULL;
	return 0;
}
//入队


/*****************队列操作定义********************/

/*****************树的操作定义********************/
void creat(bitree &p)
{
	char ch;
	ch = getchar();
	if (ch == '*')
		p = NULL;
	else
	{
		p = (bitnode *)malloc(sizeof(bitnode));
		if (!p)
		{
			exit(1);
		}
		p->data = ch;
		p->lchild = NULL;
		creat(p->lchild);
		p->rchild = NULL;
		creat(p->rchild);
	}
}

void PreOrder1(bitree t)
{
	bitree p = t;
	
}
/*****************树的操作定义********************/
int main()
{
	bitree a;
	printf("\n按先序序列输入结点序列，'*'代表空：");
	creat(a);
	printf("\n非递归层次遍历的结果：");
	PreOrder1(a);
	system("pause");
	return 0;
}