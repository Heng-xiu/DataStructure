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
	// ����1~25
	int	randMatrix[25]={0};
	// ��J1~25 
	for(int i=0;i<25;i++){
		randMatrix[i] = i+1;
	}
	// ���ö���
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
		// �Y�w�g�ˬd�h���L 
		if(doneRow[i] == 1)continue; 
		// �p��O�_�@���u 
		for(j=0;j<SIZE;j++){
			if( *(*(table+i)+j) == 1){
				checkNum = checkNum + 1;
			}
		}
		// �@���u�N���� 
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
		// �Y�w�g�ˬd�h���L
		if(doneCol[j]==1)continue;
		// �p��O�_�@���u
		for(i=0;i<SIZE;i++){
			if( *(*(table+i)+j) == 1){
				checkNum = checkNum + 1;
			}
		}
		// �@���u�N����
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
	// ���W�k�U e.g:00, 11, 22, 33, 44
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
	// �k�W���k e.g: 04, 13, 22, 31, 40
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
	// ��ܰ}�C
	int bingoTable[SIZE][SIZE] = {0};
	int playerTable[SIZE][SIZE] = {0};
	int *tmpRand;
	int score = 0;
	tmpRand = createRandNum();
	setValueInTable(tmpRand, bingoTable);
	
	// �H�U�� while or do while
	while(score < 3){
		printf("��BUG�b�̫�@�C�W, �ϥ�column\n");
		printf("Score:%d\n", score);
		printf("|���ê����G�L|\n");
		displayTable(bingoTable);
		printf("|���a�W���L|\n");
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
