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
	//헤드 노드가 NULL이라면 새로운 노드가 HEAD
	if (*Head == NULL)
	{
		*Head = newNode;
	}
	// 꼬리를 찾아 newNode를 연결한다.
	else 
	{
		Node* Tail = *Head;
		while (Tail->nextNode != NULL)
			Tail = Tail->nextNode;
		Tail->nextNode = newNode;
		// 기존의 tail을 새로운 테일의 prevNode가 가리킨다.
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
		/* DLL은 모든 노드가 이전 노드를 포함하기 때문에 while연산을 쓰지 않고,
		   주소값 대입만 해도 이전 노드의 값을 처리하는것이 가능하다 */
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
	// current노드 다음에 노드가 있다면
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