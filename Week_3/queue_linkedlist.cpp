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
	// �����O���� 
	createPtr = (linkedListNode*)malloc(sizeof(linkedListNode));
	printf("�ƭ�:");
	scanf("%d", &inputScore);
	createPtr->data.score = inputScore;
	createPtr->nextNodeAdd = NULL;
	
	// �إ߸`�I 
	if(*startPtr == NULL){
		// �إ߲Ĥ@�Ӹ`�I 
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
	printf("\n�s�W�ƭ�:");
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
 // �R���`�I�D���� 
 		prePtr->nextNodeAdd = currPtr->nextNodeAdd;
		free(currPtr);
		prePtr = currPtr; 
		currPtr = currPtr->nextNodeAdd;
	}
}

void showStudent(struct linkedListNode *currPtr){
	//	printf("!!showStudent!!\n");
	// ��ܸ`�I
	if(currPtr == NULL){
		printf("�S������ƭȳ�!\n");
	}else {
		while(currPtr != NULL){
			printf("|�ƭ�:%d |", currPtr->data.score);
			currPtr = currPtr->nextNodeAdd;
		}
	}
}

void showChoice(){
	printf("\n=============================\n");
	printf("[1] �s�W�ƭȽЫ�\n");
	printf("[2] �R���ƭȽЫ�\n");
	printf("=============================\n");
	printf("�z�����:");
}

int getChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
}

void choiceAboutAddStudent(struct linkedListNode **startPtr){
	if(*startPtr == NULL) {
		printf("�񺡴X�ӭ�:");
		// ��J�H��
		int counter = 0;
		int input;
		scanf("%d", &input);
		while(counter < input){
			firstAddStudent(&*startPtr);
			counter++;
		}
		showStudent(*startPtr);
	}else {
		printf("�Y�N�s�W...\n\n");
		addStudent(*startPtr);
		showStudent(*startPtr);
	}
}

void choiceAboutRemoveStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n�Y�N�R��...\n\n");
		removeStudent(&startPtr);
		showStudent(startPtr);
	}else {
		printf("\n�|���إ߼ƭȸ��\n\n");
	}
}

int main(){
	// �_�l�`�I 
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
				printf("switch case �줣��z�����");
		}
	}
	return 0;
}
