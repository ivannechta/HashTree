#include "HashTree.h"
#pragma region Constructor&Destructor
HashTree::HashTree(int hash_size)
{
	HashSize = hash_size;
	*HashTable = new TreeNode[HashSize];
	for (int i = 0; i < HashSize; i++)
	{
		HashTable[i] = NULL;
	}
}

void HashTree::DeleteTree(TreeNode* p)
{
	if (p == NULL) return;
	if (p->l != NULL) { DeleteTree(p->l); }
	if (p->r != NULL) { DeleteTree(p->r); }
	delete p;
}
HashTree::~HashTree()
{
	for (int i = 0; i < HashSize; i++)
	{
		DeleteTree(HashTable[i]);
	}
	delete HashTable;
}
#pragma endregion

int HashTree::HashFunc(int data)
{
	return data % HashSize;
}