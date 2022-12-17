
#include "malloc.h"
#include "stdio.h"
#include "conio.h"

int level = 1;

struct Node {
	int vis;
	int data;
	struct Node* left;
	struct Node* right;
};
int Counter = 0;

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* NewBranch, int data)
{
	if (NewBranch == NULL)
	{
		NewBranch = (struct Node*)malloc(sizeof(struct Node));
		if (NewBranch == NULL)
		{
			printf("Ошибка выделения памяти");
			return 0;
		}

		NewBranch->left = NULL;
		NewBranch->right = NULL;
		NewBranch->data = data;
		if (root == NULL) return NewBranch;

		if (data > root->data)	root->left = NewBranch;
		else root->right = NewBranch;
		return NewBranch;
	}

	if (data > NewBranch->data)
		CreateTree(NewBranch, NewBranch->left, data);
	else
		CreateTree(NewBranch, NewBranch->right, data);

	return root;
}


int SearchInTree(struct Node* NewBranch, int searchable, int level) {

	if (NewBranch == NULL)
	{
		return 0;
	}
	SearchInTree(NewBranch->right, searchable, level + 1);
	if (NewBranch->data == searchable) {
		printf("Found on %d level\n", level);
		Counter++;
	}
	SearchInTree(NewBranch->left, searchable, level + 1);
	return 0;
}





void print_tree(struct Node* NewBranch, int l)
{

	if (NewBranch == NULL)
	{
		return;
	}

	print_tree(NewBranch->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf("   ");
	}

	printf("%d\n", NewBranch->data);
	print_tree(NewBranch->left, l + 1);
}

int main()
{

	int D, start = 1;
	int S = 0;
	root = NULL;
	printf("-1 - End of tree-building\n");
	while (start)
	{
		printf("Enter number: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Tree-buidling is done\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);


	printf("Search number\n");
	scanf_s("%d", &S);
	SearchInTree(root, S, level);
	printf("Count: %d", Counter);

	getchar();
	getchar();
	return 0;
}


