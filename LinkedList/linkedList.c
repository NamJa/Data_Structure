#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode *NextNode;
} Node;

//=====================================
// 존재했던 변수의 메모리 주소를 반환하므로 에러 발생
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

// *List의 주소값을 매개변수로 전달하고 *List의 데이터를 받아 처리
void  SLL_AppendNode(Node** Head, Node* NewNode)
{
	// *List의 데이터 처리
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


int main()
{
	Node *myNode =  NULL;
	Node *List = NULL;

	myNode = SLL_CreateNode(110);
	SLL_AppendNode(&List, myNode);
	printf("%d, %d\n", List->Data, myNode->Data);
}