#include "head.h"

/*
 *  rand_num(int isATK)	.�H�����o�üƭ� 1-25 || 0-25 ���MisATK 
 *  user_choice(struct Team *currTeam, int isATK, int *currPlayerId)	.���a�ιq������� 
 */

int rand_num(int isATK){
	int var;
 	srand(time(NULL));
 	if((isATK%2) == 1){
 		// �q��������	[��] 
 		var=(rand()%25);	//0-25
	}else if((isATK%2) == 0){
		// �q������� 	[�u]
		var=(rand()%25)+1;	//1-25 
	}
	Sleep(300);
 	return var;
}

void _check_choice(int *p1_choice, int isATK){
	if((isATK%2) == 1){
		if(*p1_choice < 0 || *p1_choice > 25){
			*p1_choice =  rand_num(isATK);
		}
	}else if((isATK%2) == 0){
		if(*p1_choice < 1 || *p1_choice > 25){
			*p1_choice =  rand_num(isATK);
		}
	}else{
		printf("[ERROR] in _check_choice");
	}
}

int user_choice(struct Team *currTeam, int isATK, int *currPlayerId){
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList;
// 	pass the first one
	currPlayer = currPlayer->nextAddr;
	// �w�쥿�T����
	while(
		currPlayer->nextAddr != NULL && 
		currPlayer->identity != *currPlayerId
	){
		currPlayer = currPlayer->nextAddr;
	}
	int p1_choice = 999;
	if((isATK%2) == 1){
		//�N�������[��ܥ���] 
		printf("%s �Φ� %d(%s)���� (�п��1~25�A�p�G�����Ϋh��J0):",
			currTeam->name,
			currPlayer->identity,	
			currPlayer->name
		);
		scanf(" %d", &p1_choice);
		_check_choice(&p1_choice, isATK);
	}else if ((isATK%2) == 0){
		//�q�����
		while(currPlayer->nextAddr != NULL){
			currPlayer = currPlayer->nextAddr;
		} 
		//�N���u��[��ܧ��] 
		printf("%s ��� %s ��y(�п��1~25):", currTeam->name, currPlayer->name);
		scanf(" %d", &p1_choice);
		_check_choice(&p1_choice, isATK);
	}else{
		perror("[ERROR] in game.h=>user_choice");
	}
	return p1_choice;
}
