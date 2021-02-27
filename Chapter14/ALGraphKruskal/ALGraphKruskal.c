#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

void GraphInit(ALGraph* pg, int nv)
{
	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List) * nv);		// ���������� ������ ����Ʈ ����
	pg->numV = nv;		// ������ ���� nv�� ����� ������ ����
	pg->numE = 0;		// �ʱ��� ���� ���� 0��

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);		// ���ĺ� ������ ����� �����ϱ� ���� ��, �߿����� ����
	}

	// ������ ���� ���̷� �Ͽ� �迭�� �Ҵ�
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	// �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	// �켱���� ť�� �ʱ�ȭ
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
	{
		free(pg->adjList);
	}

	// �Ҵ�� �迭�� �Ҹ�
	if (pg->visitInfo != NULL)
	{
		free(pg->visitInfo);
	}
}

void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// ������ ����ġ ������ �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), edge);
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// ���� ������ ���� �Ҹ�
void RemoveWayEdge(ALGraph* pg, int fromV, int toV)
{
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RemoveEdge(ALGraph* pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
			{
				printf("%c ", vx + 65);
			}
		}
		printf("\n");
	}
}

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	PQueue copyPriorityQueue = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPriorityQueue))
	{
		edge = PDequeue(&copyPriorityQueue);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)		// visitV�� ó�� �湮�� ��
	{
		pg->visitInfo[visitV] = 1;		// visitV�� �湮�� ������ ���
		// printf("%c ", visitV + 65);		// �湮�� ������ �̸��� ���
		return TRUE;
	}

	return FALSE;
}

void DFSShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);		// ���� ������ �湮
	SPush(&stack, visitV);			// ���� ������ ������ ��������

	// visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while ��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitV �� ����� ������ ������ nextV �� ��� ���¿��� ���ϸ� ����
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)		// �湮�� �����ߴٸ�,
		{
			SPush(&stack, visitV);		// visitV �� ��� ������ ������ PUSH
			visitV = nextV;
			visitFlag = TRUE;
		}
		else    // �湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�.
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)		// �߰��� �湮�� ������ �����ٸ�
		{
			// ������ ��� Ž���� ���������� �ǵ��� �� ��
			if (SIsEmpty(&stack) == TRUE)
			{
				break;
			}
			else
			{
				visitV = SPop(&stack);		// ���� �ǵ��� ����.
			}
		}
	}

	// ������ Ž���� ���ؼ� Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// ���ڷ� ���޵� �� ������ ����Ǿ� �ִٸ� TRUE, �׷��� �ʴٸ� FALSE ��ȯ
int IsConnVertex(ALGraph* pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		// ������ ���ƴٴϴ� ���߿� ��ǥ�� ã�Ҵٸ� TRUE �� ��ȯ�Ѵ�.
		if (nextV == v2)
		{
			// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�.
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				// ������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE �� ��ȯ�Ѵ�.
				if (nextV == v2)
				{
					// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�.
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
			{
				break;
			}
			else
			{
				visitV = SPop(&stack);
			}
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;		// ��ǥ�� ã�� ���ߴ�.
}

void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20];		// ������ ������ ���� ����
	Edge edge;
	int edgeIndex = 0;

	// MST �� ������ ������ �Ʒ��� while ���� �ݺ�
	while (pg->numE + 1 > pg->numV)		// MST ������ �� + 1 == ������ ��
	{
		// �켱���� ť���� ����ġ�� ���� ���� ������ ������ ������.
		edge = PDequeue(&(pg->pqueue));
		
		// �켱���� ť���� ���� ������ ������ �׷������� �����Ѵ�.
		RemoveEdge(pg, edge.v1, edge.v2);

		// ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�.
		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			// ��ΰ� ���ٸ� ������ ������ �����Ѵ�.
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			// ������ ������ ������ ������ �����Ѵ�. (�켱���� ť�� �ٽ� ������ PriorityDequeue �Լ� ȣ�� �� �ٽ� ������ �ȴ�.)
			recvEdge[edgeIndex++] = edge;
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��
	for (int i = 0; i < edgeIndex; i++)
	{
		PEnqueue(&(pg->pqueue), recvEdge[i]);
	}
}