#include"ALL.h"
extern Stack *top;

void Insert(int **tree, int item)
{
	int start_idx = 1;
	int compare_idx = start_idx;
	int size_check = _msize(*tree) / sizeof(int);

	if ((*tree)[start_idx] == 0)
		(*tree)[start_idx] = item;

	else
	{
		//idx는 갯수보다 하나 작음
		while (1)
		{
			if ((*tree)[compare_idx] == 0)
			{
				(*tree)[compare_idx] = item;
				break;
			}
			else
			{
				if ((*tree)[compare_idx] >= item)
				{
					compare_idx = compare_idx * 2;
					if (compare_idx >= size_check)
					{
						(*tree) = (int*)realloc((*tree), 2 * size_check * sizeof(int));
						memset((*tree) + size_check , 0, size_check * sizeof(int));
					}

				}
				else
				{
					compare_idx = (compare_idx * 2 + 1);
					if (compare_idx >= size_check)
					{
						(*tree) = (int*)realloc((*tree), 2 * size_check * sizeof(int));
						memset((*tree) + size_check, 0, size_check * sizeof(int));
					}
				}
			}

		}
	}
}

void Delete(int **tree, int item)
{
	int search_idx;
	int size_check = _msize(*tree) / sizeof(int);
	//스택이나 배열로 역순으로 다시 영으로 지운 칸을 채워줌

	for (search_idx = 0; search_idx < size_check; search_idx++)
	{
		if ((*tree)[search_idx] == item)
		{
			(*tree)[search_idx] = 0;
			break;
		}
	}

	while (1)
	{
		search_idx = search_idx * 2 + 1;//큰쪽
		if (search_idx >= size_check)
		{
			search_idx = search_idx / 2;
			break;
		}
			
		if ((*tree)[search_idx] != 0)//노드에 숫자가 있으면
		{
			Push_stack((*tree)[search_idx]);
			(*tree)[search_idx] = 0;
		}
		else//노드에 숫자가 없으면
		{
			search_idx = search_idx - 1;//작은쪽
			if ((*tree)[search_idx] != 0)
			{
				Push_stack((*tree)[search_idx]);
				(*tree)[search_idx] = 0;
			}
			else
			{
				break;
			}
		}
	}

	while (IsEmpty() != TRUE)
	{
		search_idx = search_idx / 2;
		(*tree)[search_idx] = Pop_stack();
	}
	Delete_Level_New_Ver(tree);
}


void Delete_Level(int **tree)
{
	int size_check = _msize(*tree) / sizeof(int);

	int max_level;
	int search_idx;
	int search_idx_start;
	int search_idx_end;
	int *free_mem;
	int free_flag = TRUE;

	max_level = (int)LogB(2.0, size_check);
	search_idx_start = (int)pow(2.0, max_level - 1);
	search_idx_end = (int)pow(2.0, max_level)-1;
	free_mem = (*tree) + search_idx_start;

	for (search_idx = search_idx_start; search_idx < search_idx_end; search_idx++)
	{
		if ((*tree)[search_idx] != 0)
			free_flag = FALSE;
	}

	if (free_flag == TRUE)
		free(free_mem);
}

void Delete_Level_New_Ver(int **tree)
{
	int size_check = _msize(*tree) / sizeof(int);
	int re_size = size_check / 2;
	int max_level;
	int search_idx;
	int search_idx_start;
	int search_idx_end;
	int *free_mem;
	int free_flag = TRUE;

	max_level = (int)LogB(2.0, size_check);
	search_idx_start = (int)pow(2.0, max_level - 1);
	search_idx_end = (int)pow(2.0, max_level) - 1;
	free_mem = (*tree) + search_idx_start;

	for (search_idx = search_idx_start; search_idx < search_idx_end; search_idx++)
	{
		if ((*tree)[search_idx] != 0)
			free_flag = FALSE;
	}

	if (free_flag == TRUE)
		(*tree) = (int*)realloc((*tree), re_size * sizeof(int));
}

void Print_Tree(int *tree)
{
	int idx;
	int num_of_ary;
	int new_line_idx = 2;
	int cnt = 1;
	num_of_ary = _msize(tree) / sizeof(int);

	puts("---------------------------------------");
	for (idx = 0; idx < num_of_ary; idx++)
	{
		
		if (idx != 0)
		{
			printf("%2d ", tree[idx]);
			cnt++;
		}
		else
			printf("Level %2d: ", (int)LogB(2.0, (double)cnt)+1);

		if (cnt == new_line_idx)
		{
			puts("");
			if (idx != num_of_ary - 1)
				printf("Level %2d: ", (int)LogB(2.0, (double)cnt) + 1);
			new_line_idx = new_line_idx * 2;
		}
	}
	puts("---------------------------------------");
}


int *rand_num()
{
	int *rand_integer;
	int int_temp;
	int check_flag = TRUE;
	int idx, check_idx;

	rand_integer = (int*)calloc(TREE_MAX, sizeof(int));

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		while (1)
		{
			int_temp = rand() % RAND_INT_MAX + 1;
			for (check_idx = 0; check_idx < TREE_MAX; check_idx++)
			{
				if (int_temp == rand_integer[check_idx])
				{
					check_flag = FALSE;
					break;
				}
			}
			if (check_flag == TRUE)
				break;
		}
		rand_integer[idx] = int_temp;
	}

	return rand_integer;
}

int *rand_num_new_ver()
{
	char *rand_integer;
	int *selected_integer;
	int int_temp;
	int check_flag = TRUE;
	int idx, check_idx;

	rand_integer = (char*)calloc(RAND_INT_MAX + 1, sizeof(char));
	selected_integer = (int*)calloc(TREE_MAX, sizeof(int));

	for (idx = 0; idx < TREE_MAX; idx++)
	{
		while (1)
		{
			check_idx = rand() % RAND_INT_MAX + 1;
			if (rand_integer[check_idx] == 0)
			{
				rand_integer[check_idx] = 1;
				selected_integer[idx] = check_idx;
				break;
			}
		}
	}
	free(rand_integer);

	return selected_integer;
}


/*SIMPLE_MATH*/
double LogB(double base, double x)
{
	return log(x) / log(base);
}



#ifdef NOTYET

(*tree)[search_idx] = 0;
search_idx = search_idx * 2 + 1;
if ((*tree)[search_idx] != 0)
{
	(*tree)[search_idx / 2] = (*tree)[search_idx];
	(*tree)[search_idx] = 0;
}
else
{
	search_idx = search_idx * 2;
	if ((*tree)[search_idx] != 0)
	{

	}
}

break;
#endif



