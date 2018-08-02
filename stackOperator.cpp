//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<stack>
//using namespace std;
//
//
//
//#define Datatype int
//
//
//int main()
//{
//	stack<Datatype> s1;
//	stack<Datatype> s2;
//
//	for (int i = 0; i < 5; i++)
//	{
//		s1.push(i+1);
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		int top = s1.top();
//		s2.push(top);
//		s1.pop();
//	}
//
//	for ( int i = 0; i < 5; i++)
//	{
//		int ret = s2.top();
//		cout << ret << endl;
//		s2.pop();
//	}
//	return 0;
//}






#include<iostream>
using namespace std;

struct stack
{
	int data[5];
	int top;
};



int main()
{
	struct stack s1, s2;
	s1.top = 0;
	s2.top = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> s1.data[s1.top];
		s1.top++;
	}


	//栈1数据弹出至栈2
	while (s1.top > 0){
		s1.top--;
		s2.data[s2.top] = s1.data[s1.top];
		s2.top++;
	}


	//栈2数据弹出
	while (s2.top > 0){
		s2.top--;
		cout << s2.data[s2.top] << endl;
	}


	return 0;
}
