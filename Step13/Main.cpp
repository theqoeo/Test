#define _CRT_SECURE_NO_WARNINGS // strcpy�� ���� ���� ����
#include <stdio.h> // C ǥ�� ���̺귯�� �� �ϳ��� stdio.h ��� ��� ���Ͽ� ����
#include <string> // ���� ������� �ϱ� ���� ����
#include <time.h> // �ð� �Լ��� ����ϱ� ���� ����
#include <malloc.h> // ���� �Ҵ��� �ϱ� ���� ����
#include <Windows.h> // Sleep()�Լ��� ����ϱ� ���� ����

// const�� ��������ν� �ٲ��� �ʴ� ����� ����
const int PLAYER = 0; // �������� const int PLAYER�� 0���� �ʱ�ȭ
const int ENEMY = 1; // �������� const int ENEMY�� 1�� �ʱ�ȭ
const int MAX = 2; // �������� const int MAX�� 2�� �ʱ�ȭ

typedef struct tagInfo // ����ü tagInfo ����, �÷��̾�
{
	char* Name; // cha�� �����ͷ� ����
	int Hp; // hp�� ���������� ����
	int Mp; // mp�� ���������� ����
	int Exp; // exp�� ���������� ����
	int Level; // level�� ���������� ����
	float Att; // att�� �Ǽ������� ����
	float Def; // def�� �Ǽ������� ����
}INFO; // ����ü tagInfo�� �ҷ����� ���� INFO ����

typedef struct tagObject // ����ü tagObject ����, ����
{
	INFO Info; // tagInfo�� �ִ� ���� �ҷ����� 

}OBJECT; // tagObject�� �ҷ����� ���� OBJECT ����

void InitializeObject(OBJECT* _Obj, int ObjectType); // �Լ��� �Ҿ���� ���� ����
char* SetName(); // �Լ��� �Ҿ���� ���� ����

int main(void) // ���� �Լ�
{
	/*
	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeObject(Player, PLAYER);

	OBJECT* Enemy = (OBJECT*)malloc(sizeof(OBJECT));;
	InitializeObject(Enemy, ENEMY);
	*/
	OBJECT* Objects[MAX]; // ���� ������ ����ü�� ����ϱ� ���� ������ �迭 ����

	Objects[PLAYER] = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT�� ũ�⸸ŭ �����Ҵ� 
	InitializeObject(Objects[PLAYER], PLAYER); // ����ü�� ����ϱ� ���� ����

	Objects[ENEMY] = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT�� ũ�⸸ŭ �����Ҵ�
	InitializeObject(Objects[ENEMY], ENEMY); // ����ü�� ����Ͻ� ���� ����

	while (true) // �ݺ����� while�� true�� �� �Ʒ� �ڵ� ����
	{

		printf_s("\n[%s]\n", Objects[PLAYER]->Info.Name);
		printf_s("HP : %d\n", Objects[PLAYER]->Info.Hp);
		printf_s("MP : %d\n", Objects[PLAYER]->Info.Mp);
		printf_s("���ݷ� : %.2f\n", Objects[PLAYER]->Info.Att);
		printf_s("���� : %.2f\n", Objects[PLAYER]->Info.Def);
		printf_s("EXP : %d\n", Objects[PLAYER]->Info.Exp);
		printf_s("Level : %d\n\n", Objects[PLAYER]->Info.Level);

		printf_s("[%s]\n", Objects[ENEMY]->Info.Name);
		printf_s("HP : %d\n", Objects[ENEMY]->Info.Hp);
		printf_s("MP : %d\n", Objects[ENEMY]->Info.Mp);
		printf_s("���ݷ� : %.2f\n", Objects[ENEMY]->Info.Att);
		printf_s("���� : %.2f\n", Objects[ENEMY]->Info.Def);
		printf_s("EXP : %d\n", Objects[ENEMY]->Info.Exp);
		printf_s("Level : %d\n\n", Objects[ENEMY]->Info.Level);

		int iChoice = 0; // int iChoice���� �� 0���� �ʱ�ȭ
		printf_s("���Ϳ� �������ϴ�. �����Ͻðڽ��ϱ� ?\n1. ����\n2. ����\n�Է� : ");
		scanf_s("%d", &iChoice); // iChoice�Է°�


		switch (iChoice) // switch�� iChoice�Է¿� ���� �ڵ� ����
		{
		case 1: // iChoice�� 1�� ���
			if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def) // if�� �÷��̾� att�� ���� def���� ���� ���
			{
				Objects[ENEMY]->Info.Hp -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // ���� ü���� (�÷��̾� ���ݷ� - ���� ����)����ŭ �پ���.
			}
			else // �÷��̾� att�� ���� def���� ���� ���
				Objects[ENEMY]->Info.Hp -= 1; // ���� ü���� 1�� ��´�
			if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def) // if�� ���� att�� �÷��̾� def���� ���� ���
			{
				Objects[PLAYER]->Info.Hp -= Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def; // �÷��̾� ü���� (���� ���ݷ� - �÷��̾� ����)����ŭ �پ���.
			}
			else // ���� att�� �÷��̾� def���� ���� ���
				Objects[PLAYER]->Info.Hp -= 1; // �÷��̾� ü���� 1�� ��´�
			break;
		case 2: // iChoice�� 2�� ���
			int Numbers[3]; // �迭 ����
			time_t tTime = time(NULL); // time�Լ��� �̿��� ����ð� ��ȯ
			int Rand = rand() % 45 + 1; // rand�Լ��� �̿��� ������ ����

			if ((Rand % 3) == 1 || (Rand % 3) == 2) // �������� 3���� �������� �������� 1�̳�2�� ���
			{
				printf_s("����ġ�°Ϳ� [����] �߽��ϴ�.\n");
				break;
			}
			else // �������� 0�� ���
			{
				printf_s("����ġ�°Ϳ� [����] �߽��ϴ�.\n");
				printf_s("������ ���۵˴ϴ�. \n");

				if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def) // if�� �÷��̾� att�� ���� def���� ���� ���
				{
					Objects[ENEMY]->Info.Hp -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // ���� ü���� (�÷��̾� ���ݷ� - ���� ����)����ŭ �پ���.
				}
				else  // �÷��̾� att�� ���� def���� ���� ���
					Objects[ENEMY]->Info.Hp -= 1; // ���� ü���� 1�� ��´�
				if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def) // if�� ���� att�� �÷��̾� def���� ���� ���
				{
					Objects[PLAYER]->Info.Hp -= Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def; // �÷��̾� ü���� (���� ���ݷ� - �÷��̾� ����)����ŭ �پ���.
				}
				else // ���� att�� �÷��̾� def���� ���� ���
					Objects[PLAYER]->Info.Hp -= 1; // �÷��̾� ü���� 1�� ��´�
				break;
			}
		}
		Sleep(3000); // 3�� �ڿ� ����
		system("cls"); // ��°��� ����
	}

	return 0;
}

