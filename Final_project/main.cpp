#include "head.h" 
#include "struct.h"
#include "game.h"

/*
 *	Date:	2015/12/25 
 *	Autor:	@許恆修 
 *	ID:	D0182315 
 *  ProjectName:	棒球小遊戲
 *  
 */ 

void _showRule(){
	int input = 0;
	while(input != -1){
		printf("[規則說明]\n");
		printf("=============================\n");
		printf("遊戲開始時會出現以下畫面\n");
		printf("\t 打擊/投手區選擇\n");
		printf("\t01 02 03 04 05\n");
		printf("\t06 07 08 09 10\n");
		printf("\t11 12 13 14 15\n");
		printf("\t16 17 18 19 20\n");
		printf("\t21 22 23 24 25\n");
		printf("玩家這時會選擇 0-25 做打擊或投球的選擇\n");
		printf("若數字隨意輸入的話, 系統會隨機數字\n");
		printf("這樣影響分數可是不好的喔~\n");
		printf("=============================\n");
		printf("讀完規則後，請輸入 -1 方能回去\n");
		scanf(" %d", &input);
	}
	system("cls");
}

void _showChoice(){
	printf("\n=============================\n");
	printf("[1] 開始遊戲\n");
	printf("[2] 建立隊伍\n");
	printf("[3] 顯示球員資訊\n");
	printf("[4] 顯示上局賽況\n");
	printf("[5] 顯示遊戲規則\n");
	printf("[6] 結束遊戲\n");
	printf("=============================\n");
	printf("您的選擇:");
}

int _getChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
}

void _change_game_mode(int *game_mode){
	printf("[選擇遊玩模式]\n");
	printf("0: 電腦 vs電腦 1:人 vs電腦 2: 人vs人 \n");
	printf("你的選擇是:\n");
	*game_mode = _getChoice();
}

int main(){
	//測試 struct.h 運作正常 
	printf("看到這行代表struct.h 運作正常\n", test_struct);
	//測試 game.h  運作正常
	printf("看到這行代表game.h 運作正常\n", test_game);
	printf("**********************\n");
	printf("程式開啟中...\n");
	printf("遊戲即將開始\n");
	printf("遊戲版本 v%s\n", _GAME_VERSION_);
	Sleep(2000);
	system("cls");
	// 建立隊伍 
	struct Team *team_one;
 	team_one = (Team*)malloc(sizeof(Team));
 	team_one->PlayersList = NULL; 
 	struct Team *team_two;
 	team_two = (Team*)malloc(sizeof(Team));
 	team_two->PlayersList = NULL;
 	int game_mode = 1;
	
	while(1){
		_showChoice();
		switch(_getChoice()){
			case 1:
				system("cls");
				if(team_one->PlayersList == NULL || team_two->PlayersList == NULL){
						printf("尚有隊伍資料未建立，無法開始遊戲\n");
						break;
				}else{
					// 顯示遊戲介面 
					_change_game_mode(&game_mode);
					show_game_interface(team_one, team_two, game_mode);
				}
				break;
			case 2:
				system("cls");
				printf("第一支");
 				create_team_name_of(team_one);
 				printf("第二支");
 				create_team_name_of(team_two);
				create_players_of(team_one);
				create_players_of(team_two);
				system("cls");
				printf("隊伍建立成功\n") ;
				break;
			case 3:
				system("cls");
				if(team_one->PlayersList == NULL || team_two->PlayersList == NULL){
						printf("尚有隊伍資料未建立，無法顯示球員狀態\n");
						break;
				}else{
					show_players_situation_of(team_one);
					show_players_situation_of(team_two);
				}
				break;
			case 4:
				system("cls");
				if(team_one->PlayersList == NULL || team_two->PlayersList == NULL){
						printf("尚有隊伍資料未建立，無法顯示上局賽況\n");
						break;
				}else{
					show_game_score(team_one, team_two);
				}
				break;
			case 5:
				system("cls");
				_showRule();
				break;
			case 6:
				exit(0);
				break;
			default:
				system("cls");
				printf("switch case 抓不到您的選擇\n");
		}
	}
	return 0;
}
