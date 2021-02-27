#ifndef __AL_GRAPH_KRUSKAL_H__
#define __AL_GRAPH_KRUSKAL_H__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;				// ������ ��
	int numE;				// ������ ��
	List* adjList;			// ������ ����
	int* visitInfo;			// DFS ����� Ž���������� Ž���� �����(�鷶��) ������ ������ ��� ����
	PQueue pqueue;			// ������ ����ġ ���� ����
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

// ������ ���� ��� : Depth First Search ���
void DFSShowGraphVertex(ALGraph* pg, int startV);

// �ּ� ��� ���� Ʈ���� ����
void ConKruskalMST(ALGraph* pg);

// ����ġ ���� ���
void ShowGraphEdgeWeightInfo(ALGraph* pg);

#endif // !__AL_GRAPH_KRUSKAL_H__
