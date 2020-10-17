// 2020_10_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

//仿函数排序

//定义student对象
class Student {
public:
	Student(const char *name, int age)
	{
		strcpy_s(this->name, name);
		this->age = age;
	}

public:
	char name[64];
	int  age;
};

//提供仿函数，用于自定义对象的set进行排序，要写一个仿函数，用来排序
struct FuncStudent
{
	//重载了括号操作符，用来比较大小
	bool operator() (const Student &left, const Student &right)
	{
		//如果左边比右边小，从小到大按照年龄排序
		if (left.age < right.age)
			return true;
		else
			return false;
	}

};

int main()
{
	Student s1("s1", 32);
	Student s2("s2", 22);
	Student s3("s3", 44);
	Student s4("s4", 11);
	Student s5("s5", 22);

	//创建集合，采用从小到大的排序
	set<Student, FuncStudent> set1;

	//插入数据
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	//插入不进去(年龄有重复的，所以插不进去了),要通过返回值来确保是否插入成功
	set1.insert(s5);

	//遍历
	for (set<Student>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << it->age << "\t" << it->name << endl;
	}

	return 0;
}





/*
int main()
{
	//*********************************    std::string     *******************************

	std::string s1 = "hello helooo hello ,  hello";
	size_t index3 = s1.find_last_of("hello");   //返回最后一个索引
	cout << index3 << endl;


	//求hello出现的次数，以及对应的下标
	int count = 0;
	size_t offindex = s1.find("hello", 0);
	while (offindex != string::npos) {
		cout << "索引:" << offindex << endl;
		count++;
		offindex++;
		offindex = s1.find("hello", offindex);
	}

	cout << count;


	//把hello替换成welcome
	size_t offindex1 = s1.find("hello", 0);
	while (offindex1 != string::npos) {

		//从offindex1的位置开始删除5个位置，并插入新的字符串welcome
		s1.replace(offindex1, strlen("hello"), "welcome");

		//从后面的位置开始
		offindex1 += strlen("welcome");

		//继续查找
		offindex1 = s1.find("hello", offindex1);
	}
	cout << "替换后的字符串：" << s1 << endl;

	//*********************************    Vector     *******************************
	//vector在尾部添加或者移除元素非常快，在中间操作非常耗时，因为它需要移动元素

	//定义一个vector容器
	vector<int> v1;

	//插入元素(尾部插入)
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	//迭代器遍历打印
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//修改头部元素的值(front()返回是引用，可以当左值)
	v1.front() = 44;

	//输出头部元素
	cout << "头部元素:" << v1.front() << endl;

	//修改尾部的值(back()返回是引用，可以当左值)
	v1.back() = 99;

	//输出尾部元素
	cout << "尾部元素" << v1.back() << endl;

	//删除元素(从尾部删除)
	v1.pop_back();

	//迭代器遍历打印
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//存放三个元素，每个元素都是9
	vector<int> v5(3, 9);

	//遍历-迭代器逆向遍历
	for (vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;



		//定义优先级队列(默认是最大值优先级队列)
		priority_queue<int> p1;

		//定义一个最大优先级队列
		//less是提前定义好的预定义函数 相当于谓词
		priority_queue<int, vector<int>, less<int>> p2;

		//定义一个最小值优先级队列v
		priority_queue<int, vector<int>, greater<int>> p3;

		//给默认的最大优先级队列入栈
		p1.push(33);
		p1.push(11);
		p1.push(55);
		p1.push(22);

		//打印最大优先级的对头元素
		cout << "对头元素:" << p1.top() << endl;
		cout << "队列的大小:" << p1.size() << endl;

		//给最小值优先级队列入栈
		p3.push(33);
		p3.push(11);
		p3.push(55);
		p3.push(22);

		//打印最小优先级队列的对头元素
		cout << "P1::::" << endl;

		while (!p1.empty()) {
			cout << p1.top() << endl;
			p1.pop();
		}

		cout << "P2 :::::" << endl;

		while (!p3.empty()) {
			cout << p3.top() << endl;
			p3.pop();
		}

	


	return 0;
}

*/