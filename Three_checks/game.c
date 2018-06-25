#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"




void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', sizeof(char)*row*col);                     //初始化棋盘(指定内存地址，初始化，内存大小)
}



void Display(char board[ROW][COL],int row,int col)                //打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1],board[i][2]);
		if (i != row - 1)
		{
			printf("---|---|---\n");
		}
		
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{

		x = rand() % row;
		y = rand() % row;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}



void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("请输入坐标：\n");
		scanf("%d%d", &x, &y);
		if ((x >= 1) && (x<=3)&&(y>=1)&&(y<=3))                     //判断玩家坐标
		{
			if (board[x-1][y-1] ==' ')                   //坐标是否被占用
			{
				board[x-1][y-1] = 'X';
				break;
			}
			else
			{
				printf("请重新输入>\n");
			}
		}
		
	}
}



char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	return 1;              //棋盘满了
}



int IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2] && board[i][1] != ' '))
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i] && board[1][i] != ' '))
		{
			return board[1][i];
		}
	}
		if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
		{
			return board[1][1];
		}
		if ((board[0][2] == board[1][1]) && (board[2][0] && board[1][1] )&&(board[2][2]!= ' '))
		{
			return board[1][1];
		}
		if (IsFull(board, row, col))
		{
			return 'q';        //棋盘满了
		}
		return ' ';
	}

