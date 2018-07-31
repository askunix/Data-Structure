
//定义
#define N 10
typedef struct Pos{
	int _row;
	int _col;
}Pos;

typedef struct Maze
{
	int _mz[N][N];
	Pos _entry;
}Maze;





//寻路算法

int CheckIsAccess(Maze *m, Pos pos)
{
	if(pos._row >= 0 && pos._row < N
	   && pos._col >= 0 && pos._col < N
	   && m->_mz[pos._row][pos._col] == 1)
	   {
		   return 1;
	   }
	   return 0;
}




void MazeGetPath(Maze* m)
{
	Stack s;
	StackInit(&s, 10);
	StackPush(&s, m->_entry);
	
	while(StackEmpty(&s) != 0)
	{
		//1,入口   2，下一个可以走的位置  3，回溯的上一个位置
		cur = StackTop(&s);
	    m->_mz[cur._row][cur._col] = 2;
		
		
    	if(cur._col == N-1)
		{
			printf("找到通路了\n");
			return;
		}
		
		Pos next = cur;
		
		//上
		next._row -= 1;
		if(CheckIsAccess(m, next) == -1)
		{
			StackPush(&s, next);
			continue;
		}
		
		//下
		next = cur;
		next._row += 1;
		if(CheckIsAccess(m, next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		
		//左
		next = cur;
		next._col -= 1;
		if(CheckIsAccess(m, next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		
		
		
		//右
		next = cur;
		next._col += 1;
		if(CheckIsAccess(m, next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		
		//回溯
		StackPop(&s);
	}
	printf("没有通路\n");
}
			
			
			
			
			
			
			
			
			
