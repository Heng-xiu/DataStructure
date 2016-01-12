#include "head.h"  

/* 測試用變數 */
int test_struct = 666;

/*
 *	Players	球員 
 *	create_players_of(struct Team *test)		.建立球員名稱 
 *	show_players_situation_of(struct Team *test).顯示打者情況(安打數 | 全壘打數 | 被三振數 | 被四壞數) 
 *												.顯示投手情況(好球數 | 壞球數 | 被安打數 | 被全壘打數) 
 *
 *	Team	球隊
 *	create_team_name_of(struct Team *test)		.建立球隊名稱 
 *	show_team_name_of(struct Team *test)		.顯示球隊名稱 
 */

struct Players{
	char name[200];			//名字 
	int hit;				//安打數 
	int homeRun;			//全壘打數 
	int strikeOut;			//被三振出局數 
	int baseOnBall;			//被四壞保送數 
	int strike;				//好球數
	int ball;				//壞球數 
	int beHit;				//被安打數 
	int beHomeRun;			//被全壘打數 
	int identity;			//身分 Ex:投手:10, 打擊手:1..9 
	struct Players *nextAddr;	//	下一個球員的位址 
};

struct Team{
	char name[200];			//隊名 
	int	score[9];			// 第N局 的分數, ex:第1局為三分==> score[0]=3 
	struct Players *PlayersList;//	球員清單首項的位址 
};

struct Innings{
	int now;		//第 N 局比賽
	int strike;		//第 N 局比賽	好球數 (<=3) 
	int ball;		//第 N 局比賽	壞球數 (<=4)
	int out;		//第 N 局比賽	出局數 (<=3) 
};

void create_team_name_of(struct Team *currTeam){
	printf("隊伍名稱:");
	scanf("%s", &(currTeam->name));
	for(int i=0; i < _MAX_INNINGS_;i++){
		currTeam->score[i] = 0;
	}
}

void show_team_name_of(struct Team *currTeam){
	printf("隊伍名稱: %s\n", currTeam->name);
}

void create_players_of(struct Team *currTeam){
	printf("[請輸入 %s 棒次人員與投手名稱]\n", currTeam->name);
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currTeam->PlayersList = currPlayer;
 	currPlayer->nextAddr = NULL;
 	int num_of_players = 1;
 	while(num_of_players != 1+10){
 		// create temp player
 		struct Players *tmpPlayer;
 		tmpPlayer = (Players*)malloc(sizeof(Players));
 		tmpPlayer->nextAddr = NULL;
 		tmpPlayer->ball = 0;
 		tmpPlayer->baseOnBall = 0;
 		tmpPlayer->beHit = 0;
 		tmpPlayer->beHomeRun = 0;
 		tmpPlayer->hit = 0;
 		tmpPlayer->homeRun = 0;
 		tmpPlayer->strike = 0;
 		tmpPlayer->strikeOut = 0;
 		// locate to last node
 		while(currPlayer->nextAddr != NULL){
 			currPlayer = currPlayer->nextAddr;
		}
 		if(num_of_players == 10){
 			printf("投手:");
 			scanf(" %s", &(tmpPlayer->name));
 			tmpPlayer->identity = 10;		//代表投手 
		}else {
			printf("第%2d號打者:", num_of_players);
			scanf(" %s", &(tmpPlayer->name));
			tmpPlayer->identity = num_of_players;	//代表第 N 打者 
		}
		currPlayer->nextAddr = tmpPlayer;
 		num_of_players++;
	 }
}

void show_players_situation_of(struct Team *currTeam){
	//init
	printf("\n[顯示投手與打者情況]==> %s隊\n", currTeam->name);
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList;
	// pass the first one
	currPlayer = currPlayer->nextAddr;
	// 顯示打者情況 
	printf("打者情況(安打數 | 全壘打數 | 被三振數 | 被四壞數)\n");
	while(currPlayer->nextAddr != NULL){
		printf("%2d. %s (%2d|%2d|%2d|%2d)\n",
			currPlayer->identity,
			currPlayer->name,
			currPlayer->hit,
			currPlayer->homeRun,
			currPlayer->strikeOut,
			currPlayer->baseOnBall
		);
		currPlayer = currPlayer->nextAddr;
	}
	// 顯示投手情況
	printf("\n投手表現(好球數 | 壞球數 | 被安打數 | 被全壘打數)\n");
	printf("%2d. %s (%2d|%2d|%2d|%2d)\n", 
		currPlayer->identity,
		currPlayer->name,
		currPlayer->strike,
		currPlayer->ball,
		currPlayer->beHit,
		currPlayer->beHomeRun
	);
}

