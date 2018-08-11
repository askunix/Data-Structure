#include<iostream>

using namespace std;



//
//void Shell_Sort1(int *arr, int sz)
//{
//	int i ,j;
//	int inc = sz;//增量
//	int key;
//	while (inc > 1)
//	{
//		inc = inc / 3 + 1;
//		cout << inc << endl;
//
//		for (i = inc; i < sz; i++)   //从0开始，对相距增量步长的元素集合进行修改
//		{
//			key = arr[i];
//
//			//直接插入排序
//			j = i - inc;
//
//			while (j >= 0)
//			{
//				if (key < arr[j])
//				{
//					int temp = arr[j];
//					arr[j] = key;
//					arr[j + inc] = temp;
//				}
//				j = j - inc;
//			}
//		}
//	}
//}
//






//
//int main()
//{
//	int array[] = { 23, 4, 5, 6, 89, 23, 1, 7, 8, 44 };
//	int sz = sizeof(array) / sizeof(array[0]);
//	Shell_Sort1(array, sz);
//	int i = 0;
//	while (i < sz)
//		cout << array[i++] << "  ";
//	return 0;
//}







void prt_ary(int *ary, int len)
{
	int i = 0;
	while (i < len)
	{
		printf(" %d ", ary[i++]);
	}
	printf("\n");
}



void shellSort(int *ary, int len)
{
	int i, j;
	int increment = len;//增量
	myDataType key;
	while (increment > 1)//最后在增量为1并且是执行了情况下停止。
	{
		increment = increment / 3 + 1;//根据公式
		//increment /= 2;

		printf("increment:%d\n",increment);
		for (i = increment; i<len; i++)//从[0]开始，对相距增量步长的元素集合进行修改。
		{
			key = ary[i];
			//以下和直接插入排序类似。
			j = i - increment;
			while (j >= 0)
			{
				if (key < ary[j])
				{
					int temp = ary[j];
					ary[j] = key;
					ary[j + increment] = temp;
				}
				j = j - increment;
			}
		}
	}
}



int main()
{
	int src_ary[10] = { 9, 1, 5, 8, 3, 7, 6, 0, 2, 4 };
	printf("before sort:\n");
	prt_ary(src_ary, 10);

	shellSort(src_ary, 10);

	printf("after sort:\n");
	prt_ary(src_ary, 10);


	return 0;
}
