/*
 * linkedList display length insert delete
 * �q�T�|�� 
 * D0182315 
 * �\��� 
 * ��@ stack �� pop&push �ϥ��쵲��C 
 */

#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 5

struct linkedlistNode{
	int data;
	struct linkedlistNode *nextNodeAddr;
};

void displayLinkedlist(struct linkedlistNode *currNode){
	if(currNode->nextNodeAddr == NULL){
		printf("�S��������!\n");
	}else {
		while(currNode != NULL){
			printf("Address: %p, value: %d, NextAddress: %p\n", currNode, currNode->data, currNode->nextNodeAddr);
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
	if(currNode->nextNodeAddr == NULL) {
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
void pushStack(struct linkedlistNode *startNode){
	// ���J�b�Y���� 
	if(isFull(startNode)){
		printf("���F\n");
	} else {
 		struct linkedlistNode *tmpNode;
 		tmpNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
		int value;
		printf("Type value:");
		scanf("%d", &value);
		tmpNode->data = value;
		tmpNode->nextNodeAddr = startNode->nextNodeAddr;
		startNode->nextNodeAddr = tmpNode;
	}
	displayLinkedlist(startNode);
}
void popStack(struct linkedlistNode *startNode){
	// �q�Y�}�l�R�� 
	if(isEmpty(startNode)){
		printf("�L�k�A�R��\n");
	} else {
	  	struct linkedlistNode *currNode;
	  	currNode = startNode;
	  	currNode->nextNodeAddr = currNode->nextNodeAddr->nextNodeAddr;
	  	printf("Delete node success\n");
	}
	displayLinkedlist(startNode);
}
void showInitile(){
	printf("[1] ��ܸ��\n");
	printf("[2] �s�W���\n");
	printf("[3] �R�����\n");
	printf("[4] �٧ڵe��\n");
}
int getChoice(){
	int result;
	printf("���:\n");
	scanf(" %d", &result);
	return result;
}

int main(){	
	// create linkedlist
	struct linkedlistNode *startNode;
	startNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
	startNode->data = NULL;
	startNode->nextNodeAddr = NULL;
	int choice;
	while(1){
		showInitile();
		choice = getChoice();
		switch(choice){
			case 1:
				displayLinkedlist(startNode);
				break;
			case 2:
				pushStack(startNode);
				break;
			case 3:
				popStack(startNode);
				break;
			case 4:
				system("CLS");
				break;
			default:
				printf("�A�a�a\n");
				break;
		}
	}
	system("pause");
	return 0;
}
