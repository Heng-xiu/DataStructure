#include <stdio.h>
#include <stdlib.h>

//  D0182315 �\���
//  inputNum int	�w�P�_���Ʀr
//  judgeNum func   �P�_�O�_���Ӿ�

void judgePrime(int);

void judgePrime (int inputNum){
	int remainder = 0;
 	for(int i=1; i <= inputNum; i++){
		if((inputNum%i) == 0){
			 remainder =  remainder+1;
		}
		if(remainder > 2){
			printf( "Not prime number\n");
			break;
		}
	}
	if( remainder == 2){
		printf("It is prime number\n") ;
	}
}

int main(){

	int inputNum;
	scanf("%d", &inputNum);
	judgePrime(inputNum);
	system("pause");
	return 0;
}
