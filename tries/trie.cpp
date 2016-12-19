#include "stdafx.h"

#include "trie.h"

void trie::add_string_r(string s, trie_node* node)
{
	trie_node* next_child = new trie_node;
	node->set_char(s[0], next_child);

	if (s.size() > 1)
	{
		string child_str = s.substr(1, s.size() - 1);
		add_string_r(child_str, next_child);
	}
	else
	{
		node->valid = true;
	}
}

void trie::print_strings_r(trie_node* node, string s)
{
	if (node->valid)
	{
		cout << s << endl;
	}

	for (size_t i = 0; i < ALPHABET_SZ; i++)
	{		
		if (node->children[i] != NULL)
		{
			char node_char = 'a' + i;
			s.insert(0, &node_char);
			print_strings_r(node->children[i], s);
		}
	}
}