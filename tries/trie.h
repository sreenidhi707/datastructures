#pragma once

#include<vector>
#include<string>
#include<iostream>

using namespace std;
const uint32_t ALPHABET_SZ = 26;

class trie_node
{
public:
	bool end_of_string;
	vector<trie_node*> children;

	trie_node()
	{
		end_of_string = false;
		trie_node* temp = NULL;
		for (size_t i = 0; i < ALPHABET_SZ; i++)
		{
			children.push_back(temp);
		}
	}

	void set_char(char c, trie_node* child)
	{
		children[c - 'a'] = child;
	}
};

class trie
{
	trie_node root;

	void add_string_r(string s, trie_node* node);
	bool remove_string_r(string s, trie_node* node);
	void print_strings_r(trie_node* node, string s);

	bool is_leaf(trie_node* node);

public:
	void add_string(string s)
	{
		add_string_r(s, &root);
	}
	void remove_string(string s)
	{
		remove_string_r(s, &root);
	}
	bool is_present(string s);
	void print_strings()
	{
		print_strings_r(&root, "");
	}
};