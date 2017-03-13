#include <stdlib.h>
#include <stdio.h>
#define MAX_VERTEX_NUM 20
/*****************定义边的结构体******************/
typedef struct edgnode {
	int adjvex;//节点信息
	struct edgnode *next;//指向下一个节点
}edgnode;
/******************顶点结构体********************/
typedef struct vexnode {
	int data;//节点信息
	edgnode *firstarc;//第一个邻接点
}vexnode;
/*****************表示图的结构体****************/
typedef struct {
	int vexnum, arcnum;//定点和边的数量
	vexnode adj[MAX_VERTEX_NUM];//存放顶点
}graph;
/************找出对应下标(构造边)***************/
int locate(graph *a, int ch)
{
	for (int i = 0; i < a->arcnum; i++)
	{
		if (ch == a->adj[i].data)
			return i;
	}
	return 0;
}
/************判断输入是否超出范围***************/
void judge(graph *p)
{
	if (p->vexnum>MAX_VERTEX_NUM || p->arcnum>MAX_VERTEX_NUM)
	{
		printf("输入超出范围\n");
		exit(0);
	}
}
/***************构建单链表*********************/
int list(graph *l)
{
	int ch1, ch2;
	edgnode *pe;
	printf("输入顶点和边的数量\t");
	scanf_s("%d %d", &l->vexnum, &l->arcnum);
	judge(l);//判断是否超出范围
	printf("输入各顶点信息\t");
	for (int i = 0; i < l->vexnum; i++) 
	{
		scanf_s("%d",&l->adj[i].data);
		l->adj[i].firstarc = NULL;//将边表置为空表
	}
		/********************/
		for (int i = 0; i < l->arcnum; i++)
		{
			printf("输入边ch1,ch2:\t");
			scanf_s("%d %d", &ch1, &ch2);
			pe = (edgnode *)malloc(sizeof(edgnode));
			//采用表头插入节点
			/*****A是B的邻接点，B也是A的邻接点****/
			/*****分别申请2个内存空间****/
			pe->adjvex = locate(l,ch2);
			pe->next = l->adj[locate(l, ch1) ].firstarc;
			l->adj[locate(l, ch1)].firstarc = pe;

			pe = (edgnode *)malloc(sizeof(edgnode));
			pe->adjvex = locate(l, ch1);
			pe->next = l->adj[locate(l, ch2)].firstarc;
			l->adj[locate(l, ch2)].firstarc = pe;
		}
		return 0;
}
/************计算某个节点的度***********************/
void calculate(graph *a)
{
	int i,sum=0;
	edgnode *pe;
	printf("请输入要计算的节点：\t");
	scanf_s("%d", &i);
	pe = a->adj[locate(a, i)].firstarc;
	while (pe != NULL)
	{
		sum++;
		pe = pe->next;
	}
	printf("节点%d的度为%d\n",i, sum);
}
/******************主函数*********************/
int main()
{
	graph l;
	list(&l);
	calculate(&l);
	system("pause");
	return 0;
}