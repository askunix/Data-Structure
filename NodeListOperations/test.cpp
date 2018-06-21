#include"contect.h"





void menu()
{
	
	cout << "╔═══════════════════════════════════════════════════╗"<<endl;
	cout << "║═══════════════════  通讯录  ══════════════════════║"<<endl;
	cout << "║═══                                             ═══║" << endl;
	cout << "║═══           1.新建           2.删除           ═══║"<<endl;
	cout << "║═══           3.查找           4.修改           ═══║"<<endl;
	cout << "║═══           5.清空           6.排序           ═══║"<<endl;
	cout << "║═══           7.打印           0.退出           ═══║"<<endl;
	cout << "║═══                                             ═══║" << endl;
	cout << "╚═══════════════════════════════════════════════════╝"<<endl;
}





void test()
{
	
	system("color c"); //改变背景
	Contact my_con;
	InitContact(&my_con);

	int input = 0;

	do
	{
	
		menu();
		cout << "请选择：";
		cin >> input;

		switch (input)
		{
		case Exit:
			break;

		case Add:
			AddContact(&my_con);
			break;

		case Del:
			DelContact(&my_con);
			break;

		case Search:
			SearchContact(&my_con);
			break;
			
		case Modify:
			ModifyContact(&my_con);
			break;

		case Empty:
			EmptyContact(&my_con);
			break;

		case Sort:
			SortContact(&my_con);
			break;

		case Show:
			ShowContact(&my_con);
			break;
		default:
			cout << "选择错误：->!!!" << endl;
			break;
		}



	} while (input);
}




int main()
{
	test();
	return 0;
}