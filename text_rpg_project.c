#include <stdio.h>
#include <time.h>// �����Լ�
#include <windows.h> // Sleep �Լ� ����� ���� ��

//�������� ����
static int Exit = 0; // ���ắ��
int Mob_Hp = 150;
int player_Hp = 175;
int player_sp = 225;
//�Լ� ����
int Choose(void);
int Mob_Attack(void);
int Player_Skill_Select(void);

int main(void) {

	int choose;
	while (1)
	{

		srand(time(NULL)); // srand �� �ʱ�ȭ(������ �ʱ�ȭ)
		printf("\n\n\n  �߻� ��ī�� HP : %d  \n\n", Mob_Hp);
		printf("\n\n\n  �÷��̾� ���̸� HP : %d    SP : %d \n\n", player_Hp, player_sp);
		//�޴� ��ȣ �Է�
		Choose();
		if (player_Hp <= 0) { // �÷��̾��� HP�� ���̳ʽ��� ǥ�õǴ� ���� ���� (��������)
			player_Hp = 0;
			Exit += 1;
		}
		if (Mob_Hp <= 0) { // ���� HP�� ���̳ʽ��� ǥ�õǴ� ���� ���� (��������)
			Mob_Hp = 0;
			Exit += 1;
		}
		if (Exit >= 1) // ���ắ���� 1�̻��Ͻ� ��������
		{
			printf("\n\n  ������ �����մϴ� \n\n");
			break;
		}
		Sleep(1000);
		Mob_Attack();
		Sleep(1000);
	}

	return 0;
}



int Choose(void) //�޴� ���� �Լ�
{
	printf("\n\n##   1. ���   2. ����   ##\n\n");
	int menu_Select;
	scanf("%d", &menu_Select);
	switch (menu_Select) {
	case 1:
		Player_Skill_Select();
		return 0;
	case 2:
		Exit += 1; // ��������
		return 0;
	default:
		printf("\n   �߸��� ���Դϴ�. �ٽ� �Է����ּ���.  \n ");
		Choose();
	}

}

int Player_Attack_Scratch(void)  // �÷��̾� ������ ��� �� �޽��� ��� �Լ�
{
	int attack_damage = 5; // 5 ����
	Mob_Hp -= attack_damage; // �� HP�� ����������ŭ ����
	printf("\n\n  ����������� ���� ��ī�򿡰� %d �������� ������ \n\n", attack_damage); // �޽��� ���

}


int Player_Attack_Fiame(void)  // �÷��̾� ������ ��� �� �޽��� ��� �Լ�
{
	int attack_damage = rand() % (15) + 20; // 20~35 ������ ����
	Mob_Hp -= attack_damage; // �� HP�� ����������ŭ ����
	printf("\n\n  ȭ������ ���� ��ī�򿡰� %d �������� ������ \n\n", attack_damage); // �޽��� ���

}


int Player_Attack_Crash(void)  // �÷��̾� ������ ��� �� �޽��� ��� �Լ�
{
	int attack_damage = rand() % (10) + 10; // 10~20 ������ ����
	Mob_Hp -= attack_damage; // �� HP�� ����������ŭ ����
	printf("\n\n �����ġ��� ���� ��ī�򿡰� %d �������� ������ \n\n", attack_damage); // �޽��� ���

}


int Mob_Attack(void)  // �� ������ ��� �� �޽��� ��� �Լ�
{
	int Mob_attack_damage = rand() % (15) + 15; // 15~30 ������ ����
	player_Hp -= Mob_attack_damage; // �÷��̾� HP�� ����������ŭ ����
	if (Mob_Hp < 38) {				//���� ü���� �������� ������ �� �߰�������
		player_Hp -= 3;
	}
	printf("\n\n  ��ī���� �ʸ���Ʈ�� ���� ���̸��� %d �������� �Ծ��� \n\n", Mob_attack_damage); // �޽��� ���

}


int Player_heal(void)  // �÷��̾� ȸ��
{
	player_Hp += 40; // HP 40 ����
	if (player_Hp > 150) { // �÷��̾� HP�� �ִ� HP �ʰ����� �ʵ��� ����
		player_Hp = 150;
	}
	printf("\n\n �÷��̾��� ���̸��� 40 HP�� ȸ���ߴ�  \n\n"); // �޽��� ���
}


int Player_Skill_Select(void) //��ų ���� â
{
	int Skill = 0;
	printf("\n\n####   1. ȭ����� (20 ~ 35 ������ 30sp)       2. �����ġ�� (20 ~ 30 ������ 20sp) ####\n\n");
	printf("\n\n####   3. ����������(5 �������� 3�� ���� 30sp) 4. ȸ����(ü�� 40ȸ�� 20sp) ####\n\n");
	printf("\n####  �ڷ� ���� ������ 1~4���� ������ Ű�� �Է����ּ��� ####\n\n");
	scanf("%d", &Skill);
	switch (Skill)
	{
	case 1://ȭ�����
		if (player_sp < 30) //sp�� 30�̸��϶� �޽��� ��� �� ����Լ��Ἥ �ٽ� �����ϵ��� ��
		{
			printf("\n\n\n  SP�� �����ϳ׿�  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 30;
		Player_Attack_Fiame();
		return 0;
		//�����ġ��
	case 2:
		if (player_sp < 20) //sp�� 20�̸��϶� �޽��� ��� �� ����Լ��Ἥ �ٽ� �����ϵ��� ��
		{
			printf("\n\n\n  SP�� �����ϳ׿�  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 20;
		Player_Attack_Crash();
		return 0;
	case 3://����������
		if (player_sp < 30) //sp�� 30�̸��϶� �޽��� ��� �� ����Լ��Ἥ �ٽ� �����ϵ��� ��
		{
			printf("\n\n\n  SP�� �����ϳ׿�  \n\n");
			Player_Skill_Select();
		}
		player_sp -= 30;
		for (int i = 1; i <= 3; i++) // ���� �������� �Լ� 3�� ���
		{
			Player_Attack_Scratch();
			Sleep(1000);
		}
		return 0;

	case 4://ȸ����
		if (player_sp < 20) //sp�� 20�̸��϶� �޽��� ��� �� ����Լ��Ἥ �ٽ� �����ϵ��� ��
		{
			printf("\n\n\n   SP�� �����ϳ׿�  \n\n");
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