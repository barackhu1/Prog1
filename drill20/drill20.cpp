/*	1. Define an array of int s with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.

	2. Define a vector<int> with those ten elements.

	3. Define a list<int> with those ten elements.

	4. Define a second array, vector, and list, each initialized as a copy of the first
array, vector, and list, respectively.

	5. Increase the value of each element in the array by 2; increase the value of
each element in the vector by 3; increase the value of each element in the
list by 5.
	
	6. Write a simple copy() operation,

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);

that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the
standard library copy function. Note that if f1==e1 the sequence is empty,
so that there is nothing to copy.

	7. Use your copy() to copy the array into the vector and to copy the list into
the array.

	8. Use the standard library find() to see if the vector contains the value 3
and print out its position if it does; use find() to see if the list contains the
value 27 and print out its position if it does. The “position” of the first
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found.*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

//kiiratás

template<typename C>
void print(const C& c)
{
	for (auto& i : c)
	{
		cout << i << ' ';
	}
	cout << endl;
}

//5.feladat

template <typename C>
void inc(C& c, int n){
	for (auto& i : c)
	{
		i+=n;
	}
}

//6.feladat

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for (Iter1 p = f1; p != e1; ++p)
	{
		*f2++ = *p;
	}
	return f2;
}

int main(){

	//1.feladat

	constexpr int size = 10;

	int arr[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i;
	}
	
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());

	//2.feladat

	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());

	//3.feladat

	list<int> li(size);
	copy(arr, arr + size, li.begin());

	//4.feladat

	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;

	print(ai2);
	print(vi2);
	print(li2);

	//5.feladat

	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);

	print(ai2);
	print(vi2);
	print(li2);

	//7.feladat

	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), vi2.begin());

	print(ai2);
	print(vi2);
	print(li2);

	//8.feladat

	vector<int>::iterator vit;
	vit = find(vi2.begin(),vi2.end(),3);
	if (vit != vi2.end())
	{
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	}else{
		cout << "Not found" << endl;
	}
}