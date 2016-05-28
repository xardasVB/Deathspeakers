#pragma once

#include <Windows.h>
#include <iostream>

using namespace std;

template <typename T>
void AddElement(T* &arr, int  &size, int position, T newElement)
{
	T *tmpArr = new T[size + 1];

	if (position < 0)
	{
		position = 0;
	}
	else if (position > size - 1)
	{
		position = size;
	}

	for (int i = 0, j = 0; i < size + 1; i++)
	{
		if (i == position)
		{
			tmpArr[i] = new T(newElement);
		}
		else
		{
			tmpArr[i] = new T(arr[j]);
			++j;
		}
	}

	++size;

	delete[] arr;

	arr = tmpArr;
}

template <typename T>
void RemoveElement(T* &arr, int &size, int position)
{
	T *tmpArr = new T[size - 1];

	if (position < 0)
	{
		position = 0;
	}
	else if (position > size - 1)
	{
		position = size;
	}

	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != position)
		{
			tmpArr[j] = arr[i];
			j++;
		}
	}

	--size;

	delete[] arr;

	arr = tmpArr;

}
