/*
 * �q�T�|�� 
 * D0182315 
 * �\��� 
 * 2015/10/08
 * ��@ query �� en&del �ϥΰ}�C 
 */
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 5
void displayQueue(int queue[QUEUE_SIZE]){
	int index = 0;
	for(;index < QUEUE_SIZE;index++){
		printf("index: %d, value: %d\n", index, queue[index]);
	}
	printf("\n");
}
int isEmpty(int queue[QUEUE_SIZE], int *rear, int *front){
	if(*rear == *front){
		return true;
	} else {
		return false;
	}
}

int isFull(int queue[QUEUE_SIZE], int *rear, int *front){
	if(*rear + 1 == *front + QUEUE_SIZE){
		// �Q�ק�e (special case)
		return true;
	} else if (*rear + 1 == *front){
		// �Q�׫D�Y�� (general case)
		return true;
	} else {
		return false;
	}
}

void Enqueue(int queue[QUEUE_SIZE], int *rear, int *front){
	int value;
	if(isFull(queue, rear, front)){
		printf("the queue is already Full\n");
	} else {
		printf("Plz type value:");
		scanf(" %d", &value);
		*rear = *rear + 1;
		if(*rear == QUEUE_SIZE){
			*rear = 0;
		}
		queue[*rear] = value;
	}
	displayQueue(queue);
}
void delqueue(int queue[QUEUE_SIZE], int *rear, int *front){
	if(isEmpty(queue, rear, front)){
		printf("the queue is already empty\n");
	} else {
		*front = *front + 1;
		printf("Before: %d\n", queue[*front]);
		queue[*front] = 0;
		printf("After: %d\n", queue[*front]);
	}
	displayQueue(queue);
}

void showInitile(){
	printf("Queue_array\n");
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
	// create queue
	int queue[QUEUE_SIZE]={0};
	int rear = 0;
	int front = 0;
	int choice;
	while(1){
		showInitile();
		choice = getChoice();
		switch(choice){
			case 1:
				displayQueue(queue);
				break;
			case 2:
				Enqueue(queue, &rear, &front);
				break;
			case 3:
				delqueue(queue, &rear, &front);
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
