#include "head.h" 

/*
 *	���t��k	 
 *	pither_algo(
		struct Team *currTeam, 		���� 
		int	def_choice				�u�����ܼƭ�s 
	)
 *	
 */

void pither_algo(struct Team *currTeam, int def_choice){
	// �ϥ� �y��
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList; 
 	// 	pass the first one
	currPlayer = currPlayer->nextAddr;
	//�q�����
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
		// �n�y�a 
		currPlayer->strike += 1; 
		printf("[���] ��X�F�@�O�n�y!\n");
		Sleep(1200);
	}else{
		// �a�y�a 
		currPlayer->ball += 1; 
		printf("[���] ��X�F�@�O�a�y!\n");
		Sleep(1200);
	}
}
