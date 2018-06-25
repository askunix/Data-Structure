#define _CRT_SECURE_NO_WARNINGS 1


#include"game.h"
#include<time.h>


menu()
{
	printf("**********************************************\n");
	printf("*****************   单机三子棋   *************\n");
	printf("***************** 1.play  2.exit *************\n");
	printf("**********************************************\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = {0};

	InitBoard(board, ROW, COL);
	Display(board, ROW, COL);

	while(1)
	{
		printf("玩家走：\n");
		PlayerMove(board, ROW, COL);
		Display(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret!=' ')
		{
			break;
		}


		printf("电脑走：\n");
		ComputerMove(board,ROW,COL);
		Display(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		
		
	}
	if (ret == 'X')
	{
		printf("玩家赢\n");
	}
	else if (ret == '0')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}


void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			   game();
				break;
			case 2:
				break;
			default:
				printf("请重新输入");
				break;
		}
	} while (input);

}


int main()
{
	
	test();
	system("pause");
	return 0;
}