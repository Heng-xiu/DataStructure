/*
 * 通訊四甲 
 * D0182315 
 * 許恆修 
 * 2015/10/08
 * 實作 stack 的 pop&push 使用陣列 
 */
#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 10

void displayStack(int stack[STACK_SIZE]){
	int index;
	for(index = 0;index < STACK_SIZE;index++){
		printf("index: %d, value: %d\n", index, stack[index]);
	}
	printf("\n");
}

int isEmpty(int stack[STACK_SIZE], int top){
	if(top == -1){
		return true;
	} else {
		return false;
	}
}

int isFull(int stack[STACK_SIZE], int top){
	if(top == STACK_SIZE-1){
		return true;
	} else {
		return false;
	}
}

void popStack(int stack[STACK_SIZE], int *top){
	if(isEmpty(stack, *top)){
		printf("The stack is already empty\n");
	} else {
		printf("Before %d\n", stack[*top]);
		stack[*top] = 0;
		printf("After %d\n", stack[*top]);
		*top = *top - 1;
	}
	displayStack(stack);
}

void pushStack(int stack[STACK_SIZE], int *top){
	int value;
	printf("Type value to push:");
	scanf(" %d", &value);
	if(isFull(stack, *top)){
		printf("The stack is already full\n");
	} else {
		*top = *top + 1;
		*(stack+*top) = value;
	}
	displayStack(stack);
}

void showInitile(){
	printf("Stack_array\n");
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
	//create STACK
	int stack[STACK_SIZE] = {0};
	int top = -1;
	int choice;
	while(1){
		showInitile();
		choice = getChoice();
		switch(choice){
			case 1:
				displayStack(stack);
				break;
			case 2:
				pushStack(stack, &top);
				break;
			case 3:
				popStack(stack, &top);
				break;
			case 4:
				system("CLS");
				break;
			default:
				break;
		}
	}
	system("pause");
	return 0;
}
