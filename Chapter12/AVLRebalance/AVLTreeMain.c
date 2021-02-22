#include <stdio.h>
#include "BinaryTree3.h"		// 트리의 구조를 확인하기 위해서
#include "BinarySearchTree3.h"

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* clNode;				// current left node
	BTreeNode* crNode;				// current right node

	BTreeNode* clNode1;
	BTreeNode* crNode1;

	BTreeNode* clNode2;
	BTreeNode* crNode2;

	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	// LR 상태
	/*BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);*/

	// RL 상태
	/*BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);*/

	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);   //2, 루트 4의 왼편
	crNode = GetRightSubTree(avlRoot);  //6, 루트 4의 오른편
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode1 = GetLeftSubTree(clNode);    //1, 2의 왼편
	crNode1 = GetRightSubTree(clNode);   //3, 2의 오른편
	printf("%d, %d \n", GetData(clNode1), GetData(crNode1));

	clNode1 = GetLeftSubTree(crNode);    //5, 3의 왼편
	crNode1 = GetRightSubTree(crNode);   //8, 3의 오른편
	printf("%d, %d \n", GetData(clNode1), GetData(crNode1));

	clNode2 = GetLeftSubTree(crNode1);   //7, 8의 왼편
	crNode2 = GetRightSubTree(crNode1);  //9, 8의 오른편
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));
	return 0;
}