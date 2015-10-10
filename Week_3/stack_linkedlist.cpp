/*
 * linkedList display length insert delete
 *
 *
 *
 *
 *
 */

#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
struct linkedlistNode{
	int data;
	struct linkedlistNode *nextNodeAddr;
};

void displayLinkedlist(struct linkedlistNode *currNode){
	if(currNode == NULL){
		printf("�S��������!\n");
	}else {
		while(currNode != NULL){
			printf("Address: %p, value: %d\n", currNode, currNode->data);
			currNode = currNode->nextNodeAddr;
		}
	}
}
int stackLength(struct linkedlistNode *currNode){
	int countLength = 0;
	struct linkedlistNode *tmpNode;
	tmpNode = currNode;
	while(tmpNode != NULL){
		countLength += 1;
		tmpNode = tmpNode->nextNodeAddr;
	}
	return countLength;
}
int isEmpty(struct linkedlistNode *currNode){
	if(currNode == NULL) {
		return true;
	} else {
		return false;
	}
}
int isFull(struct linkedlistNode *currNode){
	if(stackLength(currNode) == STACK_SIZE+1){
		return true;
	} else {
		return false;
	}
}
void pushStack(struct linkedlistNode **currNode){
	// ���J�b�Y���� 
	if(isFull(*currNode)){
		printf("���F\n");
	} else {
 		struct linkedlistNode *tmpNode;
 		tmpNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
		int value;
		printf("Type value:");
		scanf("%d", &value);
		tmpNode->data = value;
//		tmpNode->nextNodeAddr = (*currNode)->nextNodeAddr;
//		(*currNode)->nextNodeAddr = tmpNode;
	}
}
void popStack(struct linkedlistNode **startNode){
	// �q�Y�}�l�R�� 
	if(isEmpty(*startNode)){
		printf("�L�k�A�R��\n");
	} else {
	  struct linkedlistNode *currNode, *nextNode;
	  currNode = *startNode;
	  nextNode = currNode->nextNodeAddr; 
	  currNode->nextNodeAddr = nextNode->nextNodeAddr;
	  free(currNode);
	}
}


int main(){	
	// create linkedlist
	struct linkedlistNode *startNode;
	startNode = NULL;
	displayLinkedlist(startNode);
	pushStack(&startNode);
//	popStack(&startNode);
//	displayLinkedlist(startNode);
	system("pause");
	return 0;
}
