#include<iostream>
#include<cassert>

using namespace std;

#define BOOL int
#define True 1
#define False 0


void SWAP_NUM(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Bubble_Sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	BOOL Flag = True;

	for (i = 0; i < sz; i++)
	{
		Flag = False;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SWAP_NUM(&arr[j], &arr[j + 1]);
				Flag = True;
			}

		}
		if (Flag == False)
			return;
	}

}

int main()
{
	int arr[] = { 2, 5, 6, 8, 9, 4, 2, 9 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}
