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

// 삽입과 탐색의 기본 동작 방식은 거의 같다.
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
		return NULL;	// 키의 중복을 허용하지 않는다.
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
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
	BTreeNode* pVRoot = MakeBTreeNode();		// 가상 루트 노드
	BTreeNode* pNode = pVRoot;					// parent node
	BTreeNode* cNode = *pRoot;					// current node
	BTreeNode* dNode;							// delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색 -> BSTSearch() 함수를 쓰지 않는 이유는 부모 노드의 갱신이 이루어지지 않기 때문이다.
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

	if (cNode == NULL)		// 삭제 대상이 존재하지 않는다면,
	{
		return NULL;
	}

	dNode = cNode;			// 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우 : 삭제 대상이 단말 노드인 경우
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
	// 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode;		// 삭제 대상의 자식 노드 가리킴

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
	// 세 번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);		// 대체 노드 가리킴
		BTreeNode* mpNode = dNode;						// 대체 노드의 부모 노드 가리킴
		int delData;

		// 삭제 대상의 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);				// 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));			// 대입

		// 대체 노드의 부모 노드와 자식 노드를 연결한다. (남아 있는것을 맞게 연결해주기 위함)
		// 그 자식이 왼쪽 노드라면 부모의 왼쪽에, 오른쪽 노드라면 부모의 오른쪽에 연결하는 것이다.
		if (GetLeftSubTree(mpNode) == mNode)
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData);		// 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	// 삭제 대상이 루트 노드인 경우 다른 노드로 대체되기도 한다.
	if (GetRightSubTree(pVRoot) != *pRoot)
	{
		*pRoot = GetRightSubTree(pVRoot);	// 루트 노드의 변경을 반영
	}

	free(pVRoot);		// 가상 루트 노드의 소멸
	*pRoot = Rebalance(pRoot);		// 노드 추가 후 리밸런싱
	return dNode;		// 삭제 대상의 반환
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}