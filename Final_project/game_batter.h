#include "head.h" 

/*
 *	打者演算法	 
 *	batter_algo(
		struct Team *currTeam, 		隊伍 
		int currPlayerId, 			當前球員編號 
		int atk_choice, 			攻方選擇 
		int def_choice, 			守方選擇 
		struct Innings *innings		該局所有資訊 
		int *base_state				紀錄壘包狀態數值 ，以二進位思考 
	)
 *	
 */

int _rand_base_hit(){
	// 打出幾壘安打 
	int var;
 	srand(time(NULL));
 	var=(rand()%3)+1;	//1-3 
 	return var;
}

int _is_pot_put(){
	// 是否成功接殺 
	int var;
 	srand(time(NULL));
 	var=(rand()%2)+1;	//1: 接殺出局 2:沒有接殺出局 
 	return var;
}

void _shift_base(int *base_state, int shift_time, struct Team *currTeam, struct Innings *innings){
	// 球員移動前進多少壘包, 使用二進位思考 
	int isShift = 0;
	for(int index=0 ; index < shift_time ; index++){
		if(*base_state >= 4){
			currTeam->score[innings->now] += 1;
		}
		*base_state = *base_state << 1;
		*base_state = *base_state & 7;
		if(isShift == 0){
			*base_state += 1;
			isShift = 1;
		}
	}
}

int _batter_judge_HR_Hit_ball_strike(int atk_choice, int def_choice){
	// HomeRun: 1, Hit: 2, Ball: 3, Strike: 4
//	printf("atk_choice= %d, def_choice= %d\n", atk_choice, def_choice) ;
	if(
		atk_choice != 0 &&
		def_choice != 0 && 
		atk_choice == def_choice
	){
		return 1;
	}else if(
		(atk_choice != 0) &&
		((atk_choice == def_choice - 5) ||
		(atk_choice == def_choice + 5) ||
		(atk_choice == def_choice - 1) ||
		(atk_choice == def_choice + 1) )
	){
		return 2;
	}else if(
		atk_choice == 0 &&
		def_choice != 7 &&
		def_choice != 8 &&
		def_choice != 9 &&
		def_choice != 12 &&
		def_choice != 13 &&
		def_choice != 14 &&
		def_choice != 17 &&
		def_choice != 18 &&
		def_choice != 19 
	){
		return 3;
	}else{
		return 4;
	}
}

void _batter_hit_homerun(
		struct Team *currTeam, 
		struct Players *currPlayer,
		struct Innings *innings,
		int *base_state
	){
		printf("[打者] 敲出了全壘打!\n");
		Sleep(900);
		printf("球飛的好高好遠, 就跟變心的女友一樣, 回不來啦QQ\n");
		Sleep(1300);
 		currTeam->score[innings->now-1] += 1;
		currPlayer->homeRun += 1; 
		innings->strike = 3;
		switch(*base_state){
			case 0:
				break;
			case 1:
			case 2:
			case 4:
				currTeam->score[innings->now-1] += 1;
				break;
			case 3:
			case 5:
			case 6:
				currTeam->score[innings->now-1] += 2;
				break;
			case 7:
				currTeam->score[innings->now-1] += 3;
				break;
			default:
				printf("全壘打判斷錯誤\n");
	}
	*base_state = 0;
}

void _batter_hit_hit(
		struct Team *currTeam,
		struct Players *currPlayer,
		struct Innings *innings,
		int *base_state
	){
		currPlayer->hit += 1;
		innings->strike = 3;
		int which_base_hit = _rand_base_hit();
		printf("球飛出去了，飛得高高的\n");
		Sleep(1500);
		if(
			which_base_hit == 2 || 
			which_base_hit == 3 && 
			_is_pot_put() == 1
		){
			innings->out += 1; 
			printf("被外野手接殺出局啦!\n");
			Sleep(1500);
		}else {
			printf("==> 這是一支 %d壘安打 <==\n", which_base_hit);
			Sleep(1500);
			_shift_base(&*base_state, which_base_hit, &*currTeam, innings);
		}
}

void _batter_hit_ball(
		struct Team *currTeam,
		struct Players *currPlayer,
		struct Innings *innings,
		int *base_state
	){
		printf("[打者] 沒有揮出棒子\n");
		innings->ball += 1; 
		if(innings->ball == 4){ 
			currPlayer->baseOnBall += 1; 
			_shift_base(&*base_state, 1, &*currTeam, innings);
			printf("[打者] 四壞保送上壘去!!\n");
		}
		Sleep(1500) ;
}

void _batter_hit_strike(
		struct Players *currPlayer,
		struct Innings *innings,
		int atk_choice
	){	
		if(atk_choice == 0){
			printf("[打者] 選擇不揮棒\n");
		}else{
			printf("[打者] 揮棒落空!!\n");
		}
		innings->strike += 1;
		if(innings->strike == 3) {
			printf("[打者] 三振出局~~\n");
			currPlayer->strikeOut += 1 ;
			innings->out += 1;
		}
		Sleep(1500) ;
}

void batter_algo(
		struct Team *currTeam, 
		int currPlayerId, 
		int atk_choice, 
		int def_choice, 
		struct Innings *innings,
		int *base_state
	){
	// 使用 球員
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList; 
 	// 	pass the first one
	currPlayer = currPlayer->nextAddr;
 	// 定位正確打者
	while(
		currPlayer->nextAddr != NULL && 
		currPlayer->identity != currPlayerId
	){
		currPlayer = currPlayer->nextAddr;
	}
 	// 判斷為好球/壞球/安打/全壘打 
 	int kind_of_ball = _batter_judge_HR_Hit_ball_strike(atk_choice, def_choice);
 	switch(kind_of_ball){
 		case 1:
 			_batter_hit_homerun(currTeam, currPlayer, innings, base_state);
			break;	
		case 2:
			_batter_hit_hit(currTeam, currPlayer, innings, base_state);
			break;
		case 3:
			_batter_hit_ball(currTeam, currPlayer, innings, base_state);
			break;
		case 4:
			_batter_hit_strike(currPlayer, innings, atk_choice);
			break;
		default :
			printf("打者演算法出現錯誤\n");
			break;
	}
}
