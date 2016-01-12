#include "head.h" 
#include "struct.h"
#include "game.h"

/*
 *	Date:	2015/12/25 
 *	Autor:	@�\��� 
 *	ID:	D0182315 
 *  ProjectName:	�βy�p�C��
 *  
 */ 

void _showRule(){
	int input = 0;
	while(input != -1){
		printf("[�W�h����]\n");
		printf("=============================\n");
		printf("�C���}�l�ɷ|�X�{�H�U�e��\n");
		printf("\t ����/���Ͽ��\n");
		printf("\t01 02 03 04 05\n");
		printf("\t06 07 08 09 10\n");
		printf("\t11 12 13 14 15\n");
		printf("\t16 17 18 19 20\n");
		printf("\t21 22 23 24 25\n");
		printf("���a�o�ɷ|��� 0-25 �������Χ�y�����\n");
		printf("�Y�Ʀr�H�N��J����, �t�η|�H���Ʀr\n");
		printf("�o�˼v�T���ƥi�O���n����~\n");
		printf("=============================\n");
		printf("Ū���W�h��A�п�J -1 ���^�h\n");
		scanf(" %d", &input);
	}
	system("cls");
}

void _showChoice(){
	printf("\n=============================\n");
	printf("[1] �}�l�C��\n");
	printf("[2] �إ߶���\n");
	printf("[3] ��ܲy����T\n");
	printf("[4] ��ܤW���ɪp\n");
	printf("[5] ��ܹC���W�h\n");
	printf("[6] �����C��\n");
	printf("=============================\n");
	printf("�z�����:");
}

int _getChoice(){
	int choice;
	scanf("%d", &choice);
	return choice;
}

void _change_game_mode(int *game_mode){
	printf("[��ܹC���Ҧ�]\n");
	printf("0: �q�� vs�q�� 1:�H vs�q�� 2: �Hvs�H \n");
	printf("�A����ܬO:\n");
	*game_mode = _getChoice();
}

int main(){
	//���� struct.h �B�@���` 
	printf("�ݨ�o��N��struct.h �B�@���`\n", test_struct);
	//���� game.h  �B�@���`
	printf("�ݨ�o��N��game.h �B�@���`\n", test_game);
	printf("**********************\n");
	printf("�{���}�Ҥ�...\n");
	printf("�C���Y�N�}�l\n");
	printf("�C������ v%s\n", _GAME_VERSION_);
	Sleep(2000);
	system("cls");
	// �إ߶��� 
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
						printf("�|�������ƥ��إߡA�L�k�}�l�C��\n");
						break;
				}else{
					// ��ܹC������ 
					_change_game_mode(&game_mode);
					show_game_interface(team_one, team_two, game_mode);
				}
				break;
			case 2:
				system("cls");
				printf("�Ĥ@��");
 				create_team_name_of(team_one);
 				printf("�ĤG��");
 				create_team_name_of(team_two);
				create_players_of(team_one);
				create_players_of(team_two);
				system("cls");
				printf("����إߦ��\\n") ;
				break;
			case 3:
				system("cls");
				if(team_one->PlayersList == NULL || team_two->PlayersList == NULL){
						printf("�|�������ƥ��إߡA�L�k��ܲy�����A\n");
						break;
				}else{
					show_players_situation_of(team_one);
					show_players_situation_of(team_two);
				}
				break;
			case 4:
				system("cls");
				if(team_one->PlayersList == NULL || team_two->PlayersList == NULL){
						printf("�|�������ƥ��إߡA�L�k��ܤW���ɪp\n");
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
				printf("switch case �줣��z�����\n");
		}
	}
	return 0;
}
