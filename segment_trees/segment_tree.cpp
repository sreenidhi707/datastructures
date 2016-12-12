#include "stdafx.h"

#include "segment_tree.h"
#include <cassert>

uint32_t mid(uint32_t s, uint32_t e)
{
	return(s + (e - s)/2);
}

segment_tree::segment_tree(vector<uint32_t>& data)
{
	//Initialize segment tree with zeros
	data_size = data.size();
	uint32_t tree_size = uint32_t(ceil(log2(data_size)));
	tree_size = 2 * pow(2, tree_size) - 1;
	for (size_t i = 0; i < tree_size; i++)
	{
		seg_tree.push_back(0);
	}

	construct_seg_tree(0, data, 0, data.size() - 1);

}

uint64_t segment_tree::query(uint32_t query_start_idx, uint32_t query_end_idx)
{
	return(get_sum(query_start_idx, query_end_idx,
					0, data_size - 1,
					0));
}

uint64_t segment_tree::construct_seg_tree(uint32_t current_idx, vector<uint32_t>& arr, uint32_t start_idx, uint32_t end_idx)
{
	if (start_idx == end_idx)
	{
		seg_tree[current_idx] = arr[start_idx];
		return seg_tree[current_idx];
	}
	else
	{
		uint32_t middle = mid(start_idx, end_idx);
		uint32_t left_sum =		construct_seg_tree(2 * current_idx + 1,	arr, start_idx, middle);
		uint32_t right_sum =	construct_seg_tree(2 * current_idx + 2,	arr, middle + 1,end_idx	);
		seg_tree[current_idx] = left_sum + right_sum;
		return seg_tree[current_idx];
	}
}

uint64_t segment_tree::get_sum(	uint32_t query_start_idx, uint32_t query_end_idx, uint32_t arr_start_idx, uint32_t arr_end_idx, uint32_t current_idx)
{
	uint32_t arr_mid_idx = mid(arr_start_idx, arr_end_idx);
	uint32_t query_mid_idx = mid(query_start_idx, query_end_idx);

	if (query_start_idx == arr_start_idx  && query_end_idx  == arr_end_idx)
	{
		return seg_tree[current_idx];
	}
	else if(query_start_idx >= arr_mid_idx + 1)
	{
		//divide array and query
		uint32_t right_sum = get_sum(query_start_idx, query_end_idx, arr_mid_idx + 1, arr_end_idx, 2 * current_idx + 2);
		return(right_sum);
	}
	else if (query_end_idx <= arr_mid_idx)
	{
		uint32_t left_sum = get_sum(query_start_idx, query_end_idx, arr_start_idx, arr_mid_idx, 2 * current_idx + 1);
		return(left_sum);
	}
	else
	{
		uint32_t new_query_start_right = arr_mid_idx + 1;
		uint32_t new_query_end_left = arr_mid_idx;
		uint32_t left_sum = get_sum(query_start_idx,       new_query_end_left, arr_start_idx,   arr_mid_idx, 2 * current_idx + 1);
		uint32_t right_sum =  get_sum(new_query_start_right, query_end_idx,      arr_mid_idx + 1, arr_end_idx, 2 * current_idx + 2);
		return(left_sum + right_sum);
	}
}

void segment_tree::update(uint32_t index, uint64_t value)
{
	update_r(0, data_size - 1, 0, index, value);
}

uint64_t segment_tree::update_r(uint32_t arr_start_idx, uint32_t arr_end_idx, uint32_t current_idx, uint32_t index, uint64_t value)
{
	uint32_t middle = mid(arr_start_idx, arr_end_idx);
	
	if (arr_start_idx == arr_end_idx) //update index is the current index
	{
		assert(arr_start_idx == index);

		int32_t diff = value - seg_tree[current_idx];
		seg_tree[current_idx] = value;
		return diff;
	}
	else if (index <= middle) //update index falls on the left tree
	{
		uint32_t diff = update_r(arr_start_idx, middle, 2 * current_idx + 1, index, value);
		seg_tree[current_idx] += diff;
		return diff;
	}
	else if (index > middle) //update index falls on the right tree
	{
		uint32_t diff = update_r(middle + 1, arr_end_idx, 2 * current_idx + 2, index, value);
		seg_tree[current_idx] += diff;
		return diff;
	}
}

naive_segment_tree::naive_segment_tree(vector<uint32_t>& data)
{
	seg_tree = data;
}

uint64_t naive_segment_tree::query(uint32_t query_start_idx, uint32_t query_end_idx)
{
	uint64_t sum = 0;
	for (size_t i = query_start_idx; i <= query_end_idx; i++)
	{
		sum += seg_tree[i];
	}
	return sum;
}

void naive_segment_tree::update(uint32_t index, uint64_t value)
{
	seg_tree[index] = value;
}

