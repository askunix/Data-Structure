// 2020_10_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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





	return 0;
}

