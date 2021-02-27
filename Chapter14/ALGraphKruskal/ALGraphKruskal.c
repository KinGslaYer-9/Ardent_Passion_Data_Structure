#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

void GraphInit(ALGraph* pg, int nv)
{
	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = (List*)malloc(sizeof(List) * nv);		// 간선정보를 저장할 리스트 생성
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

	// 우선순위 큐의 초기화
	PQueueInit(&(pg->pqueue), PQWeightComp);
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

void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// 간선의 가중치 정보를 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), edge);
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// 한쪽 방향의 간선 소멸
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
	if (pg->visitInfo[visitV] == 0)		// visitV에 처음 방문일 때
	{
		pg->visitInfo[visitV] = 1;		// visitV에 방문한 것으로 기록
		// printf("%c ", visitV + 65);		// 방문한 정점의 이름을 출력
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
	VisitVertex(pg, visitV);		// 시작 지점을 방문
	SPush(&stack, visitV);			// 시작 정점의 정보를 스택으로

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while 문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitV 와 연결된 정점의 정보가 nextV 에 담긴 상태에서 이하를 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)		// 방문에 성공했다면,
		{
			SPush(&stack, visitV);		// visitV 에 담긴 정점의 정보를 PUSH
			visitV = nextV;
			visitFlag = TRUE;
		}
		else    // 방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다.
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

		if (visitFlag == FALSE)		// 추가로 방문한 정점이 없었다면
		{
			// 스택이 비면 탐색의 시작점으로 되돌아 온 것
			if (SIsEmpty(&stack) == TRUE)
			{
				break;
			}
			else
			{
				visitV = SPop(&stack);		// 길을 되돌아 간다.
			}
		}
	}

	// 이후의 탐색을 위해서 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 인자로 전달된 두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE 반환
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

		// 정점을 돌아다니는 도중에 목표를 찾았다면 TRUE 를 반환한다.
		if (nextV == v2)
		{
			// 함수가 반환하기 전에 초기화를 진행한다.
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
				// 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE 를 반환한다.
				if (nextV == v2)
				{
					// 함수가 반환하기 전에 초기화를 진행한다.
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
	return FALSE;		// 목표를 찾지 못했다.
}

void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20];		// 복원할 간선의 정보 저장
	Edge edge;
	int edgeIndex = 0;

	// MST 를 형성할 때까지 아래의 while 문을 반복
	while (pg->numE + 1 > pg->numV)		// MST 간선의 수 + 1 == 정점의 수
	{
		// 우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다.
		edge = PDequeue(&(pg->pqueue));
		
		// 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다.
		RemoveEdge(pg, edge.v1, edge.v2);

		// 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다.
		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			// 경로가 없다면 삭제한 간선을 복원한다.
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			// 복원한 간선의 정보를 별도로 저장한다. (우선순위 큐에 다시 넣으면 PriorityDequeue 함수 호출 시 다시 꺼내게 된다.)
			recvEdge[edgeIndex++] = edge;
		}
	}

	// 우선순위 큐에서 삭제된 간선의 정보를 회복
	for (int i = 0; i < edgeIndex; i++)
	{
		PEnqueue(&(pg->pqueue), recvEdge[i]);
	}
}