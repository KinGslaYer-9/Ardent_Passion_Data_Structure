#include <stdio.h>
#include "BinaryTree3.h"		// Ʈ���� ������ Ȯ���ϱ� ���ؼ�
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

	// LR ����
	/*BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);*/

	// RL ����
	/*BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 4);*/

	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);   //2, ��Ʈ 4�� ����
	crNode = GetRightSubTree(avlRoot);  //6, ��Ʈ 4�� ������
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode1 = GetLeftSubTree(clNode);    //1, 2�� ����
	crNode1 = GetRightSubTree(clNode);   //3, 2�� ������
	printf("%d, %d \n", GetData(clNode1), GetData(crNode1));

	clNode1 = GetLeftSubTree(crNode);    //5, 3�� ����
	crNode1 = GetRightSubTree(crNode);   //8, 3�� ������
	printf("%d, %d \n", GetData(clNode1), GetData(crNode1));

	clNode2 = GetLeftSubTree(crNode1);   //7, 8�� ����
	crNode2 = GetRightSubTree(crNode1);  //9, 8�� ������
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));
	return 0;
}