#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	chooseRand(int, int);
void guessNum(int, int *, int *);

int chooseRand(int smallNum, int bigNum){
	//rand() % (最大值-最小值+1) ) + 最小值
	int randNum;
	srand(time(NULL));
	randNum = rand() % ((bigNum - smallNum + 1) + smallNum);
	return randNum;
}

void guessNum(int randNum,int *smallNum, int *bigNum){
	while(1){
		int userGuess;
		scanf("%d", &userGuess);
		if(randNum == userGuess){
			printf("Correct!!!\n");
			break;
		}
		if(userGuess != randNum){
			//judge userGuess > or < randNum
			if(userGuess > randNum){
				*bigNum = userGuess;
			}
			if(userGuess < randNum){
				*smallNum = userGuess;
			}
			printf("Range:%d~%d", *smallNum, *bigNum);
		}
 	}
}

int main(){

	int smallNum;
	int bigNum;
	int randNum;
	printf("smallNum:");
	scanf("%d", &smallNum);
	printf("bigNum:");
	scanf("%d", &bigNum);
	randNum = chooseRand(smallNum, bigNum);
	guessNum(randNum, &smallNum, &bigNum);
	system("pause");
	return 0;
}
