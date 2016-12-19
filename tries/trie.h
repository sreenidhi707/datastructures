#pragma once

#include<vector>
#include<string>
#include<iostream>

using namespace std;
const uint32_t ALPHABET_SZ = 26;

class trie_node
{
public:
	bool valid;
	vector<trie_node*> children;

	trie_node()
	{
		valid = false;
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
	void print_strings_r(trie_node* node, string s);

public:
	void add_string(string s)
	{
		add_string_r(s, &root);
	}
	void remove_string(string s);
	bool is_present(string s);
	void print_strings()
	{
		print_strings_r(&root, "");
	}
};