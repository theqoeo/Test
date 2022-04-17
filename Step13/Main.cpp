#define _CRT_SECURE_NO_WARNINGS // strcpy를 쓰기 위해 선언
#include <stdio.h> // C 표준 라이브러리 중 하나인 stdio.h 라는 헤더 파일에 선언
#include <string> // 문자 입출력을 하기 위해 선언
#include <time.h> // 시간 함수를 사용하기 위해 선언
#include <malloc.h> // 동적 할당을 하기 위해 선언
#include <Windows.h> // Sleep()함수를 사용하기 위해 선언

// const를 사용함으로써 바뀌지 않는 상수로 선언
const int PLAYER = 0; // 전역변수 const int PLAYER를 0으로 초기화
const int ENEMY = 1; // 전역변수 const int ENEMY를 1로 초기화
const int MAX = 2; // 전역변수 const int MAX를 2로 초기화

typedef struct tagInfo // 구조체 tagInfo 생성, 플레이어
{
	char* Name; // cha형 포인터로 선언
	int Hp; // hp를 정수형으로 선언
	int Mp; // mp를 정수형으로 선언
	int Exp; // exp를 정수형으로 선언
	int Level; // level을 정수형으로 선언
	float Att; // att을 실수형으로 선언
	float Def; // def를 실수형으로 선언
}INFO; // 구조체 tagInfo를 불러오기 위해 INFO 선언

typedef struct tagObject // 구조체 tagObject 생성, 몬스터
{
	INFO Info; // tagInfo에 있는 변수 불러오기 

}OBJECT; // tagObject을 불러오기 위해 OBJECT 선언

void InitializeObject(OBJECT* _Obj, int ObjectType); // 함수를 불어오기 위해 선언
char* SetName(); // 함수를 불어오기 위해 선언

int main(void) // 메인 함수
{
	/*
	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeObject(Player, PLAYER);

	OBJECT* Enemy = (OBJECT*)malloc(sizeof(OBJECT));;
	InitializeObject(Enemy, ENEMY);
	*/
	OBJECT* Objects[MAX]; // 위에 선언한 구조체를 사용하기 위해 포인터 배열 생성

	Objects[PLAYER] = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT의 크기만큼 동적할당 
	InitializeObject(Objects[PLAYER], PLAYER); // 구조체를 사용하기 위한 선언

	Objects[ENEMY] = (OBJECT*)malloc(sizeof(OBJECT)); // OBJECT의 크기만큼 동적할당
	InitializeObject(Objects[ENEMY], ENEMY); // 구조체를 사용하시 위한 선언

	while (true) // 반복문중 while문 true일 떄 아래 코드 실행
	{

		printf_s("\n[%s]\n", Objects[PLAYER]->Info.Name);
		printf_s("HP : %d\n", Objects[PLAYER]->Info.Hp);
		printf_s("MP : %d\n", Objects[PLAYER]->Info.Mp);
		printf_s("공격력 : %.2f\n", Objects[PLAYER]->Info.Att);
		printf_s("방어력 : %.2f\n", Objects[PLAYER]->Info.Def);
		printf_s("EXP : %d\n", Objects[PLAYER]->Info.Exp);
		printf_s("Level : %d\n\n", Objects[PLAYER]->Info.Level);

		printf_s("[%s]\n", Objects[ENEMY]->Info.Name);
		printf_s("HP : %d\n", Objects[ENEMY]->Info.Hp);
		printf_s("MP : %d\n", Objects[ENEMY]->Info.Mp);
		printf_s("공격력 : %.2f\n", Objects[ENEMY]->Info.Att);
		printf_s("방어력 : %.2f\n", Objects[ENEMY]->Info.Def);
		printf_s("EXP : %d\n", Objects[ENEMY]->Info.Exp);
		printf_s("Level : %d\n\n", Objects[ENEMY]->Info.Level);

		int iChoice = 0; // int iChoice선언 후 0으로 초기화
		printf_s("몬스터와 만났습니다. 공격하시겠습니까 ?\n1. 공격\n2. 도망\n입력 : ");
		scanf_s("%d", &iChoice); // iChoice입력값


		switch (iChoice) // switch문 iChoice입력에 따라 코드 실행
		{
		case 1: // iChoice가 1일 경우
			if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def) // if문 플레이어 att가 몬스터 def보다 높을 경우
			{
				Objects[ENEMY]->Info.Hp -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // 몬스터 체력을 (플레이어 공격력 - 몬스터 방어력)값만큼 줄어든다.
			}
			else // 플레이어 att가 몬스터 def보다 낮을 경우
				Objects[ENEMY]->Info.Hp -= 1; // 몬스터 체력을 1씩 깍는다
			if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def) // if문 몬스터 att가 플레이어 def보다 높을 경우
			{
				Objects[PLAYER]->Info.Hp -= Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def; // 플레이어 체력을 (몬스터 공격력 - 플레이어 방어력)값만큼 줄어든다.
			}
			else // 몬스터 att가 플레이어 def보다 낮을 경우
				Objects[PLAYER]->Info.Hp -= 1; // 플레이어 체력을 1씩 깍는다
			break;
		case 2: // iChoice가 2일 경우
			int Numbers[3]; // 배열 생성
			time_t tTime = time(NULL); // time함수를 이용해 현재시간 반환
			int Rand = rand() % 45 + 1; // rand함수를 이용해 랜덤값 생성

			if ((Rand % 3) == 1 || (Rand % 3) == 2) // 랜덤값을 3으로 나눴을때 나머지가 1이나2일 경우
			{
				printf_s("도망치는것에 [성공] 했습니다.\n");
				break;
			}
			else // 나머지가 0일 경우
			{
				printf_s("도망치는것에 [실패] 했습니다.\n");
				printf_s("전투가 시작됩니다. \n");

				if (Objects[PLAYER]->Info.Att > Objects[ENEMY]->Info.Def) // if문 플레이어 att가 몬스터 def보다 높을 경우
				{
					Objects[ENEMY]->Info.Hp -= Objects[PLAYER]->Info.Att - Objects[ENEMY]->Info.Def; // 몬스터 체력을 (플레이어 공격력 - 몬스터 방어력)값만큼 줄어든다.
				}
				else  // 플레이어 att가 몬스터 def보다 낮을 경우
					Objects[ENEMY]->Info.Hp -= 1; // 몬스터 체력을 1씩 깍는다
				if (Objects[ENEMY]->Info.Att > Objects[PLAYER]->Info.Def) // if문 몬스터 att가 플레이어 def보다 높을 경우
				{
					Objects[PLAYER]->Info.Hp -= Objects[ENEMY]->Info.Att - Objects[PLAYER]->Info.Def; // 플레이어 체력을 (몬스터 공격력 - 플레이어 방어력)값만큼 줄어든다.
				}
				else // 몬스터 att가 플레이어 def보다 낮을 경우
					Objects[PLAYER]->Info.Hp -= 1; // 플레이어 체력을 1씩 깍는다
				break;
			}
		}
		Sleep(3000); // 3초 뒤에 생성
		system("cls"); // 출력값을 지움
	}

	return 0;
}

