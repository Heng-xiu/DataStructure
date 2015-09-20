
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void firstAddStudent(struct linkedListNode **startPtr);
void showStudent(struct linkedListNode *currPtr);
void loopUpStudent(struct linkedListNode *currPtr);
void removeStudent(struct linkedListNode **startPtr);
void softScore(struct linkedListNode *currPtr);
void addStudent(struct linkedListNode *currPtr);
void showChoice();
int  getChoice();
void choiceAboutAddStudent(struct linkedListNode **startPtr);
void choiceAboutLookUpStudent(struct linkedListNode *startPtr);
void choiceAboutRemoveStudent(struct linkedListNode *startPtr);
void choiceAboutShowAndSoftStudent(struct linkedListNode *startPtr);

//	D0182315 許恆修 通訊四甲 
//	*createPtr	當前創建的鏈結串列節點 
//	*currPtr	當前關注的鏈結串列 
//	*startPtr	鏈結串列的首相 

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
	printf("名稱:");
	scanf("%s", &inputName);
	printf("成績:");
	scanf("%d", &inputScore);
	strcpy(createPtr->data.name, inputName);
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

void showStudent(struct linkedListNode *currPtr){
	//	printf("!!showStudent!!\n");
	// 顯示節點
	if(currPtr == NULL){
		printf("沒有任何學生喔!\n");
	}else {
		while(currPtr != NULL){
			printf("\n|---------------------|\n");
			printf("|姓名:%s  |", currPtr->data.name);
			printf("|成績:%d  |", currPtr->data.score);
			currPtr = currPtr->nextNodeAdd;
		}
	}
}

void loopUpStudent(struct linkedListNode *currPtr){
	//	printf("loopUp\n");
	char lookUpName[20];
	int changeScore;
	int isFind = 0;
	printf("\nGive me a Name:");
	scanf("%s", &lookUpName);
	while(currPtr != NULL){
		if(strcmp(currPtr->data.name, lookUpName) == 0){
			printf("\n修改後成績:");
			scanf("%d", &changeScore);
			printf("修改成績中...\n");
			currPtr->data.score = changeScore;
			isFind = 1;
			break;
		} 
		currPtr = currPtr->nextNodeAdd;
	}
	if(!isFind)printf("沒有該名學生\n");
}

void removeStudent(struct linkedListNode **startPtr){
	//	printf("\nRemove\n");
	struct linkedListNode *currPtr, *prePtr;
	currPtr = *startPtr;
	prePtr = NULL; 
	int isFind = 0;
	char removeName[20];
	printf("\nGive me a Name to remove:");
	scanf(" %s", &removeName);
	while(currPtr != NULL){
		if(strcmp(currPtr->data.name, removeName) == 0){
			// 找到對象
			// 刪除節點首相
			if (prePtr == NULL){
				*startPtr = currPtr->nextNodeAdd;
				free(currPtr);
				isFind = 1;
				break;
			} else {
				// 刪除節點非首相 
				prePtr->nextNodeAdd = currPtr->nextNodeAdd;
				free(currPtr);
				isFind = 1;
				break;	
			}
		}
		prePtr = currPtr; 
		currPtr = currPtr->nextNodeAdd;
	}
	if(!isFind)printf("沒有該名學生\n");
}

void softScore(struct linkedListNode *currPtr){
	//	printf("\nSoft!!\n");
	struct linkedListNode *tmpNode, *currNode, *nextNode;
	tmpNode = (linkedListNode*)malloc(sizeof(linkedListNode));
	currNode = currPtr;
	nextNode = currPtr->nextNodeAdd;
	if(currNode == NULL){
		printf("\n沒有任何學生讓你排 >.=");
	} else {
		while(currNode != NULL){
			while(nextNode != NULL){
				if(currNode->data.score > nextNode->data.score){
					// cp current data to tmpNode 
					strcpy(tmpNode->data.name, currNode->data.name);
					tmpNode->data.score = currNode->data.score;
					// cp nextNode data to currNode
					strcpy(currNode->data.name, nextNode->data.name);
					currNode->data.score = nextNode->data.score;
					// cp tmpNode data to nextNode
					strcpy(nextNode->data.name, tmpNode->data.name);
					nextNode->data.score = tmpNode->data.score;
				}
				nextNode = nextNode->nextNodeAdd;
			}
			if(currNode->nextNodeAdd == NULL){
				break;
			} else {
				currNode = currNode->nextNodeAdd;
				nextNode = currNode->nextNodeAdd;
			}
		}
	}
}

void addStudent(struct linkedListNode *currPtr){
	//	printf("\nadd!\n");
	struct linkedListNode *tmpNode;
	tmpNode = (linkedListNode*)malloc(sizeof(linkedListNode));
	char newName[20];
	int newScore;
	printf("\n新增學生名稱:");
	scanf("%s", &newName);
	printf("\n新增學生成績:");
	scanf("%d", &newScore);
	printf("\n新增學生中...\n");
	strcpy(tmpNode->data.name, newName);
	tmpNode->data.score = newScore;
	tmpNode->nextNodeAdd = currPtr->nextNodeAdd;
	currPtr->nextNodeAdd = tmpNode;
}

void showChoice(){
	printf("\n=============================\n");
	printf("[1] 新增學生名稱&成績請按\n");
	printf("[2] 修改學生成績請按\n");
	printf("[3] 刪除學生資料請按\n");
	printf("[4] 排序與顯示學生資料請按\n");
	printf("[5] 還給你乾淨的選單請按\n");
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
		printf("第一次使用時, 想要新增多少人:");
		// 輸入人數
		int counter = 0;
		int input;
		scanf("%d", &input);
		while(counter < input){
			firstAddStudent(&*startPtr);
			counter++;
		}
		softScore(*startPtr);
		showStudent(*startPtr);
	}else {
		printf("即將新增...\n\n");
		addStudent(*startPtr);
		softScore(*startPtr);
		showStudent(*startPtr);
	}
}

void choiceAboutLookUpStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("即將修改...\n\n");
		loopUpStudent(startPtr);
		softScore(startPtr);
		showStudent(startPtr);
	} else {
		printf("\n尚未建立資料\n\n");
	}
}

void choiceAboutRemoveStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n即將刪除...\n\n");
		removeStudent(&startPtr);
		softScore(startPtr);
		showStudent(startPtr);
	}else {
		printf("\n尚未建立資料\n\n");
	}
}

void choiceAboutShowAndSoftStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n即將排序與顯示...\n\n");
		softScore(startPtr);
		showStudent(startPtr);
	}else {
		printf("\n尚未建立資料\n\n");
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
				choiceAboutLookUpStudent(startPtr);
				break;
			case 3:
				choiceAboutRemoveStudent(startPtr);
				break;
			case 4:
				choiceAboutShowAndSoftStudent(startPtr);
				break;
			case 5:
				system("CLS");
				break;
			default :
				printf("switch case 抓不到您的選擇");
		}
	}
	return 0;
}
