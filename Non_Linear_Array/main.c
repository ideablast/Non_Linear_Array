#include"ALL.h"

Stack *top;

int main()
{
	int *tree;
	int num_of_ary;
	int *rand_integer;
	int idx;
	
	int new_line_idx=2;
	int cnt=0;

	top = Add_new_stack();

	srand((unsigned int)time(NULL));
	tree = (int *)calloc(2, sizeof(int));

	rand_integer = (int*)calloc(TREE_MAX, sizeof(int));
	rand_integer = rand_num_new_ver();

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		printf("%d ", rand_integer[idx]);
	}
	puts("");

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		//Insert(&tree, idx+1);
		Insert(&tree, rand_integer[idx]);
		//Insert(&tree, rand() % RAND_INT_MAX + 1);
	}
	
	num_of_ary = _msize(tree) / sizeof(int);
	printf("%d\n", num_of_ary);


	for (idx = 0; idx < num_of_ary; idx++)
	{
		//if (!(tree[idx] < 0))
		if (idx != 0)
			printf("%2d ", tree[idx]);
		cnt++;

		if (cnt == new_line_idx)
		{
			puts("");
			new_line_idx = new_line_idx * 2;
		}

	}


#ifdef TEST_LAB
	for (idx = 0; idx < 10; idx++)
	{
		tree[idx] = idx;
	}

	tree = (int *)realloc(tree, 20 * sizeof(int));
	memset(tree + 10, 0, 10 * sizeof(int));
#endif

}