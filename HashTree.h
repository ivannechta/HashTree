#pragma once
#include <stdlib.h>

struct HashTreeElement 
{
	TreeNode* t;
};

struct TreeNode 
{
	HashTreeElement* el;
	int data;
	TreeNode* l, * r;
};

class HashTree 
{
private:
	HashTreeElement** HashTable;
	int HashSize;
	//void Add2Tree(HashTreeElement **p, int data);
	void DeleteTree(TreeNode *p);
	inline int HashFunc(int data);

public:
	HashTree(int hash_size);
	~HashTree();

	HashTreeElement* Find(int data);
	void Add(int data);
};
