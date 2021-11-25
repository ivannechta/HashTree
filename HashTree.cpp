#include "HashTree.h"
#pragma region Constructor&Destructor
HashTree::HashTree(int hash_size)
{
	HashSize = hash_size;
	HashTable = new TreeNode*[HashSize];
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

void HashTree::Add(int data)
{
	int tmp = HashFunc(data);
	TreeNode* p = HashTable[tmp];
	if (p == NULL)
	{
		HashTable[tmp] = new TreeNode();
		HashTable[tmp]->data = data;
		HashTable[tmp]->l = HashTable[tmp]->r = NULL;
	}
	else 
	{
		Add2Tree(p, data);
	}
}
TreeNode* NewNode(int data)
{
	TreeNode* p=new TreeNode;
	p->data = data;
	p->l = p->r = NULL;
	return p;
}

void HashTree::Add2Tree(TreeNode *p,int data)
{
	if (p->data > data) 
	{
		if ((p->l) == NULL)
		{
			p->l = NewNode(data);
		}
		else 
		{
			Add2Tree(p->l, data);
		}
		return;
	}
	if (p->data < data)
	{
		if ((p->r) == NULL)
		{
			p->r = NewNode(data);
		}
		else
		{
			Add2Tree(p->r, data);
		}
		return;
	}	
#pragma message ("What to do with equal data in hash table?")
}
void HashTree::ShowTree(TreeNode* p)
{
	if (p == NULL) return;
	ShowTree(p->l);
	printf("%d ",p->data);
	ShowTree(p->r);
}
void HashTree::Vivod() 
{
	for (int i = 0; i < HashSize; i++)
	{	
		ShowTree(HashTable[i]);
	}
}

TreeNode* HashTree::Find2Tree(TreeNode* p, int data)
{
	if (p == NULL)return NULL;
	if (p->data == data) return p;
	if ((p->data > data)&&(p->l!=NULL))
	{
		return Find2Tree(p->l, data);
	}
	if ((p->data < data) && (p->r != NULL))
	{
		return Find2Tree(p->r, data);
	}
	return NULL;
}

TreeNode* HashTree::Find(int data)
{	
	return Find2Tree(HashTable[HashFunc(data)], data);
}