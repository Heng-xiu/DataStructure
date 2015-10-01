#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define SIZE 5

void displayTable(int matrix[SIZE][SIZE]){
	int i;
	int j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%3d", *(*(matrix+i)+j));
		}
		printf("\n");
	}
}

int *createRandNum(){
	// 產生1~25
	int	randMatrix[25]={0};
	// 填入1~25 
	for(int i=0;i<25;i++){
		randMatrix[i] = i+1;
	}
	// 打亂順序
	srand(time(NULL));
	for(int i=0;i<25;i++){
		int i1 = rand()%25;
		int i2 = rand()%25;
		int temp = randMatrix[i1];
		randMatrix[i1] = randMatrix[i2];
		randMatrix[i2] = temp;
	}
	return randMatrix;
}

void setValueInTable(int randMatrix[], int table[][SIZE]){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			table[i][j] = *(randMatrix+(i*SIZE+j));
		}
	}
}

void selectNumber(int bingoTable[][SIZE], int table[][SIZE], int number){
	int i;
	int j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if( *(*(bingoTable+i)+j) == number){
				*(*(table+i)+j) = 1;
			}
		}
	}
}

int checkRow(int table[][SIZE]){
	int i;
	int j;
	int checkNum;
	static int doneRow[5]={0};
	for(i=0;i<SIZE;i++){
		checkNum = 0;
		// 若已經檢查則跳過 
		if(doneRow[i] == 1)continue; 
		// 計算是否一條線 
		for(j=0;j<SIZE;j++){
			if( *(*(table+i)+j) == 1){
				checkNum = checkNum + 1;
			}
		}
		// 一條線就結束 
		if(checkNum == 5){
			doneRow[i] = 1;
			return 1;
		}	
	}
}

int checkColumn(int table[][SIZE]){
	int i;
	int j;
	int checkNum;
	static int doneCol[SIZE]={0};
	for(j=0;j<SIZE;j++){
		checkNum = 0;
		// 若已經檢查則跳過
		if(doneCol[j]==1)continue;
		// 計算是否一條線
		for(i=0;i<SIZE;i++){
			if( *(*(table+i)+j) == 1){
				checkNum = checkNum + 1;
			}
		}
		// 一條線就結束
		if(checkNum == 5){
			doneCol[j]=1;
			return 1;
		}
	}
}

int checkCross(int table[][SIZE]){
	int i;
	int j;
	int checkNum;
	int result = 0;
	// 左上右下 e.g:00, 11, 22, 33, 44
	static int isDoneLeft = 0;
	if(isDoneLeft == 0){
		checkNum = 0;
		for(i=0;i<SIZE;i++){
			if( *(*(table+i)+i) == 1){
				checkNum = checkNum + 1;
			}
		}
		if(checkNum == 5){
			isDoneLeft = 1;
			result = result + 1;
		}
	}
	// 右上左右 e.g: 04, 13, 22, 31, 40
	static int isDoneRight = 0;
	if(isDoneRight == 0){
		checkNum = 0;
		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
				if( (i+j) == 4 && *(*(table+i)+j)){
					checkNum = checkNum + 1;
				}
			}
		}
		if(checkNum == 5){
			isDoneRight = 1;
			result = result + 1;
		}
	}
	return result;
}

int main(void){
	// 顯示陣列
	int bingoTable[SIZE][SIZE] = {0};
	int playerTable[SIZE][SIZE] = {0};
	int *tmpRand;
	int score = 0;
	tmpRand = createRandNum();
	setValueInTable(tmpRand, bingoTable);
	
	// 以下為 while or do while
	while(score < 3){
		printf("有BUG在最後一列上, 使用column\n");
		printf("Score:%d\n", score);
		printf("|隱藏的賓果盤|\n");
		displayTable(bingoTable);
		printf("|玩家戳號盤|\n");
		displayTable(playerTable);
		int number;
		printf("Plz input a number:");
		scanf(" %d", &number);
		selectNumber(bingoTable, playerTable, number);
		score += checkRow(playerTable);
		score += checkColumn(playerTable);
		score += checkCross(playerTable);
		system("CLS");
	}
	system("pause");
	return 0;
}
