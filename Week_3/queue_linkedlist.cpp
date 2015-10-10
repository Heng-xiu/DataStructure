#include <stdlib.h>
#include <stdio.h>

struct student{
	char	name[20];
	int		score;
};

struct linkedListNode{
	struct student data;
	struct linkedListNode *nextNodeAdd;
};

void firstAddStudent(struct linkedListNode **startPtr){
	struct linkedListNode *createPtr, *currPtr;
	char inputName[20];
	int inputScore;
	// 索取記憶體 
	createPtr = (linkedListNode*)malloc(sizeof(linkedListNode));
	printf("數值:");
	scanf("%d", &inputScore);
	createPtr->data.score = inputScore;
	createPtr->nextNodeAdd = NULL;
	
	// 建立節點 
	if(*startPtr == NULL){
		// 建立第一個節點 
		*startPtr = createPtr;
	} else {
		currPtr = *startPtr;
		
		while(currPtr != NULL){
			if(currPtr->nextNodeAdd == NULL) {
				currPtr->nextNodeAdd = createPtr;
				break;
			}
			currPtr = currPtr->nextNodeAdd;
		} 
	}
}

void addStudent(struct linkedListNode *currPtr){
	struct linkedListNode *tmpNode;
	tmpNode = (linkedListNode*)malloc(sizeof(linkedListNode));
	int newScore;
	printf("\n新增數值:");
	scanf("%d", &newScore);
	tmpNode->data.score = newScore;
	tmpNode->nextNodeAdd = currPtr->nextNodeAdd;
	currPtr->nextNodeAdd = tmpNode;
}

void removeStudent(struct linkedListNode **startPtr){
	//	printf("\nRemove\n");
	struct linkedListNode *currPtr, *prePtr;
	currPtr = *startPtr;
	prePtr = NULL; 
	while(currPtr != NULL){
 // 刪除節點非首相 
 		prePtr->nextNodeAdd = currPtr->nextNodeAdd;
		free(currPtr);
		prePtr = currPtr; 
		currPtr = currPtr->nextNodeAdd;
	}
}

void showStudent(struct linkedListNode *currPtr){
	//	printf("!!showStudent!!\n");
	// 顯示節點
	if(currPtr == NULL){
		printf("沒有任何數值喔!\n");
	}else {
		while(currPtr != NULL){
			printf("|數值:%d |", currPtr->data.score);
			currPtr = currPtr->nextNodeAdd;
		}
	}
}

void showChoice(){
	printf("\n=============================\n");
	printf("[1] 新增數值請按\n");
	printf("[2] 刪除數值請按\n");
	printf("=============================\n");
	printf("您的選擇:");
}

int getChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
}

void choiceAboutAddStudent(struct linkedListNode **startPtr){
	if(*startPtr == NULL) {
		printf("填滿幾個值:");
		// 輸入人數
		int counter = 0;
		int input;
		scanf("%d", &input);
		while(counter < input){
			firstAddStudent(&*startPtr);
			counter++;
		}
		showStudent(*startPtr);
	}else {
		printf("即將新增...\n\n");
		addStudent(*startPtr);
		showStudent(*startPtr);
	}
}

void choiceAboutRemoveStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n即將刪除...\n\n");
		removeStudent(&startPtr);
		showStudent(startPtr);
	}else {
		printf("\n尚未建立數值資料\n\n");
	}
}

int main(){
	// 起始節點 
	struct linkedListNode *startPtr = NULL;
	startPtr = NULL;	
	int choice;
	while(1){
		showChoice();
		choice = getChoice();
		switch(choice){
			case 1:
				choiceAboutAddStudent(&startPtr);
				break;
			case 2:
				choiceAboutRemoveStudent(startPtr);
				break;
			default :
				printf("switch case 抓不到您的選擇");
		}
	}
	return 0;
}
