#include "head.h"

/*
 *  rand_num(int isATK)	.隨機取得亂數值 1-25 || 0-25 取決isATK 
 *  user_choice(struct Team *currTeam, int isATK, int *currPlayerId)	.玩家或電腦的選擇 
 */

int rand_num(int isATK){
	int var;
 	srand(time(NULL));
 	if((isATK%2) == 1){
 		// 電腦為打者	[攻] 
 		var=(rand()%25);	//0-25
	}else if((isATK%2) == 0){
		// 電腦為投手 	[守]
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
	// 定位正確打者
	while(
		currPlayer->nextAddr != NULL && 
		currPlayer->identity != *currPlayerId
	){
		currPlayer = currPlayer->nextAddr;
	}
	int p1_choice = 999;
	if((isATK%2) == 1){
		//代表攻擊方[顯示打者] 
		printf("%s 棒次 %d(%s)打擊 (請選擇1~25，如果不揮棒則輸入0):",
			currTeam->name,
			currPlayer->identity,	
			currPlayer->name
		);
		scanf(" %d", &p1_choice);
		_check_choice(&p1_choice, isATK);
	}else if ((isATK%2) == 0){
		//訂位到投手
		while(currPlayer->nextAddr != NULL){
			currPlayer = currPlayer->nextAddr;
		} 
		//代表防守方[顯示投手] 
		printf("%s 投手 %s 投球(請選擇1~25):", currTeam->name, currPlayer->name);
		scanf(" %d", &p1_choice);
		_check_choice(&p1_choice, isATK);
	}else{
		perror("[ERROR] in game.h=>user_choice");
	}
	return p1_choice;
}
