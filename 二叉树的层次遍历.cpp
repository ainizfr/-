#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define STACKINITSIZE 100  
#define STACKINCREASESIZE 20  
//���Ķ���
typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}bitnode, *bitree;
//���еĶ���
typedef struct QNode {
	int data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct {
	Queueptr front;//��ͷָ��
	Queueptr rear;//��βָ��
}LinkQueue;
/*****************���еĲ�������********************/
//���еĹ���
int  InitQueue(LinkQueue &q)

{
	q.front = q.rear = (Queueptr )malloc(sizeof( QNode));
	if (!q.front)
	{
		printf("�����ַʧ��");
		exit(1);
	}
	q.front->next = NULL;
	return 0;
}
//���


/*****************���в�������********************/

/*****************���Ĳ�������********************/
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
/*****************���Ĳ�������********************/
int main()
{
	bitree a;
	printf("\n�������������������У�'*'����գ�");
	creat(a);
	printf("\n�ǵݹ��α����Ľ����");
	PreOrder1(a);
	system("pause");
	return 0;
}