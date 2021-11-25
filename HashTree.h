#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef int datatype;

struct TreeNode 
{	
	datatype data;
	TreeNode* l, * r;
};

class HashTree 
{
private:
	int cmp(datatype a,datatype b);
	void move(datatype* a, datatype* b);
	TreeNode** HashTable;
	int HashSize;
	void Add2Tree(TreeNode *p, int data);
	TreeNode* NewNode(datatype data);
	TreeNode* Find2Tree(TreeNode* p, int data);
	void DeleteTree(TreeNode *p);
	inline int HashFunc(datatype data);

public:
	HashTree(int hash_size);
	~HashTree();

	TreeNode* Find(datatype data);
	void Add(datatype data);
	void Vivod();
	void ShowTree(TreeNode *p);
};
