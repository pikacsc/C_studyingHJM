#include <stdio.h>
#include <stdlib.h>
#include "MyTree.h"


enum comp_symbol
{
	LEFT = -1,
	SAME = 0,
	RIGHT = 1
	
};

typedef struct pair
{
	Node* parent;
	Node* child;
} Pair;



/* Prototypes for local functions */
static Node* MakeNode(const Item* pi);
static void AddNode(Node* new_node, Node* root);
static void InOrder(const Node* root, void (*pfun)(Item item));
static void PreOrder(const Node* root, void (*pfun)(Item item));
static void PostOrder(const Node* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Node** ptr);
static void DeleteAllNodes(Node* ptr);
static Item* Search(Node* root, const Item to_search);

static int(*compare_funcPtr)(const Item item1, const Item item2) = NULL;


void InitTree(Tree* ptree, int(comp_func)(const Item item1, const Item item2))
{
	ptree->root = NULL;
	ptree->size = 0;
	compare_funcPtr = comp_func;
}

bool TreeIsEmpty(const Tree* ptree)
{
	return (!ptree->root);
}

bool TreeIsFull(const Tree* ptree)
{
	return ptree->size == TMAX;
}

int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}

void AddNode(Node* new_node, Node* root)
{
	int comp = compare_funcPtr(new_node->item, root->item);
	if (comp == 0)
	{
		printf("Cannot add a duplicated item.\n");
		free(new_node);
		return;
	}
	else if (comp < 0)
	{
		if (!root->left)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else // compare > 0
	{
		if (!root->right)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
}

//use recursive calling
bool AddItem(const Item* pi, Tree* ptree)
{
	//When Full
	if (TreeIsFull(ptree))
	{
		printf("Can't add more items.\n");
		return false;
	}

	Node* new_node = MakeNode(pi);

	ptree->size++;

	if (ptree->root == NULL) //When begin(no root node)
		ptree->root = new_node;
	else 
		AddNode(new_node, ptree->root);

	return true;
}



//use recursive calling
//check if item is in Tree
bool InTree(const Item* pi, const Tree* ptree)
{
	return (SeekItem(pi,ptree).child == NULL) ? false : true;
}


//one leaf
//two leaf
bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;

	look = SeekItem(pi, ptree);
	if (!look.child) //no leaf
		return false;

	if (!look.parent)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

Node* MakeNode(const Item* pi)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	if (newNode)
	{
		newNode->item = *pi;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		printf("Malloc() failed.\n");
		exit(1);
	}
	return newNode;
}

static void PreOrder(const Node* root, void(*pfun)(Item item))
{
	if (!root)
		return;

	(*pfun)(root->item);
	PreOrder(root->left, pfun);
	PreOrder(root->right, pfun);
}

static void InOrder(const Node* root, void(*pfun)(Item item))
{
	if (!root)
		return;
	
	InOrder(root->left, pfun);
	(*pfun)(root->item);
	InOrder(root->right, pfun);
}


void PostOrder(const Node* root, void(*pfun)(Item item))
{
	if (!root)
		return;
	PostOrder(root->left, pfun);
	PostOrder(root->right, pfun);
	(*pfun)(root->item);
}

static Pair SeekItem(const Item* pi, const Tree* ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (!look.child)
		return look;

	while (look.child)
	{
		int comp = compare_funcPtr(*pi, look.child->item);

		if (comp == LEFT)
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (comp == RIGHT)
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

void DeleteNode(Node** ptr)
/* ptr is address of parent member pointing to target node */
{
	Node* temp;

	if (!(*ptr)->left)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if (!(*ptr)->right)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else  /* deleted node has two children */
	{
		/* find where to reattach right subtree */
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;

		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}

}

void DeleteAllNodes(Node* root)
{
	if (!root)
		return;

	Node* pright = root->right;
	DeleteAllNodes(root->left);
	free(root);
	DeleteAllNodes(pright);
}

Item* Search(Node* root, const Item to_search)
{
	if (!root)
		return NULL;

	int comp = compare_funcPtr(to_search, root->item);

	// This is an example of preorder traversal
	if (comp == SAME)
		return &root->item;
	else if (comp == LEFT)
		return Search(root->left, to_search);
	else
		return Search(root->right, to_search);
}

void Traverse(const Tree* ptree, void(*pfun)(Item item))
{
	if (ptree)
		InOrder(ptree->root, pfun);

}

void DeleteAll(Tree* ptree)
{
	if (!ptree)
		return;

	DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

Item* TreeSearch(Tree* tree, const Item key)
{
	return Search(tree->root,key);
}
