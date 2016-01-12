#include "head.h"

/*
 *	show_state(int , int , struct Team , struct Team)	.顯示第幾局.上下半場.兩隊比分. 
 *	show_strike_ball_out(int , int , int )			  	.顯示當前好球/壞球數/出局數 
 *  show_base(char , char , char , char)				.顯示一壘二壘三壘狀態	 
 *  show_bat_area(int)									.顯示打擊區與選擇揮棒位置 
 *	show_game_score(struct Team , struct Team)			.顯示每隊每局比分狀況 
 *
 */ 

int _sum_score_of(struct Team *currTeam){
	// 計算 currTeam 的總分 
	int sum = 0;
	for(int index=0; index < _MAX_INNINGS_ ;index++){
		sum = sum + currTeam->score[index];
	}
	return sum;
}

void _show_all_inngins_score_of(struct Team *curr_Team){
	int sum = 0;
	printf("%s\t\t|", curr_Team->name);
	for(int index=0; index < _MAX_INNINGS_ ;index++){
		printf("%2d|", curr_Team->score[index]);
		sum = sum + curr_Team->score[index];
	}
	printf("%8d|\n", sum);
}
 
void show_state(struct Innings *innings, int isFirstHalf, struct Team *first_Team, struct Team *sec_Team){
	int first_score = _sum_score_of(first_Team);
	int sec_score = _sum_score_of(sec_Team);
	printf("第%2d局 ", innings->now);
	if((isFirstHalf%2) == 1){
		printf("上 ");
	}else if((isFirstHalf%2) == 0){
		printf("下 ");
	}else {
		printf("卡 ");
	}
	printf("%s %2d:%2d %s\n", first_Team->name,	first_score, sec_score, sec_Team->name);
}

void show_strike_ball_out(struct Innings *innings){
	printf("球數\t好球:%d 壞球:%d 出局: %d\n", innings->strike, innings->ball, innings->out);
}

void show_base(int base_state){
	char base_base[] = "◎";	//壘包狀態 ◎:本壘 ●:壘包有人 ○:壘包沒人
	char first_base[] = "○";		 
	char secend_base[] = "○";
	char third_base[] = "○";
	
	if(base_state == 1 || base_state == 3 || base_state == 5 || base_state == 7){
		strcpy(first_base, "●");  // str2字串複製給str1字串 
	}else {
		strcpy(first_base, "○");
	}
	
	if(base_state == 2 || base_state == 3 || base_state == 6 || base_state == 7){
		strcpy(secend_base, "●");  // str2字串複製給str1字串 
	}else{
		strcpy(secend_base, "○");
	}
	
	if(base_state == 4 || base_state == 5 || base_state == 6 || base_state == 7){
		strcpy(third_base, "●");  // str2字串複製給str1字串 
	}else{
		strcpy(third_base, "○");
	}
	
	printf("壘包\n");
	printf("\t\t%s\n", secend_base);
	printf("\n");
	printf("\t%s\t\t%s\n", third_base, first_base);
	printf("\n");
	printf("\t\t%s\n", base_base);
}

void show_bat_area(int isATK){
	printf("----------------------------\n");
	if((isATK%2) == 0){
		//防守方 
		printf("\t  投球區選擇\n");
	}else if((isATK%2) == 1){
		//攻擊方 
		printf("\t  打擊區選擇\n");
	}else {
		perror("[ERROR] in show_bat_area()\n");
	}
	printf("\t01 02 03 04 05\n");
	printf("\t06 07 08 09 10\n");
	printf("\t11 12 13 14 15\n");
	printf("\t16 17 18 19 20\n");
	printf("\t21 22 23 24 25\n");
}

void show_game_score(struct Team *first_Team, struct Team *sec_Team){
	if(first_Team->name == NULL || sec_Team->name == NULL){
		perror("[ERROR]放棄吧!你沒有隊伍\n");
	}
	int sum = 0;
	printf("球隊/局數\t| 1| 2| 3| 4| 5| 6| 7| 8| 9|最終比分|\n");
	_show_all_inngins_score_of(first_Team);
	_show_all_inngins_score_of(sec_Team);
}

void show_all_info(
	struct Innings *innings,
	int isFirstHalf, 
	struct Team *first_Team, 
	struct Team *sec_Team,
	int base_state,
	int isATK
	){
		system("CLS");
		show_state(innings, isFirstHalf, first_Team, sec_Team);
		show_strike_ball_out(innings);
		show_base(base_state);
		show_bat_area(isATK);
}
