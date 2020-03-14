#include"ALL.h"

void Insert(int **tree, int item)
{
	int start_idx = 1;
	int compare_idx = start_idx;
	int size_check = _msize(*tree) / sizeof(int);

	if ((*tree)[start_idx] == 0)
		(*tree)[start_idx] = item;

	else
	{
		//idx�� �������� �ϳ� ����
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
	

	for (search_idx = 0; search_idx < size_check; search_idx++)
	{
		if ((*tree)[search_idx] == item)
		{
			(*tree)[search_idx] = 0;//���� ��� ����
			while (1)
			{
				//�ε����� �޸� ������ ������� Ȯ�ε� �ʿ��� ��
				//������ break point�� ���� 
				search_idx = search_idx * 2 + 1;//ū��
				if ((*tree)[search_idx] != 0)//��忡 ���ڰ� ������
				{
					Push_stack((*tree)[search_idx]);
					(*tree)[search_idx] = 0;
				}
				else//��忡 ���ڰ� ������
				{
					search_idx = search_idx - 1;//������
					if ((*tree)[search_idx] != 0)
					{
						Push_stack((*tree)[search_idx]);
						(*tree)[search_idx] = 0;
					}
					else
					{
						//������ break point�� ���� �����غ��� �ҵ�
					}
					
				}

				if (search_idx >= size_check)
					break;
			}
			
		}
	}
	
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