void InitializeObject(OBJECT* _Obj, int ObjectType) // �÷��̾�� ���� hp,mp�� ���� �ֱ� ���� �Լ�
{
	switch (ObjectType) // switch��
	{
	case PLAYER: // �÷��̾� �� ����
		_Obj->Info.Name = SetName(); // �̸��� SetName()�Լ����� �޾ƿ´�

		_Obj->Info.Att = 10; // �÷��̾� att���� 10���� ����
		_Obj->Info.Def = 10; // �÷��̾� def���� 10���� ����
		_Obj->Info.Exp = 0; // �÷��̾� exp���� 0���� ����
		_Obj->Info.Hp = 100; // �÷��̾� hp���� 100���� ����
		_Obj->Info.Mp = 10; // �÷��̾� mp���� 10���� ����
		_Obj->Info.Level = 1; // �÷��̾� level���� 1���� ����
		break;
	case ENEMY: // ���� �� ����
		_Obj->Info.Name = (char*)"Enemy"; // ���� �̸��� Enemy�� ����

		_Obj->Info.Att = 5; // ���� att���� 5�� ����
		_Obj->Info.Def = 15; // ���� def���� 15�� ����
		_Obj->Info.Exp = 0; // ���� exp���� 0�� ����
		_Obj->Info.Hp = 30; // ���� hp���� 30�� ����
		_Obj->Info.Mp = 5; // ���� mp���� 5�� ����
		_Obj->Info.Level = 1; // ���� level���� 1�� ����
		break;
	}
}

char* SetName() // �̸��� �Է� �޾Ƽ� �ҷ����� ���� �Լ�
{
	char Buffer[128] = ""; // �Է��� ���Ƿ� ������ ����
	printf_s("�̸��� �Է��ϼ��� : ");
	scanf("%s", Buffer); // Buffer�� �Է��� ����

	char* pName = (char*)malloc(strlen(Buffer) + 1); // ������ ������ �����Ҵ�
	strcpy(pName, Buffer); // ���ڿ� ����

	return pName; // �̸� ��ȯ
}