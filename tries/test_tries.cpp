// tries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "trie.h"

int main()
{
	trie T;
	T.add_string("she");
	T.add_string("by");

	T.print_strings();

}

