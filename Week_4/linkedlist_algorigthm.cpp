/*
 * 鏈結串列 
 * 顯示, 收尋, 長度, 插頭, 刪頭, 叉尾, 刪尾 
 * D0182315 
 * 通訊四甲 
 * 許恆修 
 * 2015/10/15 
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 struct linkedlistNode{
 	int data;
 	linkedlistNode *nextNodeAddr;
 };
 
 void display(struct linkedlistNode *currNode){
 	if(currNode->data == NULL){
 		printf("Nothing ot show\n")	;
	} else {
		printf("|Show linkedlistNode|\n");
		while(currNode->nextNodeAddr != NULL){
			printf("NodeAddr: %p, NodeData: %d, NextAddr: %p\n", currNode, currNode->data, currNode->nextNodeAddr);
			currNode = currNode->nextNodeAddr;
		}
		// 顯示最後一項 
		printf("NodeAddr: %p, NodeData: %d, NextAddr: %p\n", currNode, currNode->data, currNode->nextNodeAddr);
	}
 }
 
 int lengthOf(struct linkedlistNode *currNode) {
 	int count = 0;
 	if(currNode == NULL){
 		printf("ERROR in length\n");
	} else {
	 	
	 	while(currNode->nextNodeAddr != NULL){
	 		count++;
	 		currNode = currNode->nextNodeAddr;
		}
		count++;
	}
	return count;
 }
 
 void lookup(struct linkedlistNode *currNode, int index){
 	if(currNode == NULL){
 		printf("ERROR in lookup\n");
	} else if (index > lengthOf(currNode) || index <= 0){
		printf("linkedlist is not enough\n");
	} else {
		int count = 1;
		while(currNode->nextNodeAddr != NULL){
			if(count == index){
				printf("[%d]NodeAddr: %p, NodeData: %d, NextAddr: %p\n", index, currNode, currNode->data, currNode->nextNodeAddr);
			} else {
				count++;
			}
			currNode = currNode->nextNodeAddr; 
		}
		// 檢查最後
		if(count == index){
			printf("[%d]NodeAddr: %p, NodeData: %d, NextAddr: %p\n", index, currNode, currNode->data, currNode->nextNodeAddr);
		}
	}
 }
 
 void firstAdd(struct linkedlistNode *currNode){
 	if(currNode == NULL){
 		printf("ERROR in firstADD\n");
	} else {
		int input;
		printf("Initilize value=>");
		scanf(" %d", &input);
		currNode->data = input;
	}
 }
 
 void insertHead(struct linkedlistNode *currNode){
 	if(currNode == NULL){
 		printf("ERROR in insertHead\n");
	} else if(currNode->data == NULL){
		firstAdd(currNode);
	} else {
		struct linkedlistNode *tmpNode;
		tmpNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
		int input;
		printf("Insert value in Head=>");
		scanf(" %d", &input);
		tmpNode->data = input;
		tmpNode->nextNodeAddr = currNode->nextNodeAddr;
		currNode->nextNodeAddr = tmpNode; 
	}
 }
 
 void delHead(struct linkedlistNode *currNode){
 	if(currNode == NULL){
 		printf("ERROR in delHead\n");
	} else if (currNode->data == NULL){
		printf("Nothing can delete\n");
	} else {
		struct linkedlistNode *tmpNode;
		tmpNode = currNode->nextNodeAddr;
		currNode->nextNodeAddr = tmpNode->nextNodeAddr;
		free(tmpNode);
	}
 }
 
 void insertTail(struct linkedlistNode *currNode){
 	if(currNode == NULL){
 		printf("ERROR in insertTail\n");
	} else {
		// 定位節點位置 
		while(currNode->nextNodeAddr != NULL){
			currNode = currNode->nextNodeAddr;
		}
		// 新增節點 
		struct linkedlistNode *tmpNode;
		tmpNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
		int input;
		printf("Insert value in tail=>");
		scanf(" %d", &input);
		tmpNode->data = input;
		tmpNode->nextNodeAddr = currNode->nextNodeAddr;
		currNode->nextNodeAddr = tmpNode;
	}
 }
 
 void delTail(struct linkedlistNode *currNode){
 	if(currNode == NULL){
 		printf("ERROR in delTail\n");
	} else if (currNode->data == NULL){
		printf("Nothing can delete\n");
	} else {
		// 定位節點位置 
		struct linkedlistNode *nextNode;
		nextNode = currNode->nextNodeAddr;
		while(nextNode->nextNodeAddr != NULL){
			currNode = currNode->nextNodeAddr;
			nextNode = nextNode->nextNodeAddr;
		}
		currNode->nextNodeAddr = nextNode->nextNodeAddr;
		free(nextNode);
	}
 }
 
 int main(){
 	struct linkedlistNode *startNode;
 	startNode = (linkedlistNode*)malloc(sizeof(linkedlistNode));
 	startNode->data = NULL;
 	startNode->nextNodeAddr = NULL;
 	display(startNode);
 	insertHead(startNode);
 	display(startNode);
 	insertHead(startNode);
 	display(startNode);
 	insertHead(startNode);
 	display(startNode);
 	delHead(startNode);
 	display(startNode);
 	lookup(startNode, 0);
 	lookup(startNode, 1);
 	lookup(startNode, 3);
 	insertTail(startNode);
 	display(startNode);
 	delTail(startNode);
 	display(startNode);
 	system("pause");
 	return 0;
 }
