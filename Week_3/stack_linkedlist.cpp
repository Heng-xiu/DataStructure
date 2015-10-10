/*
 * linkedList display length insert delete
 * 通訊四甲 
 * D0182315 
 * 許恆修 
 * 實作 stack 的 pop&push 使用鏈結串列 
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
		printf("沒有任何資料!\n");
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
	// 插入在頭之後 
	if(isFull(startNode)){
		printf("滿了\n");
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
	// 從頭開始刪除 
	if(isEmpty(startNode)){
		printf("無法再刪除\n");
	} else {
	  	struct linkedlistNode *currNode;
	  	currNode = startNode;
	  	currNode->nextNodeAddr = currNode->nextNodeAddr->nextNodeAddr;
	  	printf("Delete node success\n");
	}
	displayLinkedlist(startNode);
}


int main(){	
	// create linkedlist
	struct linkedlistNode *startNode;
	startNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
	startNode->data = NULL;
	startNode->nextNodeAddr = NULL;
	displayLinkedlist(startNode);
	pushStack(startNode);
	pushStack(startNode);
	pushStack(startNode);
	popStack(startNode);
	popStack(startNode);
	popStack(startNode);
	popStack(startNode);
	system("pause");
	return 0;
}
