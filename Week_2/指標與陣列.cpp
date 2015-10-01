/* display, findMax, findMin, order, inverse*/
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
void display(int *a){
	int index;
	for(index=0;index<SIZE;index++){
		printf("Value\n");
		printf("a[index]=%d, *(a+index)=%d\n", a[index], *(a+index));
		printf("Address\n");
		printf("a[index]=%p, *(a+index)=%p\n", &a[index], &*(a+index));
	}
}

int *findMax(int *input){
	int index;
	int *max;
	max = input;
	for(index=0;index<SIZE;index++){
		if( *(input+index) > *max){
			max = input+index;
		}
	}
	return max;
}

int *findMin(int *input){
	int *min;
	int index;
	min = input;
	for(index=0;index<SIZE;index++){
		if(*(input+index) < *min){
			min = input+index;
		}
	}
	return min;
}

void order(int *input){
	int index;
	int inner;
	int tmp;
	for(index=0;index<SIZE-1;index++){
		for(inner=1;inner<SIZE;inner++){
			if( *(input-1) > *(input)){
				tmp = *(input - 1);
				*(input - 1) = *(input);
				*(input) = tmp;
			}
		}
	}
}

int main(void){
	int a[SIZE]={10,55,25,37,94};
	int *max;
	int *min;
//	display(&a[0]);
	max = findMax(&a[0]);
	printf("Max:%d, Address:%p\n", *max, max);
	min = findMin(&a[0]);
	printf("Min:%d, Address:%p\n", *min, min);
	order(&a[0]);
	display(&a[0]);
	system("pause");
	return 0;
}
