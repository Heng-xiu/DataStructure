#include "head.h"  
#include "game_info.h"
#include "game_batter.h"
#include "game_pither.h"
#include "game_choice.h"

/* 測試用變數 */
int test_game = 555;

/*	顯示遊戲介面 
 *	show_game_interface(struct Team *first_Team, struct Team *sec_Team, int game_mode)
 *	game_mode=> 0: 電腦 vs電腦 1:人 vs電腦 2: 人vs人(開發中)	
 */ 

void _swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;                                                                                             
}

void show_game_interface(struct Team *first_Team, struct Team *sec_Team, int game_mode){
	struct Innings *innings;
 	innings = (Innings*)malloc(sizeof(Innings));
 	innings->now = 1;
 	innings->strike = 0;
 	innings->ball = 0;
 	innings->out = 0;

	int isFirstHalf	= 1;			//上半場 :1, 下半場:0  
	int	base_state = 0;				//壘包狀態二進為表示法 
	int isATK = 1;				//表當下操作者為攻方or守方 攻方:1 守方:0 
	int p1_choice = 0;
	int com_choice = 0;
	int currPlayerId = 1;
	int currPlayerId_backup = currPlayerId;
	
	struct Team *atk_Team;
	struct Team *def_Team;
	int atk_choice;
	int def_choice;
	
	while(innings->now != _MAX_INNINGS_ + 1){
		// 玩家操作第一隊伍 
		show_all_info(innings, isFirstHalf, first_Team, sec_Team, base_state, isATK);
		if(game_mode == 0){			
			p1_choice = rand_num(isATK);
			Sleep(619);
		}else if(game_mode == 1 || game_mode == 2){
			p1_choice = user_choice(first_Team, isATK, &currPlayerId);
		}
		// 電腦亂數取值
		show_all_info(innings, isFirstHalf, first_Team, sec_Team, base_state, isATK);
		if(game_mode == 2){
			com_choice = user_choice(sec_Team, isATK+1, &currPlayerId);
		}else{
			com_choice = rand_num(isATK);
		}		
		
		if((isATK%2) == 1){
			atk_Team = first_Team;
			def_Team = sec_Team;
			atk_choice = p1_choice;
			def_choice = com_choice;
		}else if ((isATK%2) == 0){
			atk_Team = sec_Team;
			def_Team = first_Team;
			atk_choice = com_choice;
			def_choice = p1_choice;
		}
		
		pither_algo(def_Team ,def_choice);
		batter_algo(
			atk_Team, 
			currPlayerId, 
			atk_choice, 
			def_choice, 
			innings,
			&base_state
		); 
		
		// 更換打者 
		if(innings->strike >= 3 || innings->ball == 4){
			currPlayerId += 1;
			if(currPlayerId == 10) {
				// 打者輪完一圈 
				currPlayerId = 1;
			}
			innings->strike = 0;
			innings->ball = 0;
		}
		// 攻守交換
		if(innings->out == 3) {					
			isFirstHalf += 1 ;
			if((isFirstHalf%2) == 1){
				innings->now += 1;
			}
			innings->out = 0;
			isATK += 1;
			_swap(&currPlayerId_backup, &currPlayerId);
			base_state = 0;
		}
	}
	system("cls");
}
 
