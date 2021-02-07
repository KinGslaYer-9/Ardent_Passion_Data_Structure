#include <stdio.h>
#include "BinarySearchTree.h"

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
	BTreeNode* pNode = NULL;			// parent node
	BTreeNode* cNode = *pRoot;			// current node
	BTreeNode* nNode = NULL;			// new node

	// ����� ��ġ ã��
	// while �� ���� �ٱ��� ������ if ������ �ִµ�, �̷��� ������ ������
	// �� ��带 �ޱ� ���ؼ��� �θ����� ��ġ�� �ʿ��ϱ� �����̴�.
	while (cNode != NULL)
	{
		// ��������(Ű��) �ߺ��� ������� ����
		if (data == GetData(cNode))
			return;

		// cNode �� �ٲ�� ���� ����� �ؾ� �Ѵ�.
		pNode = cNode;

		if (GetData(cNode) > data)
		{
			cNode = GetLeftSubTree(cNode);
		}
		else
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (data < GetData(pNode))
		{
			MakeLeftSubTree(pNode, nNode);
		}
		else
		{
			MakeRightSubTree(pNode, nNode);
		}
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}
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