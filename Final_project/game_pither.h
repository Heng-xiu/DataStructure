#include "head.h" 

/*
 *	投手演算法	 
 *	pither_algo(
		struct Team *currTeam, 		隊伍 
		int	def_choice				守方投手選擇數值s 
	)
 *	
 */

void pither_algo(struct Team *currTeam, int def_choice){
	// 使用 球員
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList; 
 	// 	pass the first one
	currPlayer = currPlayer->nextAddr;
	//訂位到投手
	while(currPlayer->nextAddr != NULL){
		currPlayer = currPlayer->nextAddr;
	}
	if(
		def_choice == 7 ||
		def_choice == 8 ||
		def_choice == 9 ||
		def_choice == 12 ||
		def_choice == 13 ||
		def_choice == 14 ||
		def_choice == 17 ||
		def_choice == 18 ||
		def_choice == 19 
	){
		// 好球帶 
		currPlayer->strike += 1; 
		printf("[投手] 投出了一記好球!\n");
		Sleep(1200);
	}else{
		// 壞球帶 
		currPlayer->ball += 1; 
		printf("[投手] 投出了一記壞球!\n");
		Sleep(1200);
	}
}
