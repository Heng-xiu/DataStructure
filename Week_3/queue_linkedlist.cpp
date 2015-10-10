/*
 * linkedList display length insert delete
 * 通訊四甲 
 * D0182315 
 * 許恆修 
 * 實作 quere 的 enqueue & delqueue 使用鏈結串列 
 * queue 實際純放內容為 QUEUE_SIZE X - 2 
 */

#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 7 

struct linkedlistNode{
	int data;
	linkedlistNode *nextNodeAddr;
};

int isEmpty(int front, int rear) {
	printf("[Empty]front: %d, rear: %d\n", front, rear);
	if(front == rear){
		return true;
	} else {
		return false;
	}
}

int isFull(int front, int rear){
	printf("[Full]front: %d, rear: %d\n", front, rear);
	if(front + QUEUE_SIZE - 2 == rear + 1){
		return true;
	} else {
		return false;
	}
}

void displayQueue(struct linkedlistNode *currNode){
	if(currNode->nextNodeAddr == NULL){
		printf("沒有資料可以顯示\n");
	} else {
		while(currNode != NULL){
			printf("Addr: %p, Value: %d, NextAddr: %p\n", currNode, currNode->data, currNode->nextNodeAddr);
			currNode = currNode->nextNodeAddr;
		}
	}
}

void enQueue(struct linkedlistNode *startNode, int *front, int *rear){
	if(isFull(*front, *rear)){
		printf("柱列已經滿了\n");
	} else {
		struct linkedlistNode *tmpNode;
		tmpNode = (linkedlistNode *)malloc(sizeof(linkedlistNode));
		int value;
		printf("Type value:");
		scanf(" %d", &value);
		tmpNode->data = value;
		tmpNode->nextNodeAddr = startNode->nextNodeAddr;
		startNode->nextNodeAddr = tmpNode;
		if(*rear + 1 == QUEUE_SIZE - 2 ){
			*rear = 0;
		} else {
			*rear = *rear + 1;
		}
		printf("Insert success\n");
	} 
	displayQueue(startNode);
}

void delQueue(struct linkedlistNode *startNode, int *front, int *rear){
	if(isEmpty(*front, *rear)){
		printf("住列為空無法刪除\n");
	} else {
		struct linkedlistNode *currNode;
		currNode = startNode;
		while(currNode->nextNodeAddr->nextNodeAddr != NULL){
			currNode = currNode->nextNodeAddr;
		}
		free(currNode->nextNodeAddr->nextNodeAddr);
		currNode->nextNodeAddr = NULL;
		if(*front + 1 == QUEUE_SIZE - 2 ){
			*front = 0;
		} else {
			*front = *front + 1;
		}
		printf("delete succes\n");
	}
	displayQueue(startNode);
}
void showInitile(){
	printf("[1] 顯示資料\n");
	printf("[2] 新增資料\n");
	printf("[3] 刪除資料\n");
	printf("[4] 還我畫面\n");
}
int getChoice(){
	int result;
	printf("選擇:\n");
	scanf(" %d", &result);
	return result;
}

int main(){
	struct linkedlistNode *startNode;
	startNode = (linkedlistNode *)malloc(sizeof(linkedlistNode));
	startNode->data = 0;
	startNode->nextNodeAddr = NULL;
	int front = 0;
	int rear = 0;
	int choice;
	while(1){
		showInitile();
		choice = getChoice();
		switch(choice){
			case 1:
				displayQueue(startNode);
				break;
			case 2:
				enQueue(startNode, &front, &rear);
				break;
			case 3:
				delQueue(startNode, &front, &rear);
				break;
			case 4:
				system("CLS");
				break;
			default:
				printf("你壞壞\n");
				break;
		}
	}
	system("pause");
	return 0;
}
