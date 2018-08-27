/*
Count
----------
A counting algorithm that counts the number of times a target value 
appears in an array of values.
*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Count(const vector<int>& countVect, const int value)
{
	return count(countVect.begin(), countVect.end(), value);
}

#ifndef COUNT_TEST
int main()
{

	int size;
	cout << "Enter the input size : ";
	cin >> size;

	vector<int> inputVect(size);
	cout << "Enter " << size << " integers:\n";
	for (int& val : inputVect)
		cin >> val;

	int countVal;
	cout << "Enter desired count value: ";
	cin >> countVal;

	int Ncount = Count(inputVect, countVal);

	cout << countVal << " appears " << Ncount << " times.\n";

    return 0;
}
#endif

