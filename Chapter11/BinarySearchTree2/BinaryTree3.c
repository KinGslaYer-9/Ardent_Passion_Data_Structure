#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
	{
		free(main->left);
	}

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
	{
		free(main->right);
	}

	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
	{
		return;
	}

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

// '삭제' 또는 '제거' 라고 하면 반드시 메모리의 해제까지 담당해야 하는 것으로 오해하는 경우가 있다.
// '삭제' 와 '메모리의 해제'는 별개의 것이다.
// 삭제과정에서 메모리의 해제를 포함하는 경우도 있지만, 반드시 필요한 것은 아니며 오히려 포함해서는 안 되는 경우도 존재한다.

// 삭제과정에서 메모리의 해제를 포함하지 않는 것이 일반적이다.
// 주소 값의 반환을 통해서 메모리의 해제에 대한 책임을 함수를 호출한 영역으로 넘긴다.
BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt != NULL)
	{
		delNode = bt->left;
		bt->left = NULL;
	}

	return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;

	if (bt != NULL)
	{
		delNode = bt->right;
		bt->right = NULL;
	}

	return delNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}