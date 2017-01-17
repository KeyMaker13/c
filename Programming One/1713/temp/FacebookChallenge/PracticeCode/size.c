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
	struct node *out = (malloc(sizeof(struct node)));
	assert(out);
	out->data = data;
	out->left = NULL;
	out->right = NULL;	

	return out;
}

void RecursiveInsert(struct node *in, int data)
{
	if(!in)
		in = NewNode(data);
	else if(data <= in->data)
		if(!in->left)
			in->left = NewNode(data);
		else
			RecursiveInsert(in->left, data);
	else if(data > in->data)
		if(!in->right)
			in->right = NewNode(data);
		else
			RecursiveInsert(in->right, data)
}


struct node *insert(struct node *in, int data)
{
	struct node *basep=in;

	if(in == NULL)
		return in = NewNode(data);
	else
	{
		if(data <= basep->data)		/* goes down the left side of binary tree */
			if(basep->left == NULL)
				basep->left = NewNode(data);
			else
			{
				while((data <= basep->data) && (basep->left != NULL))
					basep = basep->left;
				if((basep->left == NULL) && (data <= basep->data))
					basep->left = NewNode(data);
			}
		else			/* goes down the right side of the binary tree */
		{
			if(basep->right == NULL)
				basep->right = NewNode(data);
			else
			{
				while((data > basep->data) && (basep->right != NULL))
					basep = basep->right;
				if((basep->right == NULL) && (data > basep->data))
					basep->right = NewNode(data);
			}
		}
		return in;
	}
}


#if 0
struct node *RecInsert(struct node *in, int data)
{
	struct node *basep=in;

	if(!basep)
		return in = NewNode(data);
	else if(data <= basep->data && basep->left == NULL)
	{
		basep->left = NewNode(data);
		return in;
	}
	else if(data <= basep->data && basep->left != NULL)
		return in = RecInsert(basep->left, data);
	else if(data > basep->data && basep->right == NULL)
	{
		basep->right = NewNode(data);
		return in;
	}
	else if(data > basep->data && basep->right != NULL)
		return in = RecInsert(basep->right, data);
}
#endif

int CountNodes(struct node *in)
{
	int count=0;
	struct node *basep = in, *ptr1, *ptr2;
	if(!in)
		return 0;
	if(in)
		count++;
	if(basep->right && basep->left)
	{
		while(basep->left)
		{
			if(!(basep->left))
				break;
			else
				count++;
			basep = basep->left;
		}
	}
	if(basep->left)
		for(basep=basep->left; basep->left != NULL; basep = basep->left)
			if(basep->left)
				count++;
	if(basep->right)
		for(basep=basep->right; basep->right != NULL; basep = basep->right)
			if(basep->right)
				count++;
	return count;
}
#if 0
struct node *insert2(struct node *in, int data)
{
	struct node *basep=in, *ptr;

	if(in == NULL)
		return in = NewNode(data);
	else
	{
		if(data <= basep->data)
		{
			while(data <= basep->data && basep->left != NULL)
				basep = basep->left;
			if(data > basep->data)
				if(data >
		}	
		else
		{



		}	



	}


}
#endif
int CountNodes(struct node *in)
{
	struct node *basep=in;
	int count=0;

	
	if(basep->left != NULL)
	{
		count++;
		
	}
	else if(basep->right != NULL)
		count++;










#if 0
	fprintf(stdout, "This is basep->left data.\n\n");
	for(count=0, basep=in; basep->left != NULL; basep=basep->left, count++)
		fprintf(stdout, "Data: %d\n", basep->data);
	fprintf(stdout, "\nThis is basep->right data.\n\n");
	for(basep=in; basep->right != NULL; basep=basep->right, count++)
		fprintf(stdout, "Data: %d\n", basep->data);
	count++;
#endif
	return count;
}


/*
 * Main method of the program begins right here.
 */
int main(int nargs, char *argv[])
{
	struct node *root = NULL;
	int x, count=0, N;
	FILE *ifp;

	if(!(nargs > 1)) /* handles control if no input files were given */
	{
		fprintf(stdout, "You are about to create a binary tree by entering your own integers.\n");
		fprintf(stdout, "How many integers would you like to enter? ");
		fscanf(stdin, "%d", &N);
		fprintf(stdout, "\nEnter your integers: ");
		while(count != N)
		{
			fscanf(stdin, "%d", &x);
			RecursiveInsert(root, x);
			count++;
		}
	}
	else /* Handles control if input files were given */
	{
		ifp = fopen(argv[1], "r");
		assert(ifp);
		while(fscanf(ifp,"%d", &x) == 1)
		{
			RecursiveInsert(root, x);
			count++;
		}

	}


#if 0
	while(1)
	{
		fprintf(stdout, "Enter an integer to add to the tree: ");
		fscanf(stdin, "%d", &x);
		root = insert(root, x);
		count++;
		fprintf(stdout, "\nWould you like to enter another integer? (y/n): ");
		fscanf(stdin, "%c", &c);
		if(c == 'y' || c == 'Y')
			continue;
		else 		// else statement handles the char response if choice was not yes 
		{
			if(c == 'n' || c == 'N')
				break;
			else
			{
				while(c != 'y' || c != 'Y' || c != 'n' || c != 'N')
				{
					fprintf(stdout, "Incorrect choice entered. Enter 'y' or 'n'.\n");
					fprintf(stdout, "Would you like to enter another integer? (y/n): ");
					fscanf(stdin, "%c", &c);
				}	
				if(c == 'y' || c == 'Y')
					continue;
				else
					break;
			}
		}
		count++;
	}
#endif

	fprintf(stdout, "Count1 = %d\n", count);
	fprintf(stdout, "Count2 = %d\n", CountNodes(root));

	free(root);
	return 0;
}

















