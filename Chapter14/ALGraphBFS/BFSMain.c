#include <stdio.h>
#include "ALGraphBFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	BFSShowGraphVertex(&graph, A); printf("\n");
	BFSShowGraphVertex(&graph, C); printf("\n");
	BFSShowGraphVertex(&graph, E); printf("\n");
	BFSShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}