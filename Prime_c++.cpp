#include <stdio.h>
#include <stdlib.h>

//  D0182315 許恆修
//  inputNum int	預判斷的數字
//  judgeNum func   判斷是否為植樹

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
