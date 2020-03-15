#include"ALL.h"

Stack *top;

int main()
{
	int *tree;
	int num_of_ary;
	int *rand_integer;
	int idx;

	int new_line_idx = 2;
	int cnt = 0;

	/*TEST
	int test_int[TREE_MAX] = { 20, 16,37,35,15,23,91,60,12,57 };
	*/
	

	top = Add_new_stack();

	srand((unsigned int)time(NULL));
	tree = (int *)calloc(2, sizeof(int));

	rand_integer = (int*)calloc(TREE_MAX, sizeof(int));
	//memcpy(rand_integer, test_int, TREE_MAX * sizeof(int));
	rand_integer = rand_num_new_ver();

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		printf("%d ", rand_integer[idx]);
	}
	puts("");

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		Insert(&tree, rand_integer[idx]);
	}

	num_of_ary = _msize(tree) / sizeof(int);
	printf("할당된 노드 수: %d\n", num_of_ary);
	Print_Tree(tree);


	/*TEST
		Delete(&tree, 37);
	Print_Tree(tree);
	Delete(&tree, 91);
	Print_Tree(tree);
	Delete(&tree, 12);
	Print_Tree(tree);
	Delete(&tree, 23);
	Print_Tree(tree);
	*/

	

#ifdef TEST_LAB

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
	for (idx = 0; idx < 10; idx++)
	{
		tree[idx] = idx;
	}

	tree = (int *)realloc(tree, 20 * sizeof(int));
	memset(tree + 10, 0, 10 * sizeof(int));



	puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[4]);
	Delete(&tree, rand_integer[4]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[5]);
	Delete(&tree, rand_integer[5]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------");
	puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[6]);
	Delete(&tree, rand_integer[5]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------");
	puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[7]);
	Delete(&tree, rand_integer[5]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------");
	puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[9]);
	Delete(&tree, rand_integer[5]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------"); puts("---------------------------------------");
	printf("삭제될 숫자: %d\n", rand_integer[8]);
	Delete(&tree, rand_integer[5]);
	new_line_idx = 2;
	cnt = 0;
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
	puts("---------------------------------------");
#endif

}