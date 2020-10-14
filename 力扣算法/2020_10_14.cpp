// 2020_10_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
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



	return 0;
}

