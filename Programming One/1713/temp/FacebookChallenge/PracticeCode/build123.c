#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

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
	if(node->data <= data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

struct node *insert2(struct node *root, int data)
{
	int x = root->data;
	if(x <= data)
		root->left = NewNode(data);
	else
		root->right = NewNode(data);
	return root;
}

struct node *build123a()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	return root;
}


int main()
{
/*	struct node *root = build123a(); */
	struct node *root2 = NewNode(2);
	root2 = insert2(root2, 1);
	root2 = insert2(root2, 3);
	struct node *root3 = NewNode(2);
	root3->left = NewNode(1);
	root3->right = NewNode(3);
/*	root2->left = NewNode(1);
	root2->right = NewNode(3); */
	struct node *basep;

	struct node *one, *two, *three;
	one = NewNode(1);
	two = NewNode(2);
	three = NewNode(3);

	two->left = one;
	two->right = three;

	basep = two;
	fprintf(stdout, "two: %d\n", basep->data);
	basep = basep->left;
	fprintf(stdout, "one: %d\n", basep->data);
	basep = two;
	fprintf(stdout, "two: %d\n", basep->data);
	basep = basep->right;
	fprintf(stdout, "three: %d\n", basep->data);

	printf("End of fixed test.\n");


















	basep = root3;
	while(1)
	{
		if(basep->left == NULL)
			break;
		else
		{
			fprintf(stdout, "root2: %d\n", basep->data);
			basep = basep->left;
		}
	}

	basep = root3;
	while(1)
	{
		if(basep->right == NULL)
			break;
		else
		{
			fprintf(stdout, "root2: %d\n", basep->data);
			basep = basep->right;
		}
	}


/*
	fprintf(stdout, "\nLeft node pointers.\n\n");
	for(basep = root2; basep->left != NULL; basep=basep->left)
		fprintf(stdout, "Left node: %d\n", basep->data);

	fprintf(stdout, "\nRight node pointers.\n\n");
	for(basep = root2; basep->right != NULL; basep=basep->right)
		fprintf(stdout, "Right node: %d\n", basep->data);
*/
	return 0;
}

















