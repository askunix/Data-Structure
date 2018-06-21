#define _CRT_SECURE_NO_WARNINGS 1
#include"contect.h"



void InitContact(pContact pCon)
{
	pCon->sz = 0;
	memset(pCon->Con, 0, MAX * sizeof(Stu));
}



void AddContact(pContact pCon)
{
	cout<<"请输入联系人姓名：";
	cin >> pCon->Con[pCon->sz].Name;
	cout << "请输入联系人年龄：";
	cin >> pCon->Con[pCon->sz].Age; 
	cout << "请输入联系人电话：";
	cin >> pCon->Con[pCon->sz].Tel;
	cout << "请输入联系人性别：";
	cin >> pCon->Con[pCon->sz].Sex;
	cout << "请输入联系人地址：";
	cin >> pCon->Con[pCon->sz].Address;
	cout << "═════联系人 " << pCon->Con[pCon->sz].Name << " 的信息保存成功════" << endl << endl;
	pCon->sz++;
	
}



void ShowContact(pContact pCon)
{
	cout << endl; 
	cout << "╔═════════════════════════════════════════════════════════════╗" << endl;
	printf("%3s\t%6s\t%2s%16s%8s%20s\n","║序号","姓名","年龄","电话","性别","地址║");
		for (int i = 0; i < pCon->sz; i++)
		{
			
			printf("%3d\t%6s\t%2d%16s%8s%20s\n", 
				i + 1, 
				pCon->Con[i].Name,
				pCon->Con[i].Age, 
				pCon->Con[i].Tel, 
				pCon->Con[i].Sex,
				pCon->Con[i].Address);


			
			//printf("\n║-------------------------------------------------------------║\n");
		}
		cout << "╚═════════════════════════════════════════════════════════════╝" << endl;
		cout << "温馨提示：输出完成！！！" << endl << endl;
}


int FindInContact(pContact pCon, char *ch)
{
	for (int i = 0; i < pCon->sz; i++)
	{
		if (strcmp(pCon->Con[i].Name,ch) == 0)
		{
			return i;
		}
		
	}
	return -1;
}


void DelContact(pContact pCon)
{
	char ch[20];
	ShowContact(pCon);
	cout << "请输入上面通讯录中要删除联系人的姓名：";
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);
	if (NULL == -1)
	{
		printf("通讯录中没有该联系人！！！");
	}
	if (NUM <= pCon->sz && NUM != -1)
	{
		for (int j = NUM; j <= pCon->sz-1; j++)
		{
			pCon->sz--;
			pCon->Con[j] = pCon->Con[j + 1];
			printf("删除成功！！！\n");
		}
	}
	
}



void SearchContact(pContact pCon)
{
	char ch[20];
	printf("请输出你要查找联系人的姓名：");
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);
	if (NUM != -1)
	{
		cout << "╔═════════════════════════════════════════════════════════════╗" << endl;
		printf("%3s\t%6s\t%2s%16s%8s%20s\n", "║序号", "姓名", "年龄", "电话", "性别", "地址║");
		printf("%3d\t%6s\t%2d%16s%8s%20s\n",
			NUM + 1,
			pCon->Con[NUM].Name,
			pCon->Con[NUM].Age,
			pCon->Con[NUM].Tel,
			pCon->Con[NUM].Sex,
			pCon->Con[NUM].Address);
		cout << "╚═════════════════════════════════════════════════════════════╝" << endl;

	}
	else
		printf("你要找的联系人不存在\n");
}




void ModifyContact(pContact pCon)
{
	char ch[NAME_MAX];

	printf("请输入要修改的联系人的姓名：");
	scanf("%s", &ch);
	int NUM = FindInContact(pCon, ch);

	if (NUM != -1)
	{
		cout << "╔═════════════════════════════════════════════════════════════╗" << endl;
		printf("%3s\t%6s\t%2s%16s%8s%20s\n", "║序号", "姓名", "年龄", "电话", "性别", "地址║");
		printf("%3d\t%6s\t%2d%16s%8s%20s\n",
			NUM,
			pCon->Con[NUM].Name,
			pCon->Con[NUM].Age,
			pCon->Con[NUM].Tel,
			pCon->Con[NUM].Sex,
			pCon->Con[NUM].Address);

		cout << "╚═════════════════════════════════════════════════════════════╝" << endl;


		printf("请把姓名修改成：");
		scanf("%s", pCon->Con[NUM].Name);

		printf("请把年龄修改成：");
		scanf("%d", &pCon->Con[NUM].Age);

		printf("请把电话修改成：");
		scanf("%s", pCon->Con[NUM].Tel);

		printf("请把性别修改成：");
		scanf("%s", pCon->Con[NUM].Sex);

		printf("请把地址修改成：");
		scanf("%s", pCon->Con[NUM].Address);

	
	}
}
		

			
				
			





void EmptyContact(pContact pCon)
{
	pCon->sz = 0;
	printf("清空成功！！！\n\n");
}




void SortContact(pContact pCon)
{
	for (int i = 0; i < pCon->sz; i++)
	{
		for (int j = 0; j < pCon->sz-i-1; j++)
		{
			if (strcmp(pCon->Con[j].Name, pCon->Con[j + 1].Name)>0)
			{
				Stu temp;
				temp = pCon->Con[j];
				pCon->Con[j] = pCon->Con[j + 1];
				pCon->Con[j + 1] = temp;
			}
		}
	}
}