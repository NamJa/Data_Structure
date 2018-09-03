#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode *NextNode;
} Node;

//=====================================
// �����ߴ� ������ �޸� �ּҸ� ��ȯ�ϹǷ� ���� �߻�
//=====================================
//Node* SLL_CreateNode(int NewData)
//{
//	Node newNode;
//	newNode.Data = NewData;
//	newNode.NextNode = NULL;
//
//	return &newNode;
//}

Node* SLL_CreateNode(int NewData)
{
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_Destroy(Node* node)
{
	free(node);
}

// *List�� �ּҰ��� �Ű������� �����ϰ� *List�� �����͸� �޾� ó��
void  SLL_AppendNode(Node** Head, Node* NewNode)
{
	// *List�� ������ ó��
	if ((*Head) == NULL)
		*Head = NewNode;
	else
	{
		Node* Tail = (Head);
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != NULL && (--Location) >= 0)
		Current = Current->NextNode;
	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
		*Head = Remove->NextNode;
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
			Current = Current->NextNode;
		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

int SLL_GetNodeCount(Node* Head)
{
	int count = 0;
	while (Head != NULL)
	{
		Head = Head->NextNode;
		count++;
	}
	return count;
}


int main()
{
	Node *myNode =  NULL;
	Node *List = NULL;

	myNode = SLL_CreateNode(110);
	SLL_AppendNode(&List, myNode);
	printf("%d, %d\n", List->Data, myNode->Data);
}