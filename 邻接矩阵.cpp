#include <stdio.h>
#include <stdlib.h>
#define INFINITY 20
typedef struct ArcCell {
	int vexnum, arcnum;//�������  �ߵĸ���
	int vexs[INFINITY];//��������
	int adj[INFINITY][INFINITY];//�ڽӾ���
}graph;
/*********************�Ҷ�Ӧ�±�*********************************/
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
/*******************************���������Ķ�*********************/
void sum(graph *g)
{
	int i, j, d = 0;
	for (i = 0; i<g->vexnum; i++)
	{
		int d = 0;
		for (j = 0; j<g->vexnum; j++)
			d += g->adj[i][j];
		printf("����%d�Ķ�Ϊ:%d\n", g->vexs[i], d);
	}
}
/*********************����ڽӾ���************************************/
void display(graph *g)
{
	int i, j;
	printf("���ڽӾ���Ϊ:\n");
	for (i = 0; i<g->vexnum; i++)
	{
		for (j = 0; j<g->vexnum; j++)
			printf("%d ", g->adj[i][j]);
		printf("\n");
	}
}
/***********************������**********************************/
int main()
{
	graph a;//��������ͼ
	int i=0, j=0,arc1,arc2,m,n;
	printf("���붥�����   �ߵĸ�����\n");
	scanf_s("%d %d", &a.vexnum, &a.arcnum);
	
	if (a.vexnum>INFINITY||a.arcnum>INFINITY)
	{
		printf("���볬����Χ\n");
		exit(0);
	}
	//���붥��
	for (; i < a.vexnum; i++)
	{
		printf("�����%d������", i+1);
		scanf_s("%d",&a.vexs[i]);
	}
	//��ʼ������
	for (i = 0; i < a.vexnum;i++)
	{
		for (j = 0; j < a.vexnum; j++)
		{
			a.adj[i][j] = 0;
		}
	}
	for (i = 0; i < a.arcnum;i++)
	{
		printf("�������%d���ߣ� arc1��arc2:\n",i+1);
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