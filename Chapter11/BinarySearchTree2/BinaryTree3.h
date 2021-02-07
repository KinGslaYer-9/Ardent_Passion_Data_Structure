#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);					// 왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode* RemoveRightSubTree(BTreeNode* bt);					// 오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
// MakeSubTree 함수들은 메모리의 해제를 하기 때문에 자식 노드의 교체를 목적으로는 어울리지 않아 추가 정의
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);		// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);		// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다.

#endif // !__BINARY_TREE3_H__
