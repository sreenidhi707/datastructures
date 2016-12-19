#pragma once

#include<vector>
#include<string>

using namespace std;

class trie_node
{
	char c;
	bool valid;

	vector<trie_node*> children;
public:
	trie_node(char ch)
	{
		c = ch;
		valid = false;
	}

	trie_node* get(char c)
	{
		for (size_t i = 0; i < children.size(); i++)
		{
			if (children[i]->c == c)
			{
				return children[i];
			}
		}
		return NULL;
	}
};

class trie
{
	trie_node root;

	void add_string_r(string s, trie_node* node)
	{
		trie_node* next_child = node->get(s[0]);
		if (next_child == NULL)
		{
			
		}
		else
		{

		}
	}

public:
	void add_string(string s);
	{
		add_string_r(string s, trie_node* node);
	}
	void remove_string(string s);
	bool is_present(string s);
};