void InitializeObject(OBJECT* _Obj, int ObjectType) // 플레이어와 몬스터 hp,mp등등에 값을 넣기 위한 함수
{
	switch (ObjectType) // switch문
	{
	case PLAYER: // 플레이어 값 설정
		_Obj->Info.Name = SetName(); // 이름을 SetName()함수에서 받아온다

		_Obj->Info.Att = 10; // 플레이어 att값을 10으로 설정
		_Obj->Info.Def = 10; // 플레이어 def값을 10으로 설정
		_Obj->Info.Exp = 0; // 플레이어 exp값을 0으로 설정
		_Obj->Info.Hp = 100; // 플레이어 hp값을 100으로 설정
		_Obj->Info.Mp = 10; // 플레이어 mp값을 10으로 설정
		_Obj->Info.Level = 1; // 플레이어 level값을 1으로 설정
		break;
	case ENEMY: // 몬스터 값 설정
		_Obj->Info.Name = (char*)"Enemy"; // 몬스터 이름을 Enemy로 설정

		_Obj->Info.Att = 5; // 몬스터 att값을 5로 설정
		_Obj->Info.Def = 15; // 몬스터 def값을 15로 설정
		_Obj->Info.Exp = 0; // 몬스터 exp값을 0로 설정
		_Obj->Info.Hp = 30; // 몬스터 hp값을 30로 설정
		_Obj->Info.Mp = 5; // 몬스터 mp값을 5로 설정
		_Obj->Info.Level = 1; // 몬스터 level값을 1로 설정
		break;
	}
}

char* SetName() // 이름을 입력 받아서 불러오기 위한 함수
{
	char Buffer[128] = ""; // 입력을 임의로 저장할 공산
	printf_s("이름을 입력하세요 : ");
	scanf("%s", Buffer); // Buffer에 입력을 받음

	char* pName = (char*)malloc(strlen(Buffer) + 1); // 포인터 변수에 동적할당
	strcpy(pName, Buffer); // 문자열 복사

	return pName; // 이름 반환
}