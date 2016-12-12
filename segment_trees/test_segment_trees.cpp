// test_segment_trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "segment_tree.h"

#include <cassert>
#include <iostream> 
#include <algorithm>
#include <ctime>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

vector<uint32_t> get_random_array(uint32_t n)
{
	vector<uint32_t> temp;

	for (size_t i = 1; i <= n; i++)
	{
		temp.push_back(i);
	}

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));

	return temp;
}

int main()
{
	//vector<uint32_t> data = { 1, 2, 3, 4, 5, 6, 7 };
	
	//segment_tree seg_tree(data);
	
	//seg_tree.update(5, 10);

	for (size_t data_size = 10; data_size < 1000; data_size++)
	{
		vector<uint32_t> data = get_random_array(data_size);
	
		cout << "Test:" << data_size << endl;
		/*for (size_t i = 0; i < data.size(); i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;*/


		segment_tree seg_tree(data);
		naive_segment_tree naive_seg_tree(data);

		double total_seg_tree_qtime = 0, total_naive_seg_tree_qtime = 0;
		double total_seg_tree_utime = 0, total_naive_seg_tree_utime = 0;
		
		for (size_t i = 0; i < data_size; i++)
		{
			//Query test
			uint32_t low = 0, high = data_size - 1;
			uint32_t rand_start_idx = rand() % (high - low + 1) + low;
			low = rand_start_idx;
			uint32_t rand_end_idx = rand() % (high - low + 1) + low;

			clock_t begin = clock();
			uint64_t seg_tree_query = seg_tree.query(rand_start_idx, rand_end_idx);
			clock_t end = clock();
			double seg_tree_qsecs = double(end - begin) / CLOCKS_PER_SEC;
			total_seg_tree_qtime += seg_tree_qsecs;

			begin = clock();
			uint64_t naive_seg_tree_query = naive_seg_tree.query(rand_start_idx, rand_end_idx);
			end = clock();
			double naive_seg_tree_qsecs = double(end - begin) / CLOCKS_PER_SEC;
			total_naive_seg_tree_qtime += naive_seg_tree_qsecs;

			//Update test
			low = 0, high = data_size - 1;
			uint32_t rand_idx = rand() % (high - low + 1) + low;
			uint64_t low_val = 1, high_val = UINT64_MAX;
			uint64_t rand_val = rand() % (high_val - low_val + 1) + low_val; rand_val = 100;
			
			begin = clock();
			seg_tree.update(rand_idx, rand_val);
			end = clock();
			double seg_tree_usecs = double(end - begin) / CLOCKS_PER_SEC;
			total_seg_tree_utime += seg_tree_usecs;

			begin = clock();
			naive_seg_tree.update(rand_idx, rand_val);
			end = clock();
			double naive_seg_tree_usecs = double(end - begin) / CLOCKS_PER_SEC;
			total_naive_seg_tree_utime += naive_seg_tree_usecs;

			assert(seg_tree.query(0, data_size - 1) == naive_seg_tree.query(0, data_size - 1));
		}
		cout << "Segment tree query :" << total_seg_tree_qtime << " Naive Segment tree query :" << total_naive_seg_tree_qtime << endl;
		cout << "Segment tree update:" << total_seg_tree_utime << " Naive Segment tree update:" << total_naive_seg_tree_utime << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;		
	}

	return 0;
}

