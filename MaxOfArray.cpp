#include<iostream>
#include<cstring>
#include<array>

using namespace std;
//int GetMaxAddOfArray(int *arr, int sz)
//{
//	int SUM = -100000;   //给定一个足够小的最大值
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = 0; j < sz; j++)
//		{
//			int subOfArr = 0;  //临时最大值
//			for (int k = i; k <= j; k++)
//			{
//				subOfArr += arr[k];
//			}
//
//			if (subOfArr > SUM)
//			{
//				SUM = subOfArr;
//			}
//		}
//	}
//	return SUM;
//}



//int GetMaxAddOfArray(int *arr, int sz)
//{
//	int SUM = -100000;   //给定一个足够小的最大值
//	for (int i = 0; i < sz; i++)
//	{
//		int subOfArr = 0;  //临时最大值
//		for (int j = i; j < sz; j++)
//		{
//			subOfArr += arr[j];
//			
//			if (subOfArr > SUM)
//			{
//				SUM = subOfArr;
//			}
//		}
//	}
//	return SUM;
//}


int GetMax(int a, int b)
{
	return (a) > (b) ? (a) : (b);
}

//int GetMaxAddOfArray(int* arr, int sz)
//{
//	if (arr == NULL || sz <= 0)
//		return 0;
//
//	int Sum = arr[0];
//	int MAX = arr[0];
//
//	for (int i = 1; i < sz; i++)
//	{
//		Sum = GetMax(Sum + arr[i], arr[i]);
//
//		if (Sum >= MAX)
//			MAX = Sum;
//	}
//	return MAX;
//}


int GetMaxAddOfArray(int* arr, int sz)
{
	if (arr == NULL || sz <= 1)
		return 0;
	int MAX = arr[0];
	int sum = arr[0];
	for (int i = 1; i < sz; i++)
	{
		if (sum < 0)
			sum = arr[i];
		else
		{
			sum += arr[i];
		}

		if (sum > MAX)
			MAX = sum;
	}
	return MAX;
}





int main()
{
	int array[] = { 2, 3, -6, 4, 6, 2, -2, 5, -9 };
	int sz = sizeof(array) / sizeof(array[0]);
	int MAX = GetMaxAddOfArray(array, sz);
	cout << MAX << endl;
	return 0;
}