#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}

struct node *NewNode(int data)
{
	struct node *node = (malloc(sizeof(struct node)));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

struct node *insert(struct node *node, int data)
{
	if(node == NULL)
		return newNode(data);
	else
	{
		if(data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node-right, data);
		return node;
	}
}





int main()
{




	return 0;
}







