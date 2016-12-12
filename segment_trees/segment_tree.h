#pragma once
#include <stdint.h>
#include <vector>

using namespace std;
class segment_tree
{
	vector<uint64_t> seg_tree; 
	uint32_t data_size;
	uint64_t construct_seg_tree(uint32_t parent_idx, vector<uint32_t>& arr, uint32_t start_idx, uint32_t end_idx);
	uint64_t get_sum(uint32_t query_start_idx, uint32_t query_end_idx,
		uint32_t arr_start_idx, uint32_t arr_end_idx,
		uint32_t parent_idx);
	uint64_t update_r(uint32_t arr_start_idx, uint32_t arr_end_idx, uint32_t current_idx, uint32_t index, uint64_t value);

	public:
		segment_tree(vector<uint32_t>& data);
		uint64_t query(uint32_t query_start_idx, uint32_t query_end_idx);
		void update(uint32_t index, uint64_t value);

};

class naive_segment_tree
{
	vector<uint32_t> seg_tree;

	public:
		naive_segment_tree(vector<uint32_t>& data); 
		uint64_t query(uint32_t query_start_idx, uint32_t query_end_idx);
		void update(uint32_t index, uint64_t value);
};

