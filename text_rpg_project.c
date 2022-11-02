#include <stdio.h>
#include <time.h>// 랜덤함수
#include <windows.h> // Sleep 함수 사용을 위한 것

//전역변수 선언
static int Exit = 0; // 종료변수
int Mob_Hp = 150;
int player_Hp = 175;
int player_sp = 225;
//함수 선언
int Choose(void);
int Mob_Attack(void);
int Player_Skill_Select(void);

int main(void) {

	int choose;
	while (1)
	{

		srand(time(NULL)); // srand 값 초기화(랜덤값 초기화)
		printf("\n\n\n  야생 피카츄 HP : %d  \n\n", Mob_Hp);
		printf("\n\n\n  플레이어 파이리 HP : %d    SP : %d \n\n", player_Hp, player_sp);
		//메뉴 번호 입력
		Choose();
		if (player_Hp <= 0) { // 플레이어의 HP이 마이너스로 표시되는 것을 방지 (게임종료)
			player_Hp = 0;
			Exit += 1;
		}
		if (Mob_Hp <= 0) { // 적의 HP이 마이너스로 표시되는 것을 방지 (게임종료)
			Mob_Hp = 0;
			Exit += 1;
		}
		if (Exit >= 1) // 종료변수가 1이상일시 게임종료
		{
			printf("\n\n  게임을 종료합니다 \n\n");
			break;
		}
		Sleep(1000);
		Mob_Attack();
		Sleep(1000);
	}

	return 0;
}



int Choose(void) //메뉴 선택 함수
{
	printf("\n\n##   1. 기술   2. 종료   ##\n\n");
	int menu_Select;
	scanf("%d", &menu_Select);
	switch (menu_Select) {
	case 1:
		Player_Skill_Select();
		return 0;
	case 2:
		Exit += 1; // 게임종료
		return 0;
	default:
		printf("\n   잘못된 값입니다. 다시 입력해주세요.  \n ");
		Choose();
	}

}

int Player_Attack_Scratch(void)  // 플레이어 데미지 계산 및 메시지 출력 함수
{
	int attack_damage = 5; // 5 고정
	Mob_Hp -= attack_damage; // 적 HP를 데미지값만큼 차감
	printf("\n\n  마구할퀴기로 인해 피카츄에게 %d 데미지를 입혔다 \n\n", attack_damage); // 메시지 출력

}


int Player_Attack_Fiame(void)  // 플레이어 데미지 계산 및 메시지 출력 함수
{
	int attack_damage = rand() % (15) + 20; // 20~35 랜덤값 설정
	Mob_Hp -= attack_damage; // 적 HP를 데미지값만큼 차감
	printf("\n\n  화염방사로 인해 피카츄에게 %d 데미지를 입혔다 \n\n", attack_damage); // 메시지 출력

}


int Player_Attack_Crash(void)  // 플레이어 데미지 계산 및 메시지 출력 함수
{
	int attack_damage = rand() % (10) + 10; // 10~20 랜덤값 설정
	Mob_Hp -= attack_damage; // 적 HP를 데미지값만큼 차감
	printf("\n\n 몸통박치기로 인해 피카츄에게 %d 데미지를 입혔다 \n\n", attack_damage); // 메시지 출력

}


int Mob_Attack(void)  // 적 데미지 계산 및 메시지 출력 함수
{
	int Mob_attack_damage = rand() % (15) + 15; // 15~30 랜덤값 설정
	player_Hp -= Mob_attack_damage; // 플레이어 HP를 데미지값만큼 차감
	if (Mob_Hp < 38) {				//적의 체력이 절반으로 떨어질 때 추가데미지
		player_Hp -= 3;
	}
	printf("\n\n  피카츄의 십만볼트로 인해 파이리가 %d 데미지를 입었다 \n\n", Mob_attack_damage); // 메시지 출력

}


int Player_heal(void)  // 플레이어 회복
{
	player_Hp += 40; // HP 40 증가
	if (player_Hp > 150) { // 플레이어 HP가 최대 HP 초과되지 않도록 고정
		player_Hp = 150;
	}
	printf("\n\n 플레이어의 파이리가 40 HP를 회복했다  \n\n"); // 메시지 출력
}


int Player_Skill_Select(void) //스킬 선택 창
{
	int Skill = 0;
	printf("\n\n####   1. 화염방사 (20 ~ 35 데미지 30sp)       2. 몸통박치기 (20 ~ 30 데미지 20sp) ####\n\n");
	printf("\n\n####   3. 마구할퀴기(5 데미지로 3번 공격 30sp) 4. 회복약(체력 40회복 20sp) ####\n\n");
	printf("\n####  뒤로 가고 싶으면 1~4번을 제외한 키를 입력해주세요 ####\n\n");
	scanf("%d", &Skill);
	switch (Skill)
	{
	case 1://화염방사
		if (player_sp < 30) //sp가 30미만일때 메시지 출력 및 재귀함수써서 다시 선택하도록 함
		{
			printf("\n\n\n  SP가 부족하네요  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 30;
		Player_Attack_Fiame();
		return 0;
		//몸통박치기
	case 2:
		if (player_sp < 20) //sp가 20미만일때 메시지 출력 및 재귀함수써서 다시 선택하도록 함
		{
			printf("\n\n\n  SP가 부족하네요  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 20;
		Player_Attack_Crash();
		return 0;
	case 3://마구할퀴기
		if (player_sp < 30) //sp가 30미만일때 메시지 출력 및 재귀함수써서 다시 선택하도록 함
		{
			printf("\n\n\n  SP가 부족하네요  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 30;
		for (int i = 1; i <= 3; i++) // 세번 공격으로 함수 3번 출력
		{
			Player_Attack_Scratch();
			Sleep(1000);
		}
		return 0;

	case 4://회복약
		if (player_sp < 20) //sp가 20미만일때 메시지 출력 및 재귀함수써서 다시 선택하도록 함
		{
			printf("\n\n\n   SP가 부족하네요  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 20;
		Player_heal();
		return 0;
	default:
		Choose();
		return 0;
	}
}