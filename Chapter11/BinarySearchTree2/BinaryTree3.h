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

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);					// ���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode* RemoveRightSubTree(BTreeNode* bt);					// ������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
// MakeSubTree �Լ����� �޸��� ������ �ϱ� ������ �ڽ� ����� ��ü�� �������δ� ��︮�� �ʾ� �߰� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);		// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�.
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);		// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�.

#endif // !__BINARY_TREE3_H__
