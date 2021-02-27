#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv)
{
	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List*) * nv);		// ���������� ������ ����Ʈ ����

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

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	// ���� �׷������ LInsert�� �� ���� ȣ��� ���̴�.
	// ���� fromV �� ���� ����Ʈ�� ���� toV �� ���� �߰�
	LInsert(&(pg->adjList[fromV]), toV);
	// ���� toV�� ���� ����Ʈ�� ���� fromV �� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE += 1;
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

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)		// visitV�� ó�� �湮�� ��
	{
		pg->visitInfo[visitV] = 1;		// visitV�� �湮�� ������ ���
		printf("%c ", visitV + 65);		// �湮�� ������ �̸��� ���
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