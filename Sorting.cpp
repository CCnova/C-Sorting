//Program to implement the Merge Sort and Bubble Sort

#include <iostream>

void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
	{
		L[i] = a[l + i];
	}

	for(int j = 0; j < n2; j++)
	{
		R[j] = a[m + 1 + j];
	}

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			++i;
		}

		else
		{
			a[k] = R[j];
			++j;
		}

		++k;
	}

	while(i < n1)
	{
		a[k] = L[i];
		++i;
		++k;
	}

	while(j < n2)
	{
		a[k] = R[j];
		++j;
		++k;
	}
}

void mergeSort(int a[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r-l)/2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);

		merge(a, l, m, r);
	}
}

void bubbleSort(int arr[], int arrSize)
{
	for(int i = 0; i < arrSize - 1; i++)
	{
		for(int j = 0; j < arrSize - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void printArray(int arr[], int arrSize)
{
	for(int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';
}

int main()
{
	int n;
	std::cout << "Enter the size of the array that will be sorted: ";
	std::cin >> n;

	int arr1[n], arr2[n];

	std::cout << "Now enter the " << n << " elements of the array: " << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cin >> arr1[i]; 
		arr2[i] = arr1[i];
	}

	std::cout << "MergeSorting the array..." << std::endl;
	mergeSort(arr1, 0, n - 1);

	printArray(arr1, n);

	std::cout << "BubbleSorting the array..." << std::endl;
	bubbleSort(arr2, n);

	printArray(arr2, n);

	std::cout << '\n';

	return 0;
}