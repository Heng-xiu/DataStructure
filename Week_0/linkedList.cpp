
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

//	D0182315 �\��� �q�T�|�� 
//	*createPtr	��e�Ыت��쵲��C�`�I 
//	*currPtr	��e���`���쵲��C 
//	*startPtr	�쵲��C������ 

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
	printf("�W��:");
	scanf("%s", &inputName);
	printf("���Z:");
	scanf("%d", &inputScore);
	strcpy(createPtr->data.name, inputName);
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

void showStudent(struct linkedListNode *currPtr){
	//	printf("!!showStudent!!\n");
	// ��ܸ`�I
	if(currPtr == NULL){
		printf("�S������ǥͳ�!\n");
	}else {
		while(currPtr != NULL){
			printf("\n|---------------------|\n");
			printf("|�m�W:%s  |", currPtr->data.name);
			printf("|���Z:%d  |", currPtr->data.score);
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
			printf("\n�ק�ᦨ�Z:");
			scanf("%d", &changeScore);
			printf("�ק令�Z��...\n");
			currPtr->data.score = changeScore;
			isFind = 1;
			break;
		} 
		currPtr = currPtr->nextNodeAdd;
	}
	if(!isFind)printf("�S���ӦW�ǥ�\n");
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
			// ����H
			// �R���`�I����
			if (prePtr == NULL){
				*startPtr = currPtr->nextNodeAdd;
				free(currPtr);
				isFind = 1;
				break;
			} else {
				// �R���`�I�D���� 
				prePtr->nextNodeAdd = currPtr->nextNodeAdd;
				free(currPtr);
				isFind = 1;
				break;	
			}
		}
		prePtr = currPtr; 
		currPtr = currPtr->nextNodeAdd;
	}
	if(!isFind)printf("�S���ӦW�ǥ�\n");
}

void softScore(struct linkedListNode *currPtr){
	//	printf("\nSoft!!\n");
	struct linkedListNode *tmpNode, *currNode, *nextNode;
	tmpNode = (linkedListNode*)malloc(sizeof(linkedListNode));
	currNode = currPtr;
	nextNode = currPtr->nextNodeAdd;
	if(currNode == NULL){
		printf("\n�S������ǥ����A�� >.=");
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
	printf("\n�s�W�ǥͦW��:");
	scanf("%s", &newName);
	printf("\n�s�W�ǥͦ��Z:");
	scanf("%d", &newScore);
	printf("\n�s�W�ǥͤ�...\n");
	strcpy(tmpNode->data.name, newName);
	tmpNode->data.score = newScore;
	tmpNode->nextNodeAdd = currPtr->nextNodeAdd;
	currPtr->nextNodeAdd = tmpNode;
}

void showChoice(){
	printf("\n=============================\n");
	printf("[1] �s�W�ǥͦW��&���Z�Ы�\n");
	printf("[2] �ק�ǥͦ��Z�Ы�\n");
	printf("[3] �R���ǥ͸�ƽЫ�\n");
	printf("[4] �ƧǻP��ܾǥ͸�ƽЫ�\n");
	printf("[5] �ٵ��A���b�����Ы�\n");
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
		printf("�Ĥ@���ϥή�, �Q�n�s�W�h�֤H:");
		// ��J�H��
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
		printf("�Y�N�s�W...\n\n");
		addStudent(*startPtr);
		softScore(*startPtr);
		showStudent(*startPtr);
	}
}

void choiceAboutLookUpStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("�Y�N�ק�...\n\n");
		loopUpStudent(startPtr);
		softScore(startPtr);
		showStudent(startPtr);
	} else {
		printf("\n�|���إ߸��\n\n");
	}
}

void choiceAboutRemoveStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n�Y�N�R��...\n\n");
		removeStudent(&startPtr);
		softScore(startPtr);
		showStudent(startPtr);
	}else {
		printf("\n�|���إ߸��\n\n");
	}
}

void choiceAboutShowAndSoftStudent(struct linkedListNode *startPtr){
	if(startPtr != NULL){
		printf("\n�Y�N�ƧǻP���...\n\n");
		softScore(startPtr);
		showStudent(startPtr);
	}else {
		printf("\n�|���إ߸��\n\n");
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
				printf("switch case �줣��z�����");
		}
	}
	return 0;
}
