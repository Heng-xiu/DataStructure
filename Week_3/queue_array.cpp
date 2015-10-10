/*
 * 通訊四甲 
 * D0182315 
 * 許恆修 
 * 2015/10/08
 * 實作 query 的 en&del 使用陣列 
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
		// 討論投委 (special case)
		return true;
	} else if (*rear + 1 == *front){
		// 討論非頭尾 (general case)
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

int main(){	
	// create queue
	int queue[QUEUE_SIZE]={0};
	int rear = 0;
	int front = 0;
	displayQueue(queue);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	delqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	Enqueue(queue, &rear, &front);
	system("pause");
	return 0;
}
