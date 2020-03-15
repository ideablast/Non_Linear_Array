#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

void Insert(int **tree, int item);
int *rand_num();
int *rand_num_new_ver();
void Delete(int **tree, int item);
void Delete_Level(int **tree);
void Delete_Level_New_Ver(int **tree);
void Print_Tree(int **tree);

/*STACK_FUNCTION*/
Stack* Add_new_stack();
void Push_stack(int item);
int Pop_stack();
int IsEmpty();
int Count_stack();

/*SIMPLE_MATH*/
double LogB(double base, double x);

#endif

