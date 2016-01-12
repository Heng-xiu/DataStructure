#include "head.h"  
#include "game_info.h"
#include "game_batter.h"
#include "game_pither.h"
#include "game_choice.h"

/* ���ե��ܼ� */
int test_game = 555;

/*	��ܹC������ 
 *	show_game_interface(struct Team *first_Team, struct Team *sec_Team, int game_mode)
 *	game_mode=> 0: �q�� vs�q�� 1:�H vs�q�� 2: �Hvs�H(�}�o��)	
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

	int isFirstHalf	= 1;			//�W�b�� :1, �U�b��:0  
	int	base_state = 0;				//�S�]���A�G�i����ܪk 
	int isATK = 1;				//���U�ާ@�̬����or�u�� ���:1 �u��:0 
	int p1_choice = 0;
	int com_choice = 0;
	int currPlayerId = 1;
	int currPlayerId_backup = currPlayerId;
	
	struct Team *atk_Team;
	struct Team *def_Team;
	int atk_choice;
	int def_choice;
	
	while(innings->now != _MAX_INNINGS_ + 1){
		// ���a�ާ@�Ĥ@���� 
		show_all_info(innings, isFirstHalf, first_Team, sec_Team, base_state, isATK);
		if(game_mode == 0){			
			p1_choice = rand_num(isATK);
			Sleep(619);
		}else if(game_mode == 1 || game_mode == 2){
			p1_choice = user_choice(first_Team, isATK, &currPlayerId);
		}
		// �q���üƨ���
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
		
		// �󴫥��� 
		if(innings->strike >= 3 || innings->ball == 4){
			currPlayerId += 1;
			if(currPlayerId == 10) {
				// ���̽����@�� 
				currPlayerId = 1;
			}
			innings->strike = 0;
			innings->ball = 0;
		}
		// ��u�洫
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
 
