#include <stdlib.h>
#include <stdio.h>
#define MAX_VERTEX_NUM 20
/*****************����ߵĽṹ��******************/
typedef struct edgnode {
	int adjvex;//�ڵ���Ϣ
	struct edgnode *next;//ָ����һ���ڵ�
}edgnode;
/******************����ṹ��********************/
typedef struct vexnode {
	int data;//�ڵ���Ϣ
	edgnode *firstarc;//��һ���ڽӵ�
}vexnode;
/*****************��ʾͼ�Ľṹ��****************/
typedef struct {
	int vexnum, arcnum;//����ͱߵ�����
	vexnode adj[MAX_VERTEX_NUM];//��Ŷ���
}graph;
/************�ҳ���Ӧ�±�(�����)***************/
int locate(graph *a, int ch)
{
	for (int i = 0; i < a->arcnum; i++)
	{
		if (ch == a->adj[i].data)
			return i;
	}
	return 0;
}
/************�ж������Ƿ񳬳���Χ***************/
void judge(graph *p)
{
	if (p->vexnum>MAX_VERTEX_NUM || p->arcnum>MAX_VERTEX_NUM)
	{
		printf("���볬����Χ\n");
		exit(0);
	}
}
/***************����������*********************/
int list(graph *l)
{
	int ch1, ch2;
	edgnode *pe;
	printf("���붥��ͱߵ�����\t");
	scanf_s("%d %d", &l->vexnum, &l->arcnum);
	judge(l);//�ж��Ƿ񳬳���Χ
	printf("�����������Ϣ\t");
	for (int i = 0; i < l->vexnum; i++) 
	{
		scanf_s("%d",&l->adj[i].data);
		l->adj[i].firstarc = NULL;//���߱���Ϊ�ձ�
	}
		/********************/
		for (int i = 0; i < l->arcnum; i++)
		{
			printf("�����ch1,ch2:\t");
			scanf_s("%d %d", &ch1, &ch2);
			pe = (edgnode *)malloc(sizeof(edgnode));
			//���ñ�ͷ����ڵ�
			/*****A��B���ڽӵ㣬BҲ��A���ڽӵ�****/
			/*****�ֱ�����2���ڴ�ռ�****/
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
/************����ĳ���ڵ�Ķ�***********************/
void calculate(graph *a)
{
	int i,sum=0;
	edgnode *pe;
	printf("������Ҫ����Ľڵ㣺\t");
	scanf_s("%d", &i);
	pe = a->adj[locate(a, i)].firstarc;
	while (pe != NULL)
	{
		sum++;
		pe = pe->next;
	}
	printf("�ڵ�%d�Ķ�Ϊ%d\n",i, sum);
}
/******************������*********************/
int main()
{
	graph l;
	list(&l);
	calculate(&l);
	system("pause");
	return 0;
}