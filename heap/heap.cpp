// heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include <iostream>


const int HEAP_SIZE = 100;
class heap
{
public:
	heap();
	heap(std::vector<int>&);
	void push(int data);
	int pop();
	int get_head();
	int right(int pos);
	int left(int pos);
	int parent(int pos);
	int valid_node(int pos);
	void swap(int pos1, int pos2);
	void heapify(int pos);

	int data[HEAP_SIZE];
	int num_elems;
};

heap::heap()
{
	std::fill(data, data + HEAP_SIZE, 0);
	num_elems = -1;
}

heap::heap(std::vector<int>& nums)
{
	if (nums.size() < HEAP_SIZE)
	{
		std::fill(data, data + HEAP_SIZE, 0);
		std::copy(nums.begin(), nums.end(), data);
		num_elems = nums.size();

		for (int i = num_elems - 1; i >= 0; i--)
		{
			heapify(i);
		}
	}
}

void heap::push(int val)
{
	if (num_elems < HEAP_SIZE)
	{
		data[num_elems] = val;
		num_elems++;
		heapify(parent(num_elems - 1));
	}
}

int heap::pop()
{
	if (num_elems > -1)
	{
		int head = data[0];
		data[0] = data[num_elems];
		num_elems--;

		heapify(0);
		return head;
	}
}

int heap::get_head()
{
	if (num_elems)
	{
		return data[0];
	}
}

int heap::left(int pos)
{
	return valid_node(2 * pos + 1);
}

int heap::right(int pos)
{
	return valid_node(2 * pos + 2);
}

int heap::parent(int pos)
{
	return valid_node(pos/2 - 1);
}

int heap::valid_node(int pos)
{
	if (pos >= 0 && pos < num_elems)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}
void heap::swap(int pos1, int pos2)
{
	int temp = data[pos1];
	data[pos1] = data[pos2];
	data[pos2] = temp;
}
void heap::heapify(int pos)
{
	int l = left(pos);
	int r = right(pos);

	if (l == -1 && r == -1)
	{
		//pos is a leaf, nothing to do
		return;
	}
	else if (l == -1 && r != -1)
	{
		//pos has only right child
		//after swapping heap property is maintained
		if (data[pos] < data[r])
		{
			swap(pos, r);
		}
		return;
	}
	else if (l != -1 && r == -1)
	{
		//pos has only left child
		//after swapping heap property is maintained
		if (data[pos] < data[l])
		{
			swap(pos, l);
		}
		return;
	}
	else
	{
		//pos has both children
		if (data[pos] > data[l] && data[pos] > data[r])
		{
			//pos is already greater than both children, pos is already a heap
			return;
		}
		else if(data[pos] < data[l] && data[pos] > data[r])
		{
			//pos is greater than right but less than left
			//right subtree is a heap, left subtree is not a heap
			swap(pos, l);
			//left subtree needs to be re-heapified
			heapify(l);
			return;
		}
		else if (data[pos] > data[l] && data[pos] < data[r])
		{
			//pos is greater than left but less than right
			//left subtree is a heap, right subtree is not a heap
			swap(pos, r);
			//right subtree needs to be re-heapified
			heapify(r);
			return;
		}
		else if (data[pos] < data[l] && data[pos] < data[r])
		{
			//Find minimum of data[l] and data[r]
			if (data[l] < data[r])
			{
				swap(pos, r);
				heapify(r);
			}
			else
			{
				swap(pos, l);
				heapify(l);
			}
		}
	}
}



int main()
{
	std::vector<int> data{1, 7, 5, 8, 12, 9, 2};
	heap hobj(data);

	for (size_t i = 0; i < hobj.num_elems; i++)
	{
		std::cout << hobj.pop() << std::endl;
	}

    return 0;
}

