#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include<time.h>


#if 0
//一般方法


int SelectPivot(int arr[],int low,int high) 
//low第一个元素，high最后一个元素
{
	return arr[low];//选择选取序列的第一个元素作为基准
}



int QKpass(int s[], int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	int x = SelectPivot(s, l, r); //s[l]即s[i]就是第一个坑
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while (i < j && s[j] >= x)
			j--;
		if (i < j)
		{
			s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}

		// 从左向右找大于或等于x的数来填s[j]
		while (i < j && s[i] < x)
			i++;
		if (i < j)
		{
			s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = x;

	return i;
}




void Quick_Sort(int *arr, int low, int high)
{
	int pos = 0;
	if (low < high)
	{
		pos = QKpass(arr, low, high);    //以pos为基准，划分两个序列
		Quick_Sort(arr, low, pos - 1);
		Quick_Sort(arr, pos + 1, high);
	}
}

#endif



#if 0
//随机生成基准

void swap_p(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

int SelectPivot(int arr[], int low, int high)
{
	srand((unsigned)time(NULL));
	int pivot_pos = rand() % (high - low) + low;
	swap_p(&arr[pivot_pos], &arr[low]);
	return arr[low];
}

int QKpass(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int k = SelectPivot(arr, left, right);

	while (i < j)
	{
		while ( i < j && arr[j] >= k)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		while (i < j && arr[i] < k)
		{
			i++;
		}

		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}
	arr[i] = k;
	return i;
}


void Quick_Sort(int *arr, int low, int high)
{
	int pos = 0;
	if (low < high)
	{
		pos = QKpass(arr, low, high);
		Quick_Sort(arr, low, pos - 1);
		Quick_Sort(arr, pos + 1, high);
	}
}
#endif






#if 0
//三元取中法

void swap_(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


int SelectPivot(int arr[], int left, int right)
{
	//三数取中，并把中间值放到left的位置
	int mid = 0;
	mid = left + ((right - left) >> 1);

	if (arr[mid] > arr[right])
	{
		swap_(arr[mid], arr[right]);
	}

	if (arr[left] > arr[right])
	{
		swap_(arr[left], arr[right]);
	}

	if (arr[mid] > arr[left])
	{
		swap_(arr[mid], arr[left]);
	}
	return arr[left];
}


int QK_pass(int arr[], int low, int high)
{
	int k = SelectPivot(arr, low, high);
	int i = low;
	int j = high;

	while (i < j)
	{
		while (i < j && arr[j] >= k)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] =arr[j];
			i++;
		}

		while (i < j && arr[i] < k)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j++;
		}
	}
	arr[i] = k;
	return i;
}



void Quick_Sort(int arr[], int low, int high)
{
	int pos = 0;
	if (low < high)
	{
		pos = QK_pass(arr, low, high);
		Quick_Sort(arr, low, pos - 1);
		Quick_Sort(arr, pos + 1, high);
	}
}

#endif


//******************************************************
//*********尾递归优化 + 插入排序 + 三值取中*************
//******************************************************


void swap_(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


int SelectPivot(int arr[], int left, int right)
{
	//三数取中，并把中间值放到left的位置
	int mid = 0;
	mid = left + ((right - left) >> 1);

	if (arr[mid] > arr[right])
	{
		swap_(&arr[mid], &arr[right]);
	}

	if (arr[left] > arr[right])
	{
		swap_(&arr[left], &arr[right]);
	}

	if (arr[mid] > arr[left])
	{
		swap_(&arr[mid], &arr[left]);
	}
	return arr[left];
}



int QK_pass(int arr[], int low, int high)
{
	int k = SelectPivot(arr, low, high);
	int i = low;
	int j = high;

	while (i < j)
	{
		while (i < j && arr[j] >= k)
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		while (i < j && arr[i] < k)
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j++;
		}
	}
	arr[i] = k;
	return i;
}



void InsertSort(int arr[], int sz)
{
	//直接插入排序
	int i, j;
	for (i = 1; i < sz; i++)
	for (j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		swap_(&arr[j], &arr[j + 1]);
}


void Quick_Sort(int arr[], int low, int high)
{
	int PivotPos;
	int len = 0;
	if (high - low + 1 < 10)
	{
		len = high - low + 1;
		InsertSort(arr, len);
		return;
	}

	while (low < high)
	{
		PivotPos = QK_pass(arr, low, high);
		Quick_Sort(arr, low, PivotPos - 1);
		low = PivotPos + 1;
	}

}




int main()
{
	int arr[] = { 3, 6, 5, 1, 7, 8, 9, 3, 2 };
	int i = 0;
	int low = 0;
	int high = sizeof(arr) / sizeof(arr[0]) -1 ;
	Quick_Sort(arr, low, high);
	for (i = 0; i < high; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}
