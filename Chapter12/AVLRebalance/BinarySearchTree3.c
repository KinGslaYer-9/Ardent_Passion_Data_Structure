#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

// ���԰� Ž���� �⺻ ���� ����� ���� ����.
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL;	// Ű�� �ߺ��� ������� �ʴ´�.
	}

	return *pRoot;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;		// current node
	BSTData cd;					// current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
		{
			return cNode;
		}
		else if (target < cd)
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	BTreeNode* pVRoot = MakeBTreeNode();		// ���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;					// parent node
	BTreeNode* cNode = *pRoot;					// current node
	BTreeNode* dNode;							// delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž�� -> BSTSearch() �Լ��� ���� �ʴ� ������ �θ� ����� ������ �̷������ �ʱ� �����̴�.
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL)		// ���� ����� �������� �ʴ´ٸ�,
	{
		return NULL;
	}

	dNode = cNode;			// ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ��� : ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
		{
			RemoveLeftSubTree(pNode);
		}
		else
		{
			RemoveRightSubTree(pNode);
		}
	}
	// �� ��° ��� : ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;		// ���� ����� �ڽ� ��� ����Ŵ

		if (GetLeftSubTree(dNode) != NULL)
		{
			dcNode = GetLeftSubTree(dNode);
		}
		else
		{
			dcNode = GetRightSubTree(dNode);
		}

		if (GetLeftSubTree(pNode) == dNode)
		{
			ChangeLeftSubTree(pNode, dcNode);
		}
		else
		{
			ChangeRightSubTree(pNode, dcNode);
		}
	}
	// �� ��° ��� : �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);		// ��ü ��� ����Ŵ
		BTreeNode* mpNode = dNode;						// ��ü ����� �θ� ��� ����Ŵ
		int delData;

		// ���� ����� ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);				// ���� �� ������ ���
		SetData(dNode, GetData(mNode));			// ����

		// ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�. (���� �ִ°��� �°� �������ֱ� ����)
		// �� �ڽ��� ���� ����� �θ��� ���ʿ�, ������ ����� �θ��� �����ʿ� �����ϴ� ���̴�.
		if (GetLeftSubTree(mpNode) == mNode)
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData);		// ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� �߰����� ó��
	// ���� ����� ��Ʈ ����� ��� �ٸ� ���� ��ü�Ǳ⵵ �Ѵ�.
	if (GetRightSubTree(pVRoot) != *pRoot)
	{
		*pRoot = GetRightSubTree(pVRoot);	// ��Ʈ ����� ������ �ݿ�
	}

	free(pVRoot);		// ���� ��Ʈ ����� �Ҹ�
	*pRoot = Rebalance(pRoot);		// ��� �߰� �� ���뷱��
	return dNode;		// ���� ����� ��ȯ
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}