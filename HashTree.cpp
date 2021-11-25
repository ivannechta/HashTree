#include "HashTree.h"
int HashTree::cmp(datatype a, datatype b)
{
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}
void HashTree::move(datatype* a, datatype* b)
{
	*a = *b;
}
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

int HashTree::HashFunc(datatype data)
{
	return data % HashSize;
}

void HashTree::Add(datatype data)
{
	int tmp = HashFunc(data);
	TreeNode* p = HashTable[tmp];
	if (p == NULL)
	{
		HashTable[tmp] = new TreeNode();
		move(&(HashTable[tmp]->data),&data);
		HashTable[tmp]->l = HashTable[tmp]->r = NULL;
	}
	else 
	{
		Add2Tree(p, data);
	}
}
TreeNode* HashTree::NewNode(datatype data)
{
	TreeNode* p = new TreeNode;
	
	move(&(p->data) , &data);
	p->l = p->r = NULL;
	return p;
}

void HashTree::Add2Tree(TreeNode *p,int data)
{
	if (cmp(p->data, data)==1) 
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
	if (cmp(p->data, data)==-1)
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

TreeNode* HashTree::Find2Tree(TreeNode* p, datatype data)
{
	if (p == NULL)return NULL;
	if (cmp(p->data,data)==0) return p;
	if (cmp(p->data , data)==1&&(p->l!=NULL))
	{
		return Find2Tree(p->l, data);
	}
	if (cmp(p->data , data)==-1 && (p->r != NULL))
	{
		return Find2Tree(p->r, data);
	}
	return NULL;
}

TreeNode* HashTree::Find(int data)
{	
	return Find2Tree(HashTable[HashFunc(data)], data);
}