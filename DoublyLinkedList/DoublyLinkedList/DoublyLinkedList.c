#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode* prevNode;
	struct tagNode* nextNode;
} Node;

Node* DLL_CreateNode(int newData)
{
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;

	return newNode;
}

void DLL_DestroyNode(Node* list)
{
	free(list);
}

void DLL_AppendNode(Node** Head, Node* newNode)
{
	//��� ��尡 NULL�̶�� ���ο� ��尡 HEAD
	if (*Head == NULL)
	{
		*Head = newNode;
	}
	// ������ ã�� newNode�� �����Ѵ�.
	else 
	{
		Node* Tail = *Head;
		while (Tail->nextNode != NULL)
			Tail = Tail->nextNode;
		Tail->nextNode = newNode;
		// ������ tail�� ���ο� ������ prevNode�� ����Ų��.
		newNode->prevNode = Tail;
	}
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head) = Remove->nextNode;
		if ((*Head) != NULL)
			(*Head)->prevNode = NULL;
		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;
		/* DLL�� ��� ��尡 ���� ��带 �����ϱ� ������ while������ ���� �ʰ�,
		   �ּҰ� ���Ը� �ص� ���� ����� ���� ó���ϴ°��� �����ϴ� */
		Remove->prevNode->nextNode = Temp->nextNode;
		if (Remove->nextNode != NULL)
			Remove->nextNode->prevNode = Temp->prevNode;
		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
}

void DLL_InsertAfter(Node* Current, Node* newNode)
{
	newNode->nextNode = Current->nextNode;
	newNode->prevNode = Current;
	// current��� ������ ��尡 �ִٸ�
	if (Current->nextNode != NULL)
		Current->nextNode->prevNode = newNode;
	Current->nextNode = newNode;

}

int DLL_GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;
	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}
	return count;
}

Node* DLL_GetNodeAt(Node* Head, int location)
{
	Node* Current = Head;
	while (Current != NULL && (--location) >= 0)
		Current = Current->nextNode;
	return Current;
}

int main()
{
	Node* list = NULL;
	Node* newNode = NULL;

	newNode = DLL_CreateNode(110);
	DLL_AppendNode(&list, newNode);
}