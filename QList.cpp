// QList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <list>
#include <iostream>
#include <stdarg.h>
#include <vector>

using namespace std;

class Student
{
public:
	Student(const int _arg, string _name) {
		m_arg = _arg;
		m_name = _name;
	}

	int arg()     { return m_arg;   }
	string name() { return m_name;  }

	void setArg(int s)      { m_arg = s;   }
	void setName(string na) { m_name = na; }


private:
	int m_arg;
	string m_name;
};


class Student;
int main()
{
	vector<Student *> allList;
	vector<Student *> sexList;

	Student *item = new Student(10, "hejinhong");
	allList.emplace_back(item);
	sexList.emplace_back(item);


	allList[0]->setArg(3);
	int m = allList[0]->arg();
	int n = sexList[0]->arg();

	cout << m << n << endl;

	allList[0]->setName("计算机");
	string name = sexList.at(0)->name();

	cout << name.c_str();
	





}
