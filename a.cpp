#include<iostream>
#include<cassert>
#include<string>
//
//using namespace std;
//
//
//void test()
//{
//	int arr[] = { 2, 3, 4, 5, 2, 3 };
//	dullicate(arr[], len, )
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//
//#include <iostream>
//
//using namespace std;
//
//bool duplicate(int numbers[], int length, int* duplication)
//{
//	if (numbers == NULL || length <= 1)
//	{
//		duplication = NULL;
//		return false;
//	}
//
//	for (int i = 0; i<length; i++)
//	{
//		while (numbers[i] != i)
//		{
//			if (numbers[i] == numbers[numbers[i]])
//			{
//				*duplication = numbers[i];
//				return true;
//			}
//			int tmp = numbers[i];
//			numbers[i] = numbers[tmp];
//			numbers[tmp] = tmp;
//		}
//	}
//
//	return false;
//}
//
//int main()
//{
//	int A[] = { 2, 2, 0, 1, 2, 5, 3};
//	int len = sizeof(A) / sizeof(A[0]);
//
//	int duplication;
//	cout <<"答案" <<duplicate(A, len, &duplication) << endl;
//	cout << duplication << endl;
//	return 0;
//}


using namespace std;

int CountNum(const int *a, int len, int l, int r)
{
	if (a == NULL)
		return 0;

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= l && a[i] <= r)
			++count;
	}
	return count;
}

int GetLotsOfNum(const int *arr, int sz)
{
	if (arr == NULL || sz <= 0)
		return -1;

	int start = 1;
	int end = sz - 1;

	while (start <= end)
	{
		int mid = start + ((end - start) >> 1);
		int count = CountNum(arr, sz, start, end);
		
		if (start == end)
		{
			if (count > 1)
			    return start;
			else
				break;
		}
		if (count > (mid - start + 1))
			end = mid;
		else
			start = mid + 1;
	}
	return -1;
}




int main()
{
	int A[] = { 2, 3, 5, 4, 3, 2, 6, 7};
	int len = sizeof(A) / sizeof(A[0]);
	cout << GetLotsOfNum(A, len) << endl;
	return 0;
}
