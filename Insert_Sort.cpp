#include<iostream>
#include<string>

using namespace std;

#if 0
template<typename T>
void INsert_Sort(T *array, int len)
{
	int key = 0;
	int end = 0;

	for (int i = 1; i < len; i++)
	{
		key = array[i];
		for (end = i - 1; (end >= 0) && array[end] > key; end--)
		{
			array[end + 1] = array[end];
		}
		array[end + 1] = key;
	}
}


template<typename T>
void Print(T array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}


void test()
{
	int arr[] = { 4, 8, 6, 1, 7, 9, 5, 3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	INsert_Sort(arr, sz);
	Print(arr, sz);
}

int main()
{
	test();
	return 0;
}

#endif












template<typename T>
void Print(T array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}



//template<typename T>
//void Bin_Insert_Sort(int *array, int len)
//{
//	int temp;
//	int left = 0;
//	int right = 0;
//	for (int i = 2; i <= len; i++)
//	{
//		temp = array[i];
//		left = 1;
//		right = i - 1;     //设置折半查找的范围，从1到i - 1, temp用来暂存元素
//
//		while (left <= right)
//		{
//			int mid = left + ((right + left) >> 1);
//			
//			if (temp < array[mid])
//				right = mid - 1;             //在左面查找
//			else
//				left = mid + 1;          //在右面查找
//		} 
//
//
//		for (int j = i - 1; j >= right + 1 ; --j)    //元素移动
//		{
//			array[j + 1] = array[j];
//		}
//		array[right + 1] = temp;
//	}
//}




void Bin_Insert_Sort(int* a, int n)

{

	int Low;
	int High;
	int Middle;
	for (int i = 1; i < n; ++i)
	{
		Low = 0;
		High = i - 1;
		// 求取插入位置
		while (Low <= High)
		{
			Middle = (Low + High) / 2;
			if (a[Middle] > a[i])
				High = Middle - 1;
			else
				Low = Middle + 1;
		}

		// 插入
		for (int j = i - 1; j > High; --j)
		{
			swap(a[j], a[j + 1]);     //这里也可以挨个移动元素后插入
		}
	}
}




void test()
{
	int arr[6] = {  8, 6, 1, 7, 5, 3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bin_Insert_Sort(arr, sz);
	Print(arr, sz);
}

int main()
{
	test();
	return 0;
}
