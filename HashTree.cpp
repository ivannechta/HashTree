#include "HashTree.h"

HashTree::HashTree(int hash_size)
{
	HashSize = hash_size;
	*HashTable = new HashTreeElement[HashSize];
	for (int i = 0; i < HashSize; i++)
	{
		HashTable[i] = NULL;
	}
}

HashTree::~HashTree()
{

}

int HashTree::HashFunc(int data)
{
	return data % HashSize;
}