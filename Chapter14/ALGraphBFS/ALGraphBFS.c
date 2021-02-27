#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv)
{
	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = (List*)malloc(sizeof(List*) * nv);		// 간선정보를 저장할 리스트 생성

	pg->numV = nv;		// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;		// 초기의 간선 수는 0개

	// 정점의 수만큼 생성된 리스트들을 초기화한다.
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);		// 알파벳 순으로 출력을 유도하기 위한 것, 중요하지 않음
	}

	// 정점의 수를 길이로 하여 배열을 할당
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	// 배열의 모든 요소를 0으로 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
	{
		free(pg->adjList);
	}

	// 할당된 배열의 소멸
	if (pg->visitInfo != NULL)
	{
		free(pg->visitInfo);
	}
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	// 방향 그래프라면 LInsert는 한 번만 호출될 것이다.
	// 정점 fromV 의 연결 리스트에 정점 toV 의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);
	// 정점 toV의 연결 리스트에 정점 fromV 의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

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
	if (pg->visitInfo[visitV] == 0)		// visitV에 처음 방문일 때
	{
		pg->visitInfo[visitV] = 1;		// visitV에 방문한 것으로 기록
		printf("%c ", visitV + 65);		// 방문한 정점의 이름을 출력
		return TRUE;
	}

	return FALSE;
}

void BFSShowGraphVertex(ALGraph* pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);
	VisitVertex(pg, visitV);		// 시작 정점을 탐색한다.

	// 아래의 while 문에서는 visitV와 연결된 모든 정점에 방문한다.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		if (VisitVertex(pg, nextV) == TRUE)
		{
			Enqueue(&queue, nextV);			// nextV에 방문했으니 큐에 저장
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
			{
				Enqueue(&queue, nextV);		// nextV에 방문했으니 큐에 저장
			}
		}

		if (QIsEmpty(&queue) == TRUE)		// 큐가 비면 BFS 종료
		{
			break;
		}
		else
		{
			visitV = Dequeue(&queue);		// 큐에서 하나 꺼내어 while 문 다시 시작
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);		// 탐색 정보 초기화
}