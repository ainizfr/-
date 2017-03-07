#include <stdio.h>
#include <stdlib.h>
#define INFINITY 20
typedef struct ArcCell {
	int vexnum, arcnum;//顶点个数  边的个数
	int vexs[INFINITY];//顶点名称
	int adj[INFINITY][INFINITY];//邻接矩阵
}graph;
/*********************找对应下标*********************************/
int locate(graph *a,int c)
{
	int i;
	for (i = 0; i < a->vexnum; i++)
		if (c == a->vexs[i])
		{
			return i;
		}
	return 0;
}
/*******************************计算各顶点的度*********************/
void sum(graph *g)
{
	int i, j, d = 0;
	for (i = 0; i<g->vexnum; i++)
	{
		int d = 0;
		for (j = 0; j<g->vexnum; j++)
			d += g->adj[i][j];
		printf("顶点%d的度为:%d\n", g->vexs[i], d);
	}
}
/*********************输出邻接矩阵************************************/
void display(graph *g)
{
	int i, j;
	printf("该邻接矩阵为:\n");
	for (i = 0; i<g->vexnum; i++)
	{
		for (j = 0; j<g->vexnum; j++)
			printf("%d ", g->adj[i][j]);
		printf("\n");
	}
}
/***********************主函数**********************************/
int main()
{
	graph a;//定义无向图
	int i=0, j=0,arc1,arc2,m,n;
	printf("输入顶点个数   边的个数：\n");
	scanf_s("%d %d", &a.vexnum, &a.arcnum);
	
	if (a.vexnum>INFINITY||a.arcnum>INFINITY)
	{
		printf("输入超出范围\n");
		exit(0);
	}
	//输入顶点
	for (; i < a.vexnum; i++)
	{
		printf("输入第%d个顶点", i+1);
		scanf_s("%d",&a.vexs[i]);
	}
	//初始化矩阵
	for (i = 0; i < a.vexnum;i++)
	{
		for (j = 0; j < a.vexnum; j++)
		{
			a.adj[i][j] = 0;
		}
	}
	for (i = 0; i < a.arcnum;i++)
	{
		printf("请输入第%d条边： arc1，arc2:\n",i+1);
		scanf_s("%d %d", &arc1, &arc2);
		m = locate(&a, arc1);
		n = locate(&a, arc2);
		a.adj[m][n] = 1;
		a.adj[n][m] = 1;
	}
	display(&a);
	sum(&a);
	system("pause");
	return 0;
}