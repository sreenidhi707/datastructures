#include "stdafx.h"

#include "trie.h"

void trie::add_string_r(string s, trie_node* node)
{
	trie_node* next_child;
	
	if (s.size() > 0)
	{
		next_child = new trie_node;
		node->set_char(s[0], next_child);
		
		string child_str = s.substr(1, s.size() - 1);
		add_string_r(child_str, next_child);
	}
	else
	{
		node->end_of_string = true;
	}
}

bool trie::remove_string_r(string s, trie_node* node)
{
	if (node->end_of_string)
	{
		//check if this node has any children
		if (is_leaf(node))
		{
			return true;
		}
		else
		{
			node->end_of_string = false;
			return false;
		}
	}

	string child_str = s.substr(1, s.size() - 1);
	char node_char = s[0];
	bool remove_this_node = remove_string_r(child_str, node->children[node_char - 'a']);

	if (remove_this_node)
	{
		delete node->children[node_char - 'a'];
		node->children[node_char - 'a'] = NULL;

		if (is_leaf(node))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void trie::print_strings_r(trie_node* node, string s)
{
	if (node->end_of_string)
	{
		cout << s << endl;
		s.clear();
	}

	for (size_t i = 0; i < ALPHABET_SZ; i++)
	{		
		if (node->children[i] != NULL)
		{
			char node_char = 'a' + i;
			s.push_back(node_char);
			print_strings_r(node->children[i], s);
		}
	}
}

bool trie::is_leaf(trie_node* node)
{
	for (size_t i = 0; i < ALPHABET_SZ; i++)
	{
		if (node->children[i] != NULL)
		{
			return false;
		}
	}
	return true;
}