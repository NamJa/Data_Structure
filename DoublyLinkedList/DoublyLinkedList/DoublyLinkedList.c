#include <stdio.h>

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

int main()
{
	Node* list;

	list = DLL_CreateNode(110);
}