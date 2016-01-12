#include "head.h"  

/* ���ե��ܼ� */
int test_struct = 666;

/*
 *	Players	�y�� 
 *	create_players_of(struct Team *test)		.�إ߲y���W�� 
 *	show_players_situation_of(struct Team *test).��ܥ��̱��p(�w���� | ���S���� | �Q�T���� | �Q�|�a��) 
 *												.��ܧ�ⱡ�p(�n�y�� | �a�y�� | �Q�w���� | �Q���S����) 
 *
 *	Team	�y��
 *	create_team_name_of(struct Team *test)		.�إ߲y���W�� 
 *	show_team_name_of(struct Team *test)		.��ܲy���W�� 
 */

struct Players{
	char name[200];			//�W�r 
	int hit;				//�w���� 
	int homeRun;			//���S���� 
	int strikeOut;			//�Q�T���X���� 
	int baseOnBall;			//�Q�|�a�O�e�� 
	int strike;				//�n�y��
	int ball;				//�a�y�� 
	int beHit;				//�Q�w���� 
	int beHomeRun;			//�Q���S���� 
	int identity;			//���� Ex:���:10, ������:1..9 
	struct Players *nextAddr;	//	�U�@�Ӳy������} 
};

struct Team{
	char name[200];			//���W 
	int	score[9];			// ��N�� ������, ex:��1�����T��==> score[0]=3 
	struct Players *PlayersList;//	�y���M�歺������} 
};

struct Innings{
	int now;		//�� N ������
	int strike;		//�� N ������	�n�y�� (<=3) 
	int ball;		//�� N ������	�a�y�� (<=4)
	int out;		//�� N ������	�X���� (<=3) 
};

void create_team_name_of(struct Team *currTeam){
	printf("����W��:");
	scanf("%s", &(currTeam->name));
	for(int i=0; i < _MAX_INNINGS_;i++){
		currTeam->score[i] = 0;
	}
}

void show_team_name_of(struct Team *currTeam){
	printf("����W��: %s\n", currTeam->name);
}

void create_players_of(struct Team *currTeam){
	printf("[�п�J %s �Φ��H���P���W��]\n", currTeam->name);
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
 			printf("���:");
 			scanf(" %s", &(tmpPlayer->name));
 			tmpPlayer->identity = 10;		//�N���� 
		}else {
			printf("��%2d������:", num_of_players);
			scanf(" %s", &(tmpPlayer->name));
			tmpPlayer->identity = num_of_players;	//�N��� N ���� 
		}
		currPlayer->nextAddr = tmpPlayer;
 		num_of_players++;
	 }
}

void show_players_situation_of(struct Team *currTeam){
	//init
	printf("\n[��ܧ��P���̱��p]==> %s��\n", currTeam->name);
	struct Players *currPlayer;
 	currPlayer = (Players*)malloc(sizeof(Players));
 	currPlayer = currTeam->PlayersList;
	// pass the first one
	currPlayer = currPlayer->nextAddr;
	// ��ܥ��̱��p 
	printf("���̱��p(�w���� | ���S���� | �Q�T���� | �Q�|�a��)\n");
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
	// ��ܧ�ⱡ�p
	printf("\n����{(�n�y�� | �a�y�� | �Q�w���� | �Q���S����)\n");
	printf("%2d. %s (%2d|%2d|%2d|%2d)\n", 
		currPlayer->identity,
		currPlayer->name,
		currPlayer->strike,
		currPlayer->ball,
		currPlayer->beHit,
		currPlayer->beHomeRun
	);
}

