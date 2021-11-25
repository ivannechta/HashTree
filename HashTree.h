#pragma once
#include <stdlib.h>
#include <stdio.h>

struct TreeNode 
{	
	int data;
	TreeNode* l, * r;
};

class HashTree 
{
private:
	TreeNode** HashTable;
	int HashSize;
	void Add2Tree(TreeNode *p, int data);
	void DeleteTree(TreeNode *p);
	inline int HashFunc(int data);

public:
	HashTree(int hash_size);
	~HashTree();

	TreeNode* Find(int data);
	void Add(int data);
	void Vivod();
	void ShowTree(TreeNode *p);
};
