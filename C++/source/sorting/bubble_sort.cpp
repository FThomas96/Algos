/*
Bubble sort
-----------
A simple sorting algorithm that repeatedly compares pairs of adjacent
elements and swaps their positions if they are in the wrong order.
Also known as sinking sort.
Time complexity
---------------
O(N^2), where N is the number of elements.
Space complexity
----------------
O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool bubble_sort(int size, const vector<T> &arr)
{
	bool isSorted = true;
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap((int*)arr[j], (int*)arr[j + 1]);
				isSorted = false;
			}
		}
	}
	return isSorted;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

#ifndef BUBBLE_SORT_TEST
int main()
{
	int size = 0;
	cout << "Enter the input size : ";
	cin >> size;

	vector<int> arr(size);
	cout << "Enter the numbers: " << endl;
	for (int& num : arr)
		cin >> num;

	bubble_sort(size,arr);
	cout << "The sorted numbers are: " << endl;
	for (int index = 0; index < size; index++)
		cout << arr[index] << ", ";

	return 0;
}

#endif // BUBBLE_SORT_TEST
