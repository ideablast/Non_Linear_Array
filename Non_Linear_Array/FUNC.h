#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

void Insert(int **tree, int item);
int *rand_num();
int *rand_num_new_ver();

/*STACK_FUNCTION*/
Stack* Add_new_stack();
void Push_stack(int item);
int Pop_stack();
int IsEmpty();
int Count_stack();

#endif

