#pragma once;

#include<iostream>
#include<Windows.h>
#include<cstdio>
#define NAME_MAX 20
#define TEL_MAX 12
#define SEX_MAX 4
#define MAX 1000

using namespace std;

enum{ Exit, Add, Del, Search, Modify, Empty, Sort, Show};

struct Stu
{
	char Name[NAME_MAX];
	int Age;
	char Tel[TEL_MAX];
	char Sex[SEX_MAX];
	char Address[50];
};

typedef struct Stu Stu;

typedef struct Contact
{
	Stu Con[MAX];       //容量
	int sz;     //计数
}Contact, *pContact;


//函数声明

void InitContact(pContact pCon);  //初始化

void AddContact(pContact pCon);   //新建

void ShowContact(pContact pCon);  //打印

void DelContact(pContact pCon);   //删除

void SearchContact(pContact pCon);   //查找

void ModifyContact(pContact pCon);    //修改

void EmptyContact(pContact pCon);    //清空

void SortContact(pContact pCon);    //排序
