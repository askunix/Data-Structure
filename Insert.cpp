#include<iostream>
#include<cassert>
#include<string>

using namespace std;

void InsertSort(int arr[], int sz)
{
	if (sz <= 1)
		return;

	for (int i = 1; i < sz; i++)
	{
		int j = i;
		int temp = arr[j];
		while (j >0 && arr[j-1] >= temp)
		{
			swap(arr[j] ,arr[j - 1]);
			--j;
		}
		//arr[j] = temp;
	}
}


int main()
{ 
	int arr[] = { 2, 3, 5, 6, 3, 4, 1, 7, 8, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}